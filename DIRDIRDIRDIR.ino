

#define INAL 4
#define INBL 7
#define ENL 2
#define PWML 3

#define INAR 13
#define INBR 12
#define ENR 8
#define PWMR 5

#define BRAKE 0
#define CW 1
#define CCW 6
#define LT 9
#define RT 10





int motorSpeed = 100;
unsigned short Motor_Status = BRAKE;

void setup(){
  pinMode(INAL, OUTPUT);
  pinMode(INBL, OUTPUT);
  pinMode(ENL, OUTPUT);

  
  
  pinMode(INAR, OUTPUT);
  pinMode(INBR, OUTPUT);
  pinMode(ENR, OUTPUT);

  Serial.begin(9600);
  Serial.println("Begin motor control");
  Serial.println("Press the button to control option");
  Serial.println("0. RUCHNIK");
  Serial.println("1. FORWARD");
  Serial.println("6. REVERSE");
  Serial.println("9. Turn Left");
  Serial.println("10. Turn Right");
  Serial.println();
}

void loop()
{
char user_input;

  while(Serial.available())
  {
    user_input = Serial.read();
    digitalWrite(ENL, HIGH);
    digitalWrite(ENR, HIGH);

    if (user_input == '0'){
      Stop();
    }
    else if(user_input == '1'){
      Forward();
    }
    else if(user_input == '6'){
      Reverse();
    }
    else if(user_input == '9'){
      TurnLeft();
    }
    else if(user_input == '10'){
      TurnRight();
    }
    
    
  }
}

void Stop(){
  Serial.println("Stop");
  Motor_Status = BRAKE;
  motorGo(Motor_Status, 0);
}

void Forward(){
  Serial.println("Forward");
  Motor_Status = CW;
  motorGo(Motor_Status, motorSpeed);
}

void Reverse(){
  Serial.println("Reverse");
  Motor_Status = CCW;
  motorGo(Motor_Status, motorSpeed);
}

void TurnLeft()
{
  Serial.println("Left Turn");
  Motor_Status = LT;
  motorGo(Motor_Status, motorSpeed);
}

void TurnRight()
{
  Serial.println("Left Right");
  Motor_Status = RT;
  motorGo(Motor_Status, motorSpeed);
}







void motorGo(uint8_t direction, uint8_t PWM){
  if(direction == CW){
    digitalWrite(INAL, LOW);
    digitalWrite(INAR, LOW);
    digitalWrite(INBL, HIGH);
    digitalWrite(INBR, HIGH);
  }
  else if (direction == CCW){
    digitalWrite(INAL, HIGH);
    digitalWrite(INAR, HIGH);
    digitalWrite(INBL, LOW);
    digitalWrite(INBR, LOW);
  }
  else if (direction == LT){
    digitalWrite(INAL, LOW);
    digitalWrite(INAR, HIGH);
    digitalWrite(INBL, HIGH);
    digitalWrite(INBR, LOW);
  }
    else if (direction == RT){
    digitalWrite(INAL, HIGH);
    digitalWrite(INAR, LOW);
    digitalWrite(INBL, LOW);
    digitalWrite(INBR, HIGH);
  }
  else{
    digitalWrite(INAL, LOW);
    digitalWrite(INAR, LOW);
    digitalWrite(INBL, LOW);
    digitalWrite(INBR, LOW);
  }

  analogWrite(PWML, motorSpeed);
  analogWrite(PWMR, motorSpeed);
}
/*
#define PWM1 5
#define PWM2 6
#define DIR1 7
#define DIR2 8

#define INAR 13
#define INBR 12
#define ENR 8
#define PWMR 5

#define BRAKE 0
#define CW 1
#define CCW 2
#define LT 3
#define RT 4





int motorSpeed = 180;
unsigned short Motor_Status = BRAKE;

void setup(){
  //pinMode(PWM1, OUTPUT);
  pinMode(DIR1, OUTPUT);

  

  //pinMode(PWM2, OUTPUT);
  pinMode(DIR2, OUTPUT);

  Serial.begin(9600);
  Serial.println("Begin motor control");
  Serial.println("Press the button to control option");
  Serial.println("0. RUCHNIK");
  Serial.println("1. FORWARD");
  Serial.println("6. REVERSE");
  Serial.println("9. LEFT");
  Serial.println("10. RIGHT");
  Serial.println();
}

void loop()
{
char user_input;

  while(Serial.available())
  {
    user_input = Serial.read();

    if (user_input == '0'){
      Stop();
    }
    else if(user_input == '1'){
      Forward();
    }
    else if(user_input == '6'){
      Reverse();
    }
    else if(user_input == '9'){
      LeftTurn();
    }
    else if(user_input == '10'){
      RightTurn();
    }
    
    
  }
}

void Stop(){
  Serial.println("Stop");
  Motor_Status = BRAKE;
  motorGo(Motor_Status, 0);
}

void Forward(){
  Serial.println("Forward");
  Motor_Status = CW;
  motorGo(Motor_Status, motorSpeed);
}

void Reverse(){
  Serial.println("Reverse");
  Motor_Status = CCW;
  motorGo(Motor_Status, motorSpeed);
}

void LeftTurn(){
  Serial.println("Turn Left");
  Motor_Status == LT;
  motorGo(Motor_Status, motorSpeed);
}

void RightTurn(){
  Serial.println("Turn Right");
  Motor_Status == RT;
  motorGo(Motor_Status, motorSpeed);
}





void motorGo(uint8_t direction, uint8_t PWM){
  if(direction == CW){
    digitalWrite(DIR1, HIGH);
    digitalWrite(DIR2, HIGH);
    delay(100);
    digitalWrite(DIR2, HIGH);
  }
  else if (direction == CCW){
    digitalWrite(DIR1, HIGH);
    digitalWrite(DIR2, HIGH);
    delay(100);
    digitalWrite(DIR2, HIGH);
  }
  else if (direction == LT){
    digitalWrite(DIR1, HIGH);
    digitalWrite(DIR2, HIGH);
    delay(100);
    digitalWrite(DIR2, HIGH);
  }
    else if (direction == RT){
    digitalWrite(DIR1, HIGH);
    digitalWrite(DIR2, HIGH);
    delay(100);
    digitalWrite(DIR2, HIGH);
  }
  else{
    digitalWrite(DIR1, HIGH);
    digitalWrite(DIR2, HIGH);
    delay(100);
    digitalWrite(DIR2, HIGH);
  }

  analogWrite(PWM1, motorSpeed);
  analogWrite(PWM2, motorSpeed);
}





/*digitalWrite(INAL, LOW);
  digitalWrite(INBL, HIGH);
  analogWrite(PMWL, motorSpeed);

  digitalWrite(INAR, LOW);
  digitalWrite(INBR, HIGH);
  analogWrite(PMWR, motorSpeed);

  /*delay(1000);

  digitalWrite(ENL, LOW);
  digitalWrite(ENR, LOW); */