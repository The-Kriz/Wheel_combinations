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
int motor_Front_left_speed = 0; 
int motor_Front_right_speed = 0;
int motor_Back_left_speed = 0; 
int motor_Back_right_speed = 0;


//motor driver(x2) pins 
//Front Left
#define motor_1a 0
#define motor_1b 1  
#define motor_1PWM 2
//Front Right
#define motor_2a 3
#define motor_2b 4
#define motor_2PWM 5
//Back Left
#define motor_3a 6
#define motor_3b 7
#define motor_3PWM 8
//Back Right
#define motor_4a 9
#define motor_4b 10
#define motor_4PWM 11


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
   pinMode(motor_4a,OUTPUT);
   pinMode(motor_4b,OUTPUT);
   pinMode(motor_4PWM,OUTPUT);
  
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
  digitalWrite(motor_4PWM,0);
}

void loop() 
{
  int lJoyY = ps2x.Analog(PSS_LY);
  int lJoyX = ps2x.Analog(PSS_LX);

  if (ps2x.Button(PSB_L1))
  {
    //Rotate Left
    digitalWrite(motor_1a,LOW);
    digitalWrite(motor_1b,HIGH);
    digitalWrite(motor_2a,LOW);
    digitalWrite(motor_2b,HIGH);
    digitalWrite(motor_3a,HIGH);
    digitalWrite(motor_3b,LOW);
    digitalWrite(motor_4a,LOW);
    digitalWrite(motor_4b,HIGH);
    
//    digitalWrite(motor_1PWM,0);
//    digitalWrite(motor_2PWM,0);
//    digitalWrite(motor_3PWM,0);
//    digitalWrite(motor_4PWM,0);
  }
  
  else if (ps2x.Button(PSB_R1)) 
  {   
    //Rotate Right
    digitalWrite(motor_1a,HIGH);
    digitalWrite(motor_1b,LOW);
    digitalWrite(motor_2a,HIGH);
    digitalWrite(motor_2b,LOW);
    digitalWrite(motor_3a,LOW);
    digitalWrite(motor_3b,HIGH);
    digitalWrite(motor_4a,HIGH);
    digitalWrite(motor_4b,LOW);
    
//    digitalWrite(motor_1PWM,0);
//    digitalWrite(motor_2PWM,0);
//    digitalWrite(motor_3PWM,0);
//    digitalWrite(motor_4PWM,0);
  }

  else if( lJoyY >50 and lJoyX > 50 )
  {
    //Forward Right
    digitalWrite(motor_1a,HIGH);
    digitalWrite(motor_1b,LOW);
    digitalWrite(motor_2a,HIGH);
    digitalWrite(motor_2b,HIGH);
    digitalWrite(motor_3a,HIGH);
    digitalWrite(motor_3b,HIGH);
    digitalWrite(motor_4a,LOW);
    digitalWrite(motor_4b,HIGH);
    
//    digitalWrite(motor_1PWM,0);
//    digitalWrite(motor_2PWM,0);
//    digitalWrite(motor_3PWM,0);
//    digitalWrite(motor_4PWM,0);
  }

  else if( lJoyY < 50 and lJoyX < 50 )
  {
    //Backward Left
    digitalWrite(motor_1a,LOW);
    digitalWrite(motor_1b,HIGH);
    digitalWrite(motor_2a,HIGH);
    digitalWrite(motor_2b,HIGH);
    digitalWrite(motor_3a,HIGH);
    digitalWrite(motor_3b,HIGH);
    digitalWrite(motor_4a,HIGH);
    digitalWrite(motor_4b,LOW);
    
//    digitalWrite(motor_1PWM,0);
//    digitalWrite(motor_2PWM,0);
//    digitalWrite(motor_3PWM,0);
//    digitalWrite(motor_4PWM,0);
  }
  
  else if( lJoyY > 50 and lJoyX < 50 )
  {
    //Forward Left
    digitalWrite(motor_1a,HIGH);
    digitalWrite(motor_1b,HIGH);
    digitalWrite(motor_2a,LOW);
    digitalWrite(motor_2b,HIGH);
    digitalWrite(motor_3a,HIGH);
    digitalWrite(motor_3b,LOW);
    digitalWrite(motor_4a,HIGH);
    digitalWrite(motor_4b,HIGH);
    
//    digitalWrite(motor_1PWM,0);
//    digitalWrite(motor_2PWM,0);
//    digitalWrite(motor_3PWM,0);
//    digitalWrite(motor_4PWM,0);
  }

  else if( lJoyY < 50 and lJoyX > 50 )
  {
    //Backward Right
    digitalWrite(motor_1a,HIGH);
    digitalWrite(motor_1b,HIGH);
    digitalWrite(motor_2a,HIGH);
    digitalWrite(motor_2b,LOW);
    digitalWrite(motor_3a,LOW);
    digitalWrite(motor_3b,HIGH);
    digitalWrite(motor_4a,HIGH);
    digitalWrite(motor_4b,HIGH);
    
//    digitalWrite(motor_1PWM,0);
//    digitalWrite(motor_2PWM,0);
//    digitalWrite(motor_3PWM,0);
//    digitalWrite(motor_4PWM,0);
  }

  else if( lJoyY > 50 )
  {  
    //Forward
    digitalWrite(motor_1a,HIGH);
    digitalWrite(motor_1b,LOW);
    digitalWrite(motor_2a,LOW);
    digitalWrite(motor_2b,HIGH);
    digitalWrite(motor_3a,HIGH);
    digitalWrite(motor_3b,LOW);
    digitalWrite(motor_4a,LOW);
    digitalWrite(motor_4b,HIGH);
    
//    digitalWrite(motor_1PWM,0);
//    digitalWrite(motor_2PWM,0);
//    digitalWrite(motor_3PWM,0);
//    digitalWrite(motor_4PWM,0);
  }

  else if( lJoyY < 50)
  {
    //Backward
    digitalWrite(motor_1a,LOW);
    digitalWrite(motor_1b,HIGH);
    digitalWrite(motor_2a,HIGH);
    digitalWrite(motor_2b,LOW);
    digitalWrite(motor_3a,LOW);
    digitalWrite(motor_3b,HIGH);
    digitalWrite(motor_4a,HIGH);
    digitalWrite(motor_4b,LOW);
    
//    digitalWrite(motor_1PWM,0);
//    digitalWrite(motor_2PWM,0);
//    digitalWrite(motor_3PWM,0);
//    digitalWrite(motor_4PWM,0);
  }
  else if( lJoyX < 50 )
  {    
    //Left
    digitalWrite(motor_1a,LOW);
    digitalWrite(motor_1b,HIGH);
    digitalWrite(motor_2a,LOW);
    digitalWrite(motor_2b,HIGH);
    digitalWrite(motor_3a,HIGH);
    digitalWrite(motor_3b,LOW);
    digitalWrite(motor_4a,HIGH);
    digitalWrite(motor_4b,LOW);
    
//    digitalWrite(motor_1PWM,0);
//    digitalWrite(motor_2PWM,0);
//    digitalWrite(motor_3PWM,0);
//    digitalWrite(motor_4PWM,0);
  }
  
  else if( lJoyX > 50 )
  {    
    //Right
    digitalWrite(motor_1a,HIGH);
    digitalWrite(motor_1b,LOW);
    digitalWrite(motor_2a,HIGH);
    digitalWrite(motor_2b,LOW);
    digitalWrite(motor_3a,LOW);
    digitalWrite(motor_3b,HIGH);
    digitalWrite(motor_4a,LOW);
    digitalWrite(motor_4b,HIGH);
    
//    digitalWrite(motor_1PWM,0);
//    digitalWrite(motor_2PWM,0);
//    digitalWrite(motor_3PWM,0);
//    digitalWrite(motor_4PWM,0);
  }
  else
  {
    digitalWrite(motor_1a,LOW);
    digitalWrite(motor_1b,LOW);
    digitalWrite(motor_2a,LOW);
    digitalWrite(motor_2b,LOW);
    digitalWrite(motor_3a,LOW);
    digitalWrite(motor_3b,LOW);
    digitalWrite(motor_4a,LOW);
    digitalWrite(motor_4b,LOW);
    
    digitalWrite(motor_1PWM,0);
    digitalWrite(motor_2PWM,0);
    digitalWrite(motor_3PWM,0);
    digitalWrite(motor_4PWM,0);
  }
}
