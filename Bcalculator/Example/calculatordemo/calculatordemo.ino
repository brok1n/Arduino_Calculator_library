#include "bcalculator.h"

Bcalculator bcircle;
char str[] = "-18+69.036-24.89+3*12.1568=";

void setup() {
  Serial.begin(115200);
  char ch = 0;
  int index = 0;
  while ( (ch = str[index++]) != '\0')
  {
      bcircle.pressed(ch);
  }
  double result = bcircle.count();
  Serial.println( result);  
}

void loop() {
  // put your main code here, to run repeatedly:

}
