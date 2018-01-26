#include "DualMC33926MotorShield.h"

DualMC33926MotorShield md;

// set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  // initialize the pushbutton pin as an input:
  pinMode(buttonPin, INPUT);   

  Serial.begin(115200);
  Serial.println("Dual MC33926 Motor Shield");
  md.init();

}

void stopIfFault()
{
  if (md.getFault())
  {
    Serial.println("fault");
    while(1);
  }
}

void loop()
{
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {     
    md.setM2Speed(-400);
    md.setM1Speed(250);
    stopIfFault();
    delay(1600);
    md.setM1Speed(00);
    md.setM2Speed(00);
    delay(4200);
    md.setM2Speed(-400);
    md.setM1Speed(250);
    delay(76000);
    md.setM2Speed(-350);
    md.setM1Speed(225);
    delay(1000);
    md.setM2Speed(-300);
    md.setM1Speed(200);
    delay(1000);
    md.setM1Speed(00);
    md.setM2Speed(00);
    delay(60000);
  } 
  else {
    md.setM1Speed(00);
    md.setM2Speed(00);
    stopIfFault();
  }

}




