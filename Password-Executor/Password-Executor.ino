#include <Keyboard.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 32 // OLED display height, in pixels

#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C ///< See datasheet for Address; 0x3D for 128x64, 0x3C for 128x32
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

    //display.clearDisplay() – all pixels are off
    //display.drawPixel(x,y, color) – plot a pixel in the x,y coordinates
    //display.setTextSize(n) – set the font size, supports sizes from 1 to 8
    //display.setCursor(x,y) – set the coordinates to start writing text
    //display.print(“message”) – print the characters at location x,y
    //display.display() – call this method for the changes to make effect 
    
String PASSWORD = "RANDOMPASSWORD";
const int pin = 9;
int count = 0;
int state = 0;
int last = 0;
int skip = 0;


void setup()
{
  Serial.begin(115200);
  pinMode(pin, INPUT);  // Set the button as an input
  digitalWrite(pin, HIGH);  // Pull the button high

  Keyboard.begin(); //Init keyboard emulation
}

void loop(){
state = digitalRead(pin);
  if (state != last){
    if (state == LOW){
    count++;
    }
    delay(1000);
  }
  last = state;

  
  if (count == 1 && skip < 1) {
   Serial.println("DO NOTHING 1");
  }

  if (count == 2 && skip < 2) {
  Serial.println("DO NOTHING 2");
  }

  if (count == 3 && skip < 3) {
   Serial.println("Print Passwording");
   display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 10);
   // Display static text
    display.println("Print Password");
    display.display(); 
    Keyboard.print(PASSWORD);  // send a 'z' to the computer via Keyboard HID
    delay(10000);  // delay so there aren't a kajillion z's
  
  }
  if (count == 6 && skip < 6) {
   Serial.println("Display Creator");
   display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0, 10);
   // Display static text
    display.println("Hello, world!");
    display.display(); 
    Keyboard.print(PASSWORD);  // send a 'z' to the computer via Keyboard HID
    delay(1000);  // delay so there aren't a kajillion z's 
  }
}
