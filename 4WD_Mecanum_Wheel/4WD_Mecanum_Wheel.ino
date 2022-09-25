#include <PS2X_lib.h>


//PS2 pins
PS2X ps2x; 
#define  ps2_clock 13
#define  ps2_command 11
#define  ps2_attention 10
#define  ps2_data 12
#define  ps2_Pressures true
#define  ps2_Rumble true

int error = 0; 
byte type = 0;
byte vibrate = 0;

//motor driver(x2) pins 

//Front Left
#define motor_1a 1
#define motor_1b 2   
#define motor_1PWM 3 

//Front Right
#define motor_2a 7
#define motor_2b 6
#define motor_2PWM 5

//Back Left
#define motor_3a 8
#define motor_3b 9
#define motor_3PWM 10

//Back Right
#define motor_4a 13
#define motor_4b 12
#define motor_4PWM 11


void setup() 
{
  error = ps2x.config_gamepad(ps2_clock,ps2_command,ps2_attention,ps2_data,ps2_Pressures,ps2_Rumble);
  if(error == 0)
  {
    Serial.println("Found Controller, configured successful");
    Serial.println("Try out all the buttons, X will vibrate the controller, faster as you press harder;");
    Serial.println("holding L1 or R1 will print out the analog stick values.");
  }
   else if(error == 1)
    Serial.println("No controller found");
   else if(error == 2)
    Serial.println("Controller found but not accepting commands");
   else if(error == 3)
    Serial.println("Controller refusing to enter Pressures mode, may not support it. ");
    type = ps2x.readType(); 
      switch(type) 
      {
        case 0:
         Serial.println("Unknown Controller type");
        break;
        case 1:
         Serial.println("DualShock Controller Found");
        break;
        case 2:
          Serial.println("GuitarHero Controller Found");
        break;
      }
}

void loop() {
  // put your main code here, to run repeatedly:


//Forward
digitalWrite(motor_1a,HIGH);
digitalWrite(motor_1b,LOW);
digitalWrite(motor_2a,LOW);
digitalWrite(motor_2b,HIGH);
digitalWrite(motor_3a,HIGH);
digitalWrite(motor_3b,LOW);
digitalWrite(motor_4a,LOW);
digitalWrite(motor_4b,HIGH);

//Backward
digitalWrite(motor_1a,LOW);
digitalWrite(motor_1b,HIGH);
digitalWrite(motor_2a,HIGH);
digitalWrite(motor_2b,LOW);
digitalWrite(motor_3a,LOW);
digitalWrite(motor_3b,HIGH);
digitalWrite(motor_4a,HIGH);
digitalWrite(motor_4b,LOW);

//Left
digitalWrite(motor_1a,LOW);
digitalWrite(motor_1b,HIGH);
digitalWrite(motor_2a,LOW);
digitalWrite(motor_2b,HIGH);
digitalWrite(motor_3a,HIGH);
digitalWrite(motor_3b,LOW);
digitalWrite(motor_4a,HIGH);
digitalWrite(motor_4b,LOW);

//Right
digitalWrite(motor_1a,HIGH);
digitalWrite(motor_1b,LOW);
digitalWrite(motor_2a,HIGH);
digitalWrite(motor_2b,LOW);
digitalWrite(motor_3a,LOW);
digitalWrite(motor_3b,HIGH);
digitalWrite(motor_4a,LOW);
digitalWrite(motor_4b,HIGH);

//Forward Left
digitalWrite(motor_1a,HIGH);
digitalWrite(motor_1b,HIGH);
digitalWrite(motor_2a,LOW);
digitalWrite(motor_2b,HIGH);
digitalWrite(motor_3a,HIGH);
digitalWrite(motor_3b,LOW);
digitalWrite(motor_4a,HIGH);
digitalWrite(motor_4b,HIGH);
 
//Forward Right
digitalWrite(motor_1a,HIGH);
digitalWrite(motor_1b,LOW);
digitalWrite(motor_2a,HIGH);
digitalWrite(motor_2b,HIGH);
digitalWrite(motor_3a,HIGH);
digitalWrite(motor_3b,HIGH);
digitalWrite(motor_4a,LOW);
digitalWrite(motor_4b,HIGH);

//Backward Left
digitalWrite(motor_1a,LOW);
digitalWrite(motor_1b,HIGH);
digitalWrite(motor_2a,HIGH);
digitalWrite(motor_2b,HIGH);
digitalWrite(motor_3a,HIGH);
digitalWrite(motor_3b,HIGH);
digitalWrite(motor_4a,HIGH);
digitalWrite(motor_4b,LOW);
 
//Backward Right
digitalWrite(motor_1a,HIGH);
digitalWrite(motor_1b,HIGH);
digitalWrite(motor_2a,HIGH);
digitalWrite(motor_2b,LOW);
digitalWrite(motor_3a,LOW);
digitalWrite(motor_3b,HIGH);
digitalWrite(motor_4a,HIGH);
digitalWrite(motor_4b,HIGH);

//Rotate Left
digitalWrite(motor_1a,LOW);
digitalWrite(motor_1b,HIGH);
digitalWrite(motor_2a,LOW);
digitalWrite(motor_2b,HIGH);
digitalWrite(motor_3a,HIGH);
digitalWrite(motor_3b,LOW);
digitalWrite(motor_4a,LOW);
digitalWrite(motor_4b,HIGH);

//Rotate Right
digitalWrite(motor_1a,HIGH);
digitalWrite(motor_1b,LOW);
digitalWrite(motor_2a,HIGH);
digitalWrite(motor_2b,LOW);
digitalWrite(motor_3a,LOW);
digitalWrite(motor_3b,HIGH);
digitalWrite(motor_4a,HIGH);
digitalWrite(motor_4b,LOW);





}
