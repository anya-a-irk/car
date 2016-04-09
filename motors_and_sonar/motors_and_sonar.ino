#include <Boards.h>
#include <Firmata.h>

#include <Ultrasonic.h>
Ultrasonic ultrasonic(22,23);
int power = 150;

#include <AFMotor.h>  // Подключаем библиотеку для работы с шилдом

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);

void setup() {

  Serial.begin(9600);
  motor1.setSpeed(255);
  motor1.run(RELEASE);
  motor2.setSpeed(255);
  motor2.run(RELEASE);
}

void loop() {
  motor1.run(FORWARD);
  motor1.setSpeed(power);
  motor2.run(FORWARD);
  motor2.setSpeed(power);

  Serial.print(ultrasonic.Ranging(CM));
  Serial.println("cm");
  int length = ultrasonic.Ranging(CM);
  if (length < 20) {

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
    delay(500);
  }
}
