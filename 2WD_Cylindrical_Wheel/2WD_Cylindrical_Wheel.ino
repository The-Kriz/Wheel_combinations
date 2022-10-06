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


