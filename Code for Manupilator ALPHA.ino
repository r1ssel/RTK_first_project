#include <Servo.h>

#define PT 7
#define PM 8 
#define PB 9


void setup() {
Servo servo_bot;
Servo servo_mid;
Servo servo_top;

pinMode(PT, OUTPUT);
pinMode(PM, OUTPUT);
pinMode(PB, OUTPUT);

servo_bot.attach(7);
servo_mid.attach(8);
servo_top.attach(9);

int angle_bot = 0;
int angle_mid = 90;
int angle_top = 90;

Serial.begin(9600);
Serial.println("Begin control");
Serial.println("1. Up (doenst work)");
Serial.println("2. Down");
}

void loop() {
  char user_input;
  while(Serial.available())
  {
    user_input = Serial.read();

    /*if (user_input == '1')
    {
     Up(); 
    }
    */

    if (user_input == '2')
    {
     Down(); 
    }
  }

}


/*void Up()
{
  Serial.println("Up");
  if (i = 90, i <= 180, i++)
}
*/


void Down()
{
 Serial.println("Down");
 
 while (angle_top <= 180)
 {
   if (angle_top = 90, angle_top <= 180, angle_top = angle_top + 10)
   {
     servo_top.write(angle_top);
   }
 }

 while (angle_mid <= 180)
 {
   if (angle_mid = 90, angle_mid <= 180, angle_mid = angle_mid + 10)
   {
     servo_mid.write(angle_mid);
   }
 }

while (angle_bot <= 90)
 {
   if (angle_bot = 0, angle_bot <= 90, angle_bot = angle_bot + 10)
   {
     servo_bot.write(angle_bot);
   }
 }

}




















