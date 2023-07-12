#include <SoftwareSerial.h>


#define MOTOR_A_SPEED 10
#define MOTOR_B_SPEED 11
#define MOTOR_A_DIRECTION 12
#define MOTOR_B_DIRECTION 13
#define TRIG_F A0 //TRIG 핀 설정 (초음파 보내는 핀)
#define ECHO_F A1 //ECHO 핀 설정 (초음파 받는 핀)
#define TRIG_L A2 //TRIG 핀 설정 (초음파 보내는 핀)
#define ECHO_L A3 //ECHO 핀 설정 (초음파 받는 핀)
#define TRIG_R A4 //TRIG 핀 설정 (초음파 보내는 핀)
#define ECHO_R A5 //ECHO 핀 설정 (초음파 받는 핀)
#define MOTOR_SPEED 200

void setup() {
  Serial.begin(9600);
  // 모터 설정
  pinMode(MOTOR_A_DIRECTION, OUTPUT);
  pinMode(MOTOR_B_DIRECTION, OUTPUT);

  // 초음파 센서 설정
  pinMode(TRIG_F, OUTPUT);
  pinMode(ECHO_F, INPUT);
  pinMode(TRIG_L, OUTPUT);
  pinMode(ECHO_L, INPUT);
  pinMode(TRIG_R, OUTPUT);
  pinMode(ECHO_R, INPUT);

  Serial.println("Motor party!");
  
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
    Forward();
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

void Forward() {
  digitalWrite(MOTOR_A_DIRECTION, LOW);
  digitalWrite(MOTOR_B_DIRECTION, LOW);
  analogWrite(MOTOR_A_SPEED, MOTOR_SPEED);
  analogWrite(MOTOR_B_SPEED, MOTOR_SPEED);
}

void Left() {
  digitalWrite(MOTOR_A_DIRECTION, LOW);
  digitalWrite(MOTOR_B_DIRECTION, HIGH);
  analogWrite(MOTOR_A_SPEED, MOTOR_SPEED);
  analogWrite(MOTOR_B_SPEED, MOTOR_SPEED);
}

void Right() {
  digitalWrite(MOTOR_A_DIRECTION, HIGH);
  digitalWrite(MOTOR_B_DIRECTION, LOW);
  analogWrite(MOTOR_A_SPEED, MOTOR_SPEED);
  analogWrite(MOTOR_B_SPEED, MOTOR_SPEED);
}

void Back() {
  digitalWrite(MOTOR_A_DIRECTION, HIGH);
  digitalWrite(MOTOR_B_DIRECTION, HIGH);
  analogWrite(MOTOR_A_SPEED, MOTOR_SPEED);
  analogWrite(MOTOR_B_SPEED, MOTOR_SPEED);
}

void Stop() {
  digitalWrite(MOTOR_A_DIRECTION, HIGH);
  digitalWrite(MOTOR_B_DIRECTION, HIGH);
  analogWrite(MOTOR_A_SPEED, 0);
  analogWrite(MOTOR_B_SPEED, 0);
}
