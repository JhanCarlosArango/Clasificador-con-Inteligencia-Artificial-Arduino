#include <Servo.h>
#ifndef Servo_motor_h
#define Servo_motor_h
Servo servoMotor;

class Servo_motor {

public:
  void run() {
    Serial.begin(9600);
    servoMotor.attach(39, 750, 1800);  // pin 9
    servoMotor.write(90);              //angulo
  }
  void movimieto_a() {

    servoMotor.write(0);
    delay(1000);
    servoMotor.write(90);
  }
  void movimieto_b() {
    servoMotor.write(170);
    delay(1000);
    servoMotor.write(90);
  }
};
#endif