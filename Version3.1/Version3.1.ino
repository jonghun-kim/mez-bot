#include <SoftwareSerial.h>
#include <AFMotor.h>
#define TRIG_F A0 //TRIG 핀 설정 (초음파 보내는 핀)
#define ECHO_F A1 //ECHO 핀 설정 (초음파 받는 핀)
#define TRIG_L A2 //TRIG 핀 설정 (초음파 보내는 핀)
#define ECHO_L A3 //ECHO 핀 설정 (초음파 받는 핀)
#define TRIG_R A4 //TRIG 핀 설정 (초음파 보내는 핀)
#define ECHO_R A5 //ECHO 핀 설정 (초음파 받는 핀)


AF_DCMotor motor_1(3);
AF_DCMotor motor_2(4);

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_F, OUTPUT);
  pinMode(ECHO_F, INPUT);
  pinMode(TRIG_L, OUTPUT);
  pinMode(ECHO_L, INPUT);
  pinMode(TRIG_R, OUTPUT);
  pinMode(ECHO_R, INPUT);

  Serial.println("Motor party!");
  motor_1.setSpeed(50);
  motor_2.setSpeed(50);
  motor_1.run(RELEASE);
  motor_2.run(RELEASE);
}

void loop() {
  // Left();
  // Right();
  delay(1000);
  for(int i=0;i<2;i++){
    Go(600);
    Stop(1000);
    Right(2000);
    Stop(1000);
  }

  for(int i=0;i<2;i++){
    Go(600);
    Stop(1000);
    Left(2000);
    Stop(1000);
  }
  
  Go(1500);
  Stop(1000);
  Left(2000);
  Stop(1000);
  
  for(int i=0;i<2;i++){
    Go(600);
    Stop(1000);
    Right(2000);
    Stop(1000);
  }

  Go(1000);
  Stop(1000);
  Right(2000);
  Stop(1000);
  Go_Last(5000);
  Stop(100);
  while(1) 
    delay(100);



  // Serial.print("\F_Distance : ");
  // int F_distance = Get_distance(TRIG_F, ECHO_F);
  // Serial.println("\n\n");
  // if (F_distance <= 10) {
  //   Stop();
  //   Serial.print("\L_Distance : ");
  //   int L_distance = Get_distance(TRIG_L, ECHO_L);
  //   Serial.print("\R_Distance : ");
  //   int R_distance = Get_distance(TRIG_R, ECHO_R);
  //   delay(1000);
  //   if (R_distance > L_distance) {
  //     Serial.println("Right Turn");
  //     Back();
  //     delay(200);
  //     Right();
  //     delay(1000);
  //   }
  //   else if (L_distance > R_distance) {
  //     Serial.println("Left Turn");
  //     Back();
  //     delay(200);
  //     Left();
  //     delay(1000);
  //   }
  // }
  // else {
  //   Go();
  // }
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

void Go(int time) {
  motor_1.setSpeed(150);
  motor_2.setSpeed(150);
  // motor_1.run(FORWARD);
  // motor_2.run(FORWARD);
  motor_1.run(BACKWARD);
  motor_2.run(BACKWARD);
  delay(time);
}
void Go_Last(int time) {
  motor_1.setSpeed(255);
  motor_2.setSpeed(255);
  // motor_1.run(FORWARD);
  // motor_2.run(FORWARD);
  motor_1.run(BACKWARD);
  motor_2.run(BACKWARD);
  delay(time);
}

void Left(int time) {
  motor_1.setSpeed(200);
  motor_2.setSpeed(255);
  // motor_1.run(FORWARD);
  // motor_2.run(BACKWARD);
  motor_1.run(BACKWARD);
  motor_2.run(FORWARD);
  delay(time);
}

void Right(int time) {
  motor_1.setSpeed(255);
  motor_2.setSpeed(200);
  // motor_1.run(BACKWARD);
  // motor_2.run(FORWARD);
  motor_1.run(FORWARD);
  motor_2.run(BACKWARD);
  delay(time);
}

void Back(int time) {
  motor_1.setSpeed(100);
  motor_2.setSpeed(100);
  // motor_1.run(BACKWARD);
  // motor_2.run(BACKWARD);
  motor_1.run(FORWARD);
  motor_2.run(FORWARD);
  delay(time);
}

void Stop(int time) {
  motor_1.run(RELEASE);
  motor_2.run(RELEASE);
  delay(time);
}
