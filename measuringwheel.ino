#include <LiquidCrystal.h>

LiquidCrystal lcd(5, 6, 7, 8, 9, 10);

int pin1 = 2;
int pin2 = 3;

int Pos = 0; 
int State;
int LastState;  

const float pi = 3.14;

const float R = 3.25;
const int N = 40;

float distance = 0;

void setup() { 
  pinMode (pin1 ,INPUT_PULLUP);
  pinMode (pin2 ,INPUT_PULLUP);

  lcd.begin(16, 2);
  lcd.print("MEASURNING WHEEL");
  
  LastState = digitalRead(pin1);    
} 

void loop() { 
  State = digitalRead(pin1);
   if (State != LastState){     
     if (digitalRead(pin2) != State) { 
       Pos ++;
     } 
     
     else {
       Pos --;
     }
   } 

  distance = ((2*pi*R)/N) * Pos ;

  lcd.setCursor(0, 1);
  lcd.print( distance);

  lcd.setCursor(5, 1);
  lcd.print("cm  ");
   
  LastState = State;
 }