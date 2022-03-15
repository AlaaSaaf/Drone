/* For more info go to www.calpardo.com  */
#include <Servo.h>

int PWM_ROLL = 13; //Define Digital PIN
int PWM_PITCH = 12; //Define Digital PIN
int PWM_THROTTLE = 11; //Define Digital PIN
int PWM_YAW = 7; //Define Digital PIN
int PWM_SWA = 4; //Define Digital PIN
int PWM_VRA = 8; //Define Digital PIN

Servo ESC1;     // create servo object to control the ESC
Servo ESC2;
Servo ESC3;
Servo ESC4;

void setup() {
  ESC1.attach(9,0,1000);
  ESC2.attach(10,0,1000);//**
  ESC3.attach(5,0,1000);//**
  ESC4.attach(6,0,1000);
  pinMode(PWM_ROLL, INPUT);
  pinMode(PWM_PITCH, INPUT);
  pinMode(PWM_THROTTLE, INPUT);
  pinMode(PWM_YAW, INPUT);
  pinMode(PWM_SWA, INPUT);
  pinMode(PWM_VRA, INPUT);
  Serial.begin(115200);
}

void loop() {
  int roll = pulseIn(PWM_ROLL, HIGH); //Read PWM Pulse
  int pitch = pulseIn(PWM_PITCH, HIGH); //Read PWM Pulse
  int throttle = pulseIn(PWM_THROTTLE, HIGH); //Read PWM Pulse
  int yaw = pulseIn(PWM_YAW, HIGH); //Read PWM Pulse
  int swA = pulseIn(PWM_SWA, HIGH); //Read PWM Pulse
  int vrA = pulseIn(PWM_VRA, HIGH); //Read PWM Pulse
  
  Serial.print(" PWM CH1 Roll: ");
  Serial.print(roll-1500);
  Serial.print(" PWM CH2 Pitch: ");
  Serial.print(pitch-1500);
  Serial.print(" PWM CH3 Throttle: ");
  Serial.println(throttle-1014);
  Serial.print(" PWM CH1 Yaw: ");
  Serial.print(yaw-1495);
  //Serial.print(" PWM CH2 swA: ");
  //Serial.print(swA-995);
  //Serial.print(" PWM CH3 vrA: ");
  //Serial.println(vrA-995);
  if(throttle-1014 >0)
  {
    ESC1.write(throttle-1014);
    ESC2.write(throttle-1014);
    ESC3.write(throttle-1014);
    ESC4.write(throttle-1014); 
    if(throttle-1014 >600)
    {
      ESC1.write(throttle-1014+pitch-1500);
      ESC2.write(throttle-1014+pitch-1500);
      ESC3.write(throttle-1014+pitch-1500);
      ESC4.write(throttle-1014+pitch-1500);
    }
  }

}
