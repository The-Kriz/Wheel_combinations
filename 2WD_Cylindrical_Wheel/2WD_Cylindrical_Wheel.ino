#include <PS2X_lib.h>

//PS2 pins
PS2X ps2x; 
#define  ps2_clock 52
#define  ps2_command 51
#define  ps2_attention 53
#define  ps2_data 50
#define  ps2_Pressures true
#define  ps2_Rumble true
int error = 0; 
byte type = 0;
byte vibrate = 0;

int pss_val_high_high = 255;
int pss_val_high_low = 170;
int pss_val_low_high = 85;
int pss_val_low_low = 0;

int motor_speed = 80;

//motor driver(x2) pins 
//Left
#define motor_1a 0
#define motor_1b 1  
#define motor_1PWM 2
//Right
#define motor_2a 3
#define motor_2b 4
#define motor_2PWM 5



void setup() 
{
  Serial.begin(57600); 
   pinMode(motor_1a,OUTPUT);
   pinMode(motor_1b,OUTPUT);
   pinMode(motor_1PWM,OUTPUT);
   pinMode(motor_2a,OUTPUT);
   pinMode(motor_2b,OUTPUT);
   pinMode(motor_2PWM,OUTPUT);

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
      
  digitalWrite(motor_1PWM,0);
  digitalWrite(motor_2PWM,0);
  digitalWrite(motor_1a,HIGH);
  digitalWrite(motor_1b,HIGH);
  digitalWrite(motor_2a,HIGH);
  digitalWrite(motor_2b,HIGH);

}
