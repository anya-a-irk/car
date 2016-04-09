# Arduino car

Arduino car project with remote controls.
Using [AFMotor library](https://github.com/adafruit/Adafruit-Motor-Shield-library) for controlling motors

[![youtube test drive video](https://img.youtube.com/vi/wXmuz_UJH7o/0.jpg)](https://www.youtube.com/watch?v=wXmuz_UJH7o)

## motors_forward

Move 2 car motors forward with specified speed

## motors_forward_and_backward

Move 2 car motors forward and backward with specified speed

## sonar

Using [Ultrasonic library](http://robocraft.ru/blog/electronics/772.html) for controlling sonar
Measures the distance to an obstacle

## motors_and_sonars

Using [Ultrasonic library](http://robocraft.ru/blog/electronics/772.html) for controlling sonar
If there is no obstacle before sonar move forward, else car turns and move forward

## bluetooth_and_2motors_4directions_with_sonar

Using [Ultrasonic library](http://robocraft.ru/blog/electronics/772.html) for controlling sonar
Move car for 4 directions: forward, backward, right, left, directions received from bluetooth module. If there is obstacle before sonar car release the motors
