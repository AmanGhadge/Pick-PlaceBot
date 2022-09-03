#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void setup() {
  Serial.begin(9600); // set up Serial library at 9600 bps
  Serial.println("Robojax L293D Example");
}

void loop() {

  motor1.setSpeed( speed(50) ); //set speed for motor 1 at 50%
  motor1.run(FORWARD);//send motor 1 to Foarward rotation

  delay(2000);//wait for 2 seconds
  motor2.setSpeed( speed(100) );//set speed for motor 2 at 100%
  motor2.run(BACKWARD);//send motor 2 to Foarward rotation

  delay(2000);
  motor3.setSpeed( speed(70) );
  motor3.run(FORWARD);
  
  delay(2000);
  motor4.setSpeed( speed(90) );
  motor4.run(FORWARD);

    
  delay(2000);
  
  motor1.run(BRAKE);
  motor2.run(RELEASE);  
  motor3.run(RELEASE);
  motor4.run(RELEASE);   
  delay(2000);

  
  motor1.setSpeed(speed(100));
  motor1.run(BACKWARD);
  delay(2000);
  
  motor1.run(RELEASE);

  delay(1000);
}

/*
 * speed percent to speed converter
 * receives value between 0 to 100 and converts it to value between
 * 0 to 255 which are 8 bits Arduino PWM value
 * www.Robojax.com
 Watch full video instruction:  https://youtu.be/0XihwdulmDQ
 */
int  speed(int percent)
{
  return map(percent, 0, 100, 0, 255);
}