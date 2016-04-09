#include <Boards.h>
#include <Firmata.h>

#include <Ultrasonic.h>
Ultrasonic ultrasonic(22,23);

#include <AFMotor.h>
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
int power=255;
char symbol;

void setup() {
  Serial.begin(9600);
  Serial3.begin(9600);
  Serial3.println("Enter symbol");
  Serial3.println("'0' - RELEASE");
  Serial3.println("'1' - FORWARD");
  Serial3.println("'2' - BACKWARD");
  Serial3.println("'3' - RIGHT");
  Serial3.println("'4' - LEFT");
  Serial3.setTimeout(5000);
}

void loop() {
  Serial.print(ultrasonic.Ranging(CM));
  Serial.println("cm");
  int length = ultrasonic.Ranging(CM);
  if (length < 15) {

    motor1.run(RELEASE);
    motor2.run(RELEASE);
    delay(500);

    motor1.run(BACKWARD);
    motor1.setSpeed(power);
    motor2.run(BACKWARD);
    motor2.setSpeed(power);
    delay(500);

    motor1.run(RELEASE);
    motor2.run(RELEASE);
    delay(500);

    motor1.run(RELEASE);
    motor1.setSpeed(power);
    motor2.run(FORWARD);
    motor2.setSpeed(power);
    delay(1000);
  }
   if (Serial3.available() > 0) {
     symbol = Serial3.read();
     Serial3.println(symbol);
     motor1.run(RELEASE);
     motor2.run(RELEASE);
     delay(500);
     if (symbol == '1') {
       motor1.run(FORWARD);
       motor1.setSpeed(power);
       motor2.run(FORWARD);
       motor2.setSpeed(power);
     }
     if (symbol == '2') {
       motor1.run(BACKWARD);
       motor1.setSpeed(power);
       motor2.run(BACKWARD);
       motor2.setSpeed(power);
     }
     if (symbol == '3') {
       motor1.run(RELEASE);
       motor1.setSpeed(power);
       motor2.run(FORWARD);
       motor2.setSpeed(power);
     }

     if (symbol == '4') {
       motor1.run(FORWARD);
       motor1.setSpeed(power);
       motor2.run(RELEASE);
       motor2.setSpeed(power);
     }
     if (symbol == '0') {
       motor1.run(RELEASE);
       motor2.run(RELEASE);
     }
   }
}
