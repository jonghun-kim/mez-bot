#include <AFMotor.h> //header
int set_speed;
// DC motor

AF_DCMotor rear_left(3);
AF_DCMotor rear_right(4);
void go_f(int);
void go_b(int);
void turn_l(int);
void turn_r(int);
void stop_move();

void setup() {

  Serial.begin(9600);           // set up Serial library at 9600 bps

  Serial.println("Motor party!");

  rear_left.setSpeed(set_speed);
  rear_right.setSpeed(set_speed);
  
  rear_right.run(RELEASE);
  rear_left.run(RELEASE);

}


void loop() {
  set_speed = 255;
  go_f(set_speed);
  delay(2000);

  turn_l(set_speed);
  delay(2000);

  go_b(set_speed);
  delay(2000);

  turn_r(set_speed);
  delay(2000);

  stop_move();
  delay(3000);

  
}














void go_f(int speed){
  rear_left.setSpeed(speed - 55);
  rear_right.setSpeed(speed);
  rear_right.run(FORWARD);
  rear_left.run(FORWARD);
}

void go_b(int speed){
  rear_left.setSpeed(speed - 55);
  rear_right.setSpeed(speed);
  rear_right.run(BACKWARD);
  rear_left.run(BACKWARD);
}

void turn_l(int speed){
  rear_left.setSpeed(speed);
  rear_right.setSpeed(speed);
  rear_right.run(BACKWARD);
  rear_left.run(FORWARD);
}

void turn_r(int speed){
  rear_left.setSpeed(speed);
  rear_right.setSpeed(speed);
  rear_left.run(BACKWARD);
  rear_right.run(FORWARD);
}

void stop_move(){
  rear_right.run(RELEASE);
  rear_left.run(RELEASE);
}