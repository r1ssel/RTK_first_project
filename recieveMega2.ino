#define Mot_L_PWM 9 
#define Mot_L_DIR1 8
#define Mot_L_DIR2 7
#define Mot_R_PWM 10 
#define Mot_R_DIR1 11
#define Mot_R_DIR2 15

#include <Servo.h>
Servo Top;
Servo Mid;
Servo Bot;
Servo Crab;


void setup() {
  //realise serial ports
  Serial.begin(9600); // test serial microUSB
  Serial1.begin(57600); // holybro Serial
  //define motor pins
  pinMode(Mot_L_PWM, OUTPUT);
  pinMode(Mot_L_DIR1, OUTPUT);
  pinMode(Mot_L_DIR2, OUTPUT);
  pinMode(Mot_R_PWM, OUTPUT);
  pinMode(Mot_R_DIR1, OUTPUT);
  pinMode(Mot_R_DIR2, OUTPUT);
  //define manipulator pins
 Top.attach(6);
  Mid.attach(12);
  Bot.attach(13);
  Crab.attach(5);
  //define led

  //set start state 
  analogWrite(Mot_L_PWM, 0);
  digitalWrite(Mot_L_DIR1, 1);
  digitalWrite(Mot_L_DIR2, 1);
  analogWrite(Mot_R_PWM, 0);
  digitalWrite(Mot_R_DIR1, 1);
  digitalWrite(Mot_R_DIR2, 1);
  
}

struct Avto {
  uint16_t left;
  uint16_t rigth;
  uint16_t top;
  uint16_t mid;
  uint16_t bot;
  uint16_t crab;
  bool led;
};

Avto car;


void drive(uint16_t left, uint16_t rigth)
{
  if(left > 128)
  {
    digitalWrite(Mot_L_DIR1, 0);
    digitalWrite(Mot_L_DIR2, 1);
    analogWrite(Mot_L_PWM, (left - 128)*2); 
  }
  else
  {
    digitalWrite(Mot_L_DIR1, 1);
    digitalWrite(Mot_L_DIR2, 0);
    analogWrite(Mot_L_PWM, (128 - left)*2);  
  }
  
  if(rigth > 128)
  {
    digitalWrite(Mot_R_DIR1, 0);
    digitalWrite(Mot_R_DIR2, 1);
    analogWrite(Mot_R_PWM, (rigth - 128)*2);  //changed
  }
  else
  {
    digitalWrite(Mot_R_DIR1, 1);
    digitalWrite(Mot_R_DIR2, 0);
    analogWrite(Mot_R_PWM, (128 - rigth)*2);  //changed
  }  

}

void manipulator(uint16_t top,uint16_t mid,uint16_t bot, uint16_t crab)
{
  Top.write(top);
   Mid.write(crab);
   Bot.write(bot); 
   Crab.write(mid);
}

void loop() {

  if (Serial1.readBytes((byte*)&car, sizeof(car)))  
  {
  drive(car.left, car.rigth);
  manipulator(car.top, car.mid, car.bot, car.crab);
  }          
                  
  delay(10); 
} 
