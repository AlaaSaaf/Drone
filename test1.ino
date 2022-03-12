
#include <Servo.h>

Servo ESC1;     // create servo object to control the ESC
Servo ESC2;
Servo ESC3;
Servo ESC4;

int potValue1;  // value from the analog pin
float potValue2;
//int potValue2;
void setup() {
  Serial.begin(9600);
  // Attach the ESC on pin 9
  ESC1.attach(9,1000,2000);
  ESC2.attach(10,1000,2000);//**
  ESC3.attach(5,1000,2000);//**
  ESC4.attach(6,1000,2000);
  //ESC2.attach(10,1000,2000);// (pin, min pulse width, max pulse width in microseconds) 
}
void loop() {
  potValue1 = analogRead(A0); 
  
  //potValue2 = analogRead(A1); // reads the value of the potentiometer (value between 0 and 1023)
  potValue1 = map(potValue1, 0, 1023, 0, 180);
  //potValue2 = map(potValue2, 0, 1023, 0, 180);// scale it to use it with the servo library (value between 0 and 180)
  float potValue2 = potValue1*0.7 ; 
  ESC1.write(potValue1);
  ESC2.write(potValue1);
  ESC3.write(potValue1);
  ESC4.write(potValue1); 
  //ESC2.write(potValue1); // Send the signal to the ESC
  Serial.print("DU1: ");
  Serial.println(potValue1);
  //Serial.print("DU2: ");
  //Serial.println(potValue1);
}
