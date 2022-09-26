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

int motor_Front_left_speed = 50; 
int motor_Front_right_speed = 60;
int motor_Back_speed = 55; 

//motor driver pins 
//Front Left
#define motor_1a 1
#define motor_1b 2  
#define motor_1PWM 3
//Front Right
#define motor_2a A3
#define motor_2b A2
#define motor_2PWM 5
//Back
#define motor_3a 7
#define motor_3b 8
#define motor_3PWM 9

void setup() 
{
  Serial.begin(57600); 
   pinMode(motor_1a,OUTPUT);
   pinMode(motor_1b,OUTPUT);
   pinMode(motor_1PWM,OUTPUT);
   pinMode(motor_2a,OUTPUT);
   pinMode(motor_2b,OUTPUT);
   pinMode(motor_2PWM,OUTPUT);
   pinMode(motor_3a,OUTPUT);
   pinMode(motor_3b,OUTPUT);
   pinMode(motor_3PWM,OUTPUT);
  
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
  digitalWrite(motor_3PWM,0);
  digitalWrite(motor_1a,HIGH);
  digitalWrite(motor_1b,HIGH);
  digitalWrite(motor_2a,HIGH);
  digitalWrite(motor_2b,HIGH);
  digitalWrite(motor_3a,HIGH);
  digitalWrite(motor_3b,HIGH);

}

void loop() 
{
  ps2x.read_gamepad();
    if(ps2x.Button(PSB_L1))
    {
      analogWrite(motor_1PWM,(motor_Front_left_speed)/2);
      analogWrite(motor_2PWM,(motor_Front_right_speed)/2);
      analogWrite(motor_3PWM,motor_Back_speed/2);

      digitalWrite(motor_1a,HIGH);
      digitalWrite(motor_1b,LOW);      
      digitalWrite(motor_2a,HIGH);
      digitalWrite(motor_2b,LOW);
      digitalWrite(motor_3a,HIGH);
      digitalWrite(motor_3b,LOW);      
    }
    else if(ps2x.Button(PSB_R1))
    {
      analogWrite(motor_1PWM,(motor_Front_left_speed)/2);
      analogWrite(motor_2PWM,(motor_Front_right_speed)/2);
      analogWrite(motor_3PWM,motor_Back_speed/2);

      digitalWrite(motor_1a,LOW);
      digitalWrite(motor_1b,HIGH);
      digitalWrite(motor_2a,LOW);
      digitalWrite(motor_2b,HIGH);      
      digitalWrite(motor_3a,LOW);
      digitalWrite(motor_3b,HIGH);
      
    }
    else if(ps2x.Button(PSB_PAD_UP))
    {
      Serial.println("Moving Forward");
      analogWrite(motor_1PWM,motor_Front_left_speed);
      analogWrite(motor_2PWM,motor_Front_right_speed);
      
      digitalWrite(motor_1a,HIGH);
      digitalWrite(motor_1b,LOW);
      digitalWrite(motor_2a,LOW);
      digitalWrite(motor_2b,HIGH); 
      digitalWrite(motor_3a,LOW);
      digitalWrite(motor_3b,LOW);
    }
    else if(ps2x.Button(PSB_PAD_DOWN))
    {
      Serial.println("Moving Backward");
      analogWrite(motor_1PWM,motor_Front_left_speed);
      analogWrite(motor_2PWM,motor_Front_right_speed);
      
      digitalWrite(motor_1a,LOW);
      digitalWrite(motor_1b,HIGH);
      digitalWrite(motor_2a,HIGH);
      digitalWrite(motor_2b,LOW); 
      digitalWrite(motor_3a,LOW);
      digitalWrite(motor_3b,LOW);
    }
 else if(ps2x.Button(PSB_PAD_LEFT))
    {
      
      Serial.println("Moving Left");
      analogWrite(motor_1PWM,(motor_Front_left_speed)/2);
      analogWrite(motor_2PWM,(motor_Front_right_speed)/2);
      analogWrite(motor_3PWM,motor_Back_speed);
      
      digitalWrite(motor_1a,LOW);
      digitalWrite(motor_1b,HIGH);
      digitalWrite(motor_2a,LOW);
      digitalWrite(motor_2b,HIGH);      
      digitalWrite(motor_3a,HIGH);
      digitalWrite(motor_3b,LOW);
    }
     else if(ps2x.Button(PSB_PAD_LEFT))
    {
      
      Serial.println("Moving Left");
      analogWrite(motor_1PWM,(motor_Front_left_speed)/2);
      analogWrite(motor_2PWM,(motor_Front_right_speed)/2);
      analogWrite(motor_3PWM,motor_Back_speed);
      
      digitalWrite(motor_1a,LOW);
      digitalWrite(motor_1b,HIGH);
      digitalWrite(motor_2a,LOW);
      digitalWrite(motor_2b,HIGH);      
      digitalWrite(motor_3a,HIGH);
      digitalWrite(motor_3b,LOW);
    }
     else if(ps2x.Button(PSB_PAD_RIGHT))
    {
      
      Serial.println("Moving Right");
      analogWrite(motor_1PWM,(motor_Front_left_speed)/2);
      analogWrite(motor_2PWM,(motor_Front_right_speed)/2);
      analogWrite(motor_3PWM,motor_Back_speed);
      
      digitalWrite(motor_1a,HIGH);
      digitalWrite(motor_1b,LOW);
      digitalWrite(motor_2a,HIGH);
      digitalWrite(motor_2b,LOW);      
      digitalWrite(motor_3a,LOW);
      digitalWrite(motor_3b,HIGH);
    }
    else
    {
     digitalWrite(motor_1a,HIGH);
     digitalWrite(motor_1b,HIGH);
     digitalWrite(motor_2a,HIGH);
     digitalWrite(motor_2b,HIGH);
     digitalWrite(motor_3a,HIGH);
     digitalWrite(motor_3b,HIGH);
    }
    delay(50);
}
