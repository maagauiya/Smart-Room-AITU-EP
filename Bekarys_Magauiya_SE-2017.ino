//by:Bekarys Magauiya SE-2017 
#include "Adafruit_NeoPixel.h"  //library for LED strip
#include "IRremote.h"  //library for IR Remote 
#include "LiquidCrystal.h" 
int sensorPin = A1; //pin of TMP36 
LiquidCrystal lcd(0, 1, 8, 9, 10, 11); //pins for the LCD
int PIN = 6;  //Initialization  of pins this 6 for led strip    
int lnum = 4;   //lnum means number of leds
int pir = 2;  //pir means IR motion sensor
int ir = 3; //pin of IR sensor
int spir = LOW;  //to start with no active        
IRrecv irrecv(ir);//Initialization of IR sensor
decode_results results;
 Adafruit_NeoPixel strip = Adafruit_NeoPixel(lnum, PIN, NEO_GRB + NEO_KHZ800);//Initialization of strip,1 argument is number of leds,2nd pin of strip,3rd kHz of strip in this library support 800 and 400 kHz
void setup() { 
  lcd.begin(16,2); //to set size of LCD
  pinMode(pir, INPUT); //receive signals  
  strip.begin(); 
  strip.setBrightness(255);//to set brightness    
  strip.clear(); //to clear                       
  strip.show();// Initialize all pixels to 'off' 
    irrecv.enableIRIn(); //to receiving from sensor 
   lcd.print("Hello Mr.Bekarys"); //this part of code was done just for design
  delay(500);  
   lcd.clear();
  lcd.print("3..."); 
  delay(500); 
   lcd.clear();
  lcd.print("2...");   
  delay(500); 
   lcd.clear();
  lcd.print("1...");   
  delay(500); 
   lcd.clear(); 
  
}
 
void loop(){  
  int reading = analogRead(sensorPin); //read data from TMP36
  float temperatureC = (((reading * 5.0)/1024)-0.5)*100;//by this formula its so long to write but you can read in documentation 
  if(temperatureC<15){  
     lcd.print(temperatureC);
    lcd.print("   suyk");  
  
  }else{  
     lcd.print(temperatureC);
     lcd.print("   zhyly"); 

  }
 
  lcd.setCursor(0, 0);// set the cursor to column 0, line1
  delay(1000);
 lcd.clear();
  if (digitalRead(pir) == HIGH) { //if motion detected          
    for (int i = 0; i < lnum; i++ ) { //program turn on the led in default color (default colour is-yellow)  
    strip.setPixelColor(i, 0xEDF792); //   0xEDF792 hex code of yellow 
    strip.show();                         
    delay(1);
  } 
  }
    if (irrecv.decode(&results)) { 
    switch (results.value) {
      case 16582903: 
        for (int i = 0; i < lnum; i++ ) {   
    strip.setPixelColor(i, 0xFF0000);   
    strip.show();                        
    delay(1);
  }  
      if(results.value!=16582903){ 
         strip.clear();                         
     strip.show();  
        
      }
      break;
      
      case 16615543:
  
      for (int i = 0; i < lnum; i++ ) {  
    strip.setPixelColor(i, 0x00FF06);     
    strip.show();                         
    delay(1);
  }  
       if(results.value!=16615543){ 
         strip.clear();                        
     strip.show();  
        
      }
        break;
      
      case 16599223:
        for (int i = 0; i < lnum; i++ ) {  
    strip.setPixelColor(i, 0x285EFE);    
    strip.show();                         
    delay(1);
  }  
       if(results.value!=16599223){ 
         strip.clear();   
         
      }
      break; 
     
     case 16580863:{  //if turn of button will pressed then program will be turn of the LED strip
        strip.clear(); 
     strip.show();  
      } }
     }
      
    irrecv.resume(); //to receive signals
  } 
} 
