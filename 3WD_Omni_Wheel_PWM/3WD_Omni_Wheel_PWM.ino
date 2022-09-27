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

int pss_val_high_high = 255;
int pss_val_high_low = 170;
int pss_val_low_high = 85;
int pss_val_low_low = 0;

int motor_Front_left_speed = 0; 
int motor_Front_right_speed = 0;
int motor_Back_speed = 0; 

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
