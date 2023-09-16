


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
  else{
    digitalWrite(INAL, LOW);
    digitalWrite(INAR, LOW);
    digitalWrite(INBL, LOW);
    digitalWrite(INBR, LOW);
  }

  analogWrite(PWML, motorSpeed);
  analogWrite(PWMR, motorSpeed);
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