const int s1 = A1;
const int s2 = A2;
const int s3 = A3;
const int s4 = A4;
const int s5 = A5;

const int enA = 9;
const int in1 = 8;
const int in2 = 6;

const int enB = 3;
const int in3 = 7;
const int in4 = 5;

const int speed = 225;
const int turnSpeed = 100;
const int t = 500;

#define AR analogRead

void setup() {
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);
  pinMode(enB,OUTPUT);
  pinMode(enA,OUTPUT);

  pinMode(s1,INPUT);
  pinMode(s2,INPUT);
  pinMode(s3,INPUT);
  pinMode(s4,INPUT);
  pinMode(s5,INPUT);
}

void loop() {
  if(AR(s1)>=t && AR(s2)>=t && AR(s3)<=t && AR(s4)>=t && AR(s5)>=t ) {
    forward(speed,speed);
  } else if (AR(s1)>=t && AR(s2)<=t && AR(s3)>=t && AR(s4)>=t && AR(s5)>=t ) {
    forward(turnSpeed,speed);
  } else if (AR(s1)>=t && AR(s2)>=t && AR(s3)>=t && AR(s4)<=t && AR(s5)>=t ) {
    forward(speed,turnSpeed);
  } else if (AR(s1)>=t && (AR(s2)>=t || AR(s3)>=t )) {
    left();
  } else if (AR(s5)>=t && (AR(s4)>=t || AR(s3)>=t )) {
    right();
  } else if (AR(s1)>=t && AR(s2)>=t && AR(s3)>=t && AR(s4)>=t && AR(s5)>=t ) {
    stop();
  } else if (AR(s1)<=t && AR(s2)<=t && AR(s3)<=t && AR(s4)<=t && AR(s5)<=t ) {
    stop();
  } else {
    stop();
  }
}

void forward(int leftSpeed, int rightSpeed) {
  analogWrite(enA,rightSpeed);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);

  analogWrite(enB,leftSpeed);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
}

void right() {
  analogWrite(enA,speed);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);

  analogWrite(enB,turnSpeed);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
}

void left() {
  analogWrite(enA,turnSpeed);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);

  analogWrite(enB,speed);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
}

void stop() {
  analogWrite(enA, 0);
  analogWrite(enB, 0);
  digitalWrite(in1,LOW);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,LOW);
}

