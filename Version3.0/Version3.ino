#include <SoftwareSerial.h>
#include <AFMotor.h>
#define TRIG_F A0 //TRIG 핀 설정 (초음파 보내는 핀)
#define ECHO_F A1 //ECHO 핀 설정 (초음파 받는 핀)
#define TRIG_L A2 //TRIG 핀 설정 (초음파 보내는 핀)
#define ECHO_L A3 //ECHO 핀 설정 (초음파 받는 핀)
#define TRIG_R A4 //TRIG 핀 설정 (초음파 보내는 핀)
#define ECHO_R A5 //ECHO 핀 설정 (초음파 받는 핀)


AF_DCMotor motor_1(1);
AF_DCMotor motor_2(2);

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_F, OUTPUT);
  pinMode(ECHO_F, INPUT);
  pinMode(TRIG_L, OUTPUT);
  pinMode(ECHO_L, INPUT);
  pinMode(TRIG_R, OUTPUT);
  pinMode(ECHO_R, INPUT);

  Serial.println("Motor party!");
  motor_1.setSpeed(100);
  motor_2.setSpeed(100);
  motor_1.run(RELEASE);
  motor_2.run(RELEASE);
}

void loop() {
  Serial.print("\F_Distance : ");
  int F_distance = Get_distance(TRIG_F, ECHO_F);
  Serial.println("\n\n");
  if (F_distance <= 10) {
    Stop();
    Serial.print("\L_Distance : ");
    int L_distance = Get_distance(TRIG_L, ECHO_L);
    Serial.print("\R_Distance : ");
    int R_distance = Get_distance(TRIG_R, ECHO_R);
    delay(1000);
    if (R_distance > L_distance) {
      Serial.println("Right Turn");
      Right();
      delay(500);
    }
    else if (L_distance > R_distance) {
      Serial.println("Left Turn");
      Left();
      delay(500);
    }
  }
  else {
    Go();
  }
}

int Get_distance(int TRIG, int ECHO) {
  long duration, distance;
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);
  duration = pulseIn (ECHO, HIGH);
  distance = duration * 17 / 1000;
  Serial.println(distance);
  return distance;
}

void Go() {
  motor_1.setSpeed(150);
  motor_2.setSpeed(150);
  motor_1.run(FORWARD);
  motor_2.run(FORWARD);
}

void Left() {
  motor_1.setSpeed(200);
  motor_2.setSpeed(150);
  motor_1.run(FORWARD);
  motor_2.run(BACKWARD);
}

void Right() {
  motor_1.setSpeed(150);
  motor_2.setSpeed(200);
  motor_1.run(BACKWARD);
  motor_2.run(FORWARD);
}

void Back() {
  motor_1.run(BACKWARD);
  motor_2.run(BACKWARD);
}

void Stop() {
  motor_1.run(RELEASE);
  motor_2.run(RELEASE);
}
