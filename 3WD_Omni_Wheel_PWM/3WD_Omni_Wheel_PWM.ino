void loop() 
{
  ps2x.read_gamepad();
  int lJoyY = ps2x.Analog(PSS_LY);
  int lJoyX = ps2x.Analog(PSS_LX);
    if(ps2x.Button(PSB_L1))
    {
      
      analogWrite(motor_1PWM, 50);
      analogWrite(motor_2PWM, 50);
      analogWrite(motor_3PWM, 50);

      digitalWrite(motor_1a,HIGH);
      digitalWrite(motor_1b,LOW);      
      digitalWrite(motor_2a,HIGH);
      digitalWrite(motor_2b,LOW);
      digitalWrite(motor_3a,HIGH);
      digitalWrite(motor_3b,LOW);      
    }
    else if(ps2x.Button(PSB_R1))
    {
      analogWrite(motor_1PWM, 50);
      analogWrite(motor_2PWM, 50);
      analogWrite(motor_3PWM, 50);

      digitalWrite(motor_1a,LOW);
      digitalWrite(motor_1b,HIGH);
      digitalWrite(motor_2a,LOW);
      digitalWrite(motor_2b,HIGH);      
      digitalWrite(motor_3a,LOW);
      digitalWrite(motor_3b,HIGH);
      
    }
    else if ( lJoyY >= pss_val_high_low && lJoyY <= pss_val_high_high )
     {  
      //Forward
      Serial.println("Moving Forward");
      
      motor_Front_left_speed  = map( lJoyY,140 , 255, 0 , 255);
      motor_Front_right_speed = map( lJoyY,140 , 255, 0 , 255);
   
      analogWrite(motor_1PWM,motor_Front_left_speed);
      analogWrite(motor_2PWM,motor_Front_right_speed);
      
      digitalWrite(motor_1a,HIGH);
      digitalWrite(motor_1b,LOW);
      digitalWrite(motor_2a,LOW);
      digitalWrite(motor_2b,HIGH); 
      digitalWrite(motor_3a,LOW);
      digitalWrite(motor_3b,LOW);
    }
     else if( lJoyY >= pss_val_low_low && lJoyY <= pss_val_low_high ) 
    {
      //Backward
      Serial.println("Moving Backward");
      
      motor_Front_left_speed  = map( lJoyY, 120, 0, 0, 255);
      motor_Front_right_speed = map( lJoyY, 120, 0, 0, 255);
      
      analogWrite(motor_1PWM,motor_Front_left_speed);
      analogWrite(motor_2PWM,motor_Front_right_speed);
      
      digitalWrite(motor_1a,LOW);
      digitalWrite(motor_1b,HIGH);
      digitalWrite(motor_2a,HIGH);
      digitalWrite(motor_2b,LOW); 
      digitalWrite(motor_3a,LOW);
      digitalWrite(motor_3b,LOW);
    }
    else if( lJoyX >= pss_val_low_low && lJoyX <= pss_val_low_high )
    {    
      //Left
      Serial.println("Moving Left");
      
      motor_Front_left_speed  = map( lJoyX, 120, 0, 0, 255);
      motor_Front_right_speed = map( lJoyX, 120, 0, 0, 255);
      motor_Back_speed        = map( lJoyX, 120, 0, 0, 255);
   
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
    else if( lJoyX >=pss_val_high_low && lJoyX <= pss_val_high_high )
    {    
      //Right
      Serial.println("Moving Right");
      
      motor_Front_left_speed  = map( lJoyX, 140, 255, 0, 255);
      motor_Front_right_speed = map( lJoyX, 140, 255, 0, 255);
      motor_Back_speed        = map( lJoyX, 140, 255, 0, 255);
      
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
