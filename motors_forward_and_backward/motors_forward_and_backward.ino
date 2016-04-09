#include <Boards.h>
#include <Firmata.h>

#include <AFMotor.h>  // Подключаем библиотеку для работы с шилдом

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
int power=255;

void setup() {
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
  delay(1000);

  motor1.run(RELEASE);
  motor2.run(RELEASE);
  delay(500);

  motor1.run(BACKWARD);
  motor1.setSpeed(power);
  motor2.run(BACKWARD);
  motor2.setSpeed(power);
  delay(1000);

  motor1.run(RELEASE);
  motor2.run(RELEASE);
  delay(500);

}
