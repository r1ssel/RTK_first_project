/*#define Mot_L_PWM 9 
#define Mot_L_DIR1 8
#define Mot_L_DIR2 7
#define Mot_R_PWM 10 
#define Mot_R_DIR1 11
#define Mot_R_DIR2 15
#define Top 6
#define Mid 12
#define Bot 13
*/
void setup() {
  //realise serial ports
  Serial.begin(9600); // test serial microUSB
  Serial1.begin(57600); // holybro Serial
  //define motor pins
  /*pinMode(Mot_L_PWM, OUTPUT);
  pinMode(Mot_L_DIR1, OUTPUT);
  pinMode(Mot_L_DIR2, OUTPUT);
  pinMode(Mot_R_PWM, OUTPUT);
  pinMode(Mot_R_DIR1, OUTPUT);
  pinMode(Mot_R_DIR2, OUTPUT);
  //define manipulator pins
  pinMode(Top, OUTPUT);
  pinMode(Mid, OUTPUT);
  pinMode(Bot, OUTPUT);
  //define led
*/
  //set start state 
 /* analogWrite(Mot_L_PWM, 0);
  digitalWrite(Mot_L_DIR1, 1);
  digitalWrite(Mot_L_DIR2, 1);
  analogWrite(Mot_R_PWM, 0);
  digitalWrite(Mot_R_DIR1, 1);
  digitalWrite(Mot_R_DIR2, 1);
  */
}

struct Avto {
  uint16_t left;
  uint16_t rigth;
  uint16_t Top;
  uint16_t Mid;
  uint16_t Bot;
  bool led;
};

Avto car;


/*void drive(uint16_t left, uint16_t rigth)
{
  if(left > 128)
  {
    digitalWrite(Mot_L_DIR1, 1);
    digitalWrite(Mot_L_DIR2, 0);
    analogWrite(Mot_L_PWM, 256 - left);
  }
  else
  {
    digitalWrite(Mot_L_DIR1, 0);
    digitalWrite(Mot_L_DIR2, 1);
    analogWrite(Mot_L_PWM, left);
  }
  if(rigth > 128)
  {
    digitalWrite(Mot_R_DIR1, 1);
    digitalWrite(Mot_R_DIR2, 0);
    analogWrite(Mot_R_PWM, 256 + rigth);
  }
  else
  {
    digitalWrite(Mot_R_DIR1, 0);
    digitalWrite(Mot_R_DIR2, 1);
    analogWrite(Mot_R_PWM, rigth);
  }  
}*/

/*void manipulator(uint16_t top,uint16_t mid,uint16_t bot)
{
  
}
*/
void loop() {

  /*if (Serial1.readBytes((byte*)&car, sizeof(car)))
  drive(car.left, car.rigth);
  manipulator(car.top, car.mid, car.bot);
  */
  if (Serial1.readBytes((byte*)&car, sizeof(car))){
  Serial.print(car.left);
  Serial.print("   ");
  Serial.print(car.rigth);
  Serial.print("   ");
  Serial.print(car.Top);
  Serial.print("   ");
  Serial.print(car.Mid);
  Serial.print("   ");
  Serial.println(car.Bot);
  Serial.print("   ");
  Serial.print(car.led);
  Serial.println("   ");
  delay(10);
  }
  
}
