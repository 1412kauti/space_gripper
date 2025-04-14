#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
 
Adafruit_PWMServoDriver pca9685 = Adafruit_PWMServoDriver(0x40);
 
#define SERVOMIN  80  // Minimum value
#define SERVOMAX  530  // Maximum value
#define Finger1base  0   
#define Finger1mid  1  
#define Finger1tip  2 
#define Finger2base  3 
#define Finger2mid  4 
#define Finger2tip  5
#define Finger3base  6
#define Finger3mid  7
#define Finger3tip  8
#define Palm1  9
#define Palm2  10
#define Palm3  11

const int button1 = 19;
const int button2 = 18;
const int button3 = 5;
const int button4 = 17;
const int button5 = 16;
const int button6 = 4;
int finger1[3]= { 0 };
int finger2[3]= { 0 };
int finger3[3]= { 0 };
int palm[3]= { 0 };
int pwm[12]={ 0 };
int buttonstates[6]={ 0 };

void setup() {
 
  Serial.begin(115200);
 
  Serial.println("PCA9685 Servo Test");
 
  pca9685.begin();

  pca9685.setPWMFreq(50);

  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);
  pinMode(button5, INPUT);
}
 
void loop() {
  buttonstates[0]=digitalRead(button1);
  buttonstates[1]=digitalRead(button2);
  buttonstates[2]=digitalRead(button3);
  buttonstates[3]=digitalRead(button4);
  buttonstates[4]=digitalRead(button5);
  buttonstates[5]=digitalRead(button6);
//Sphere large
  if (buttonstates[0]== HIGH){
    finger1[0]=90;//don't go beyond 90
    finger1[1]=42;//don't go beyond 90
    finger1[2]=117;//don't go beyond 180

    finger2[0]=90;//don't go beyond 90
    finger2[1]=32;//don't go beyond 90
    finger2[2]=91;//don't go beyond 180

    finger3[0]=90;//don't go beyond 90
    finger3[1]=60;//don't go beyond 90
    finger3[2]=91;//don't go beyond 180

    palm[0]=0;//don't go beyond 60
    palm[1]=0;//don't go beyond 60
    palm[2]=30;//don't go beyond 60
  }
  //flat pose 1
  else if (buttonstates[1]== HIGH){
    finger1[0]=90;//don't go beyond 90
    finger1[1]=70;//don't go beyond 90
    finger1[2]=100;//don't go beyond 180

    finger2[0]=90;//don't go beyond 90
    finger2[1]=90;//don't go beyond 90
    finger2[2]=90;//don't go beyond 180

    finger3[0]=0;//don't go beyond 90
    finger3[1]=0;//don't go beyond 90
    finger3[2]=90;//don't go beyond 180

    palm[0]=0;//don't go beyond 60
    palm[1]=30;//don't go beyond 60
    palm[2]=0;//don't go beyond 60
  }
  //flat pose 2
  else if (buttonstates[2]== HIGH){
    finger1[0]=0;//don't go beyond 90
    finger1[1]=0;//don't go beyond 90
    finger1[2]=90;//don't go beyond 180

    finger2[0]=90;//don't go beyond 90
    finger2[1]=90;//don't go beyond 90
    finger2[2]=10;//don't go beyond 180

    finger3[0]=90;//don't go beyond 90
    finger3[1]=90;//don't go beyond 90
    finger3[2]=10;//don't go beyond 180

    palm[0]=0;//don't go beyond 60
    palm[1]=0;//don't go beyond 60
    palm[2]=60;//don't go beyond 60
  }
  //bolt pose medium
  else if (buttonstates[3]== HIGH){
    finger1[0]=90;//don't go beyond 90
    finger1[1]=90;//don't go beyond 90
    finger1[2]=0;//don't go beyond 180

    finger2[0]=90;//don't go beyond 90
    finger2[1]=90;//don't go beyond 90
    finger2[2]=0;//don't go beyond 180

    finger3[0]=90;//don't go beyond 90
    finger3[1]=90;//don't go beyond 90
    finger3[2]=0;//don't go beyond 180

    palm[0]=15;//don't go beyond 60
    palm[1]=15;//don't go beyond 60
    palm[2]=30;//don't go beyond 60
  }
  //bolt large
  else if (buttonstates[4]== HIGH){
    finger1[0]=0;//don't go beyond 90
    finger1[1]=0;//don't go beyond 90
    finger1[2]=90;//don't go beyond 180

    finger2[0]=0;//don't go beyond 90
    finger2[1]=0;//don't go beyond 90
    finger2[2]=90;//don't go beyond 180

    finger3[0]=90;//don't go beyond 90
    finger3[1]=85;//don't go beyond 90
    finger3[2]=135;//don't go beyond 180

    palm[0]=0;//don't go beyond 60
    palm[1]=0;//don't go beyond 60
    palm[2]=30;//don't go beyond 60
  }
  //Sphere small
  else if (buttonstates[5]== HIGH){
    finger1[0]=85;//don't go beyond 90
    finger1[1]=70;//don't go beyond 90
    finger1[2]=10;//don't go beyond 180

    finger2[0]=85;//don't go beyond 90
    finger2[1]=70;//don't go beyond 90
    finger2[2]=10;//don't go beyond 180

    finger3[0]=85;//don't go beyond 90
    finger3[1]=70;//don't go beyond 90
    finger3[2]=10;//don't go beyond 180

    palm[0]=30;//don't go beyond 60
    palm[1]=30;//don't go beyond 60
    palm[2]=30;//don't go beyond 60
  }
  //zero
  else {
  finger1[0]=0;//don't go beyond 90
  finger1[1]=0;//don't go beyond 90
  finger1[2]=90;//don't go beyond 180

  finger2[0]=0;//don't go beyond 90
  finger2[1]=0;//don't go beyond 90
  finger2[2]=90;//don't go beyond 180

  finger3[0]=0;//don't go beyond 90
  finger3[1]=0;//don't go beyond 90
  finger3[2]=90;//don't go beyond 180

  palm[0]=0;//don't go beyond 60
  palm[1]=0;//don't go beyond 60
  palm[2]=0;//don't go beyond 60
  }
  
//Finger 1 
  pwm[0] = map(finger1[0], 0, 180, SERVOMIN, SERVOMAX);
  pca9685.setPWM(Finger1base, 0, pwm[0]);

  pwm[1] = map(finger1[1], 0, 180, SERVOMIN, SERVOMAX);
  pca9685.setPWM(Finger1mid, 0, pwm[1]);

  pwm[2] = map(finger1[2], 0, 180, SERVOMIN, SERVOMAX);
    pca9685.setPWM(Finger1tip, 0, pwm[2]);

//  Finger2

  pwm[3] = map(finger2[0], 0, 180, SERVOMIN, SERVOMAX);
  pca9685.setPWM(Finger2base, 0, pwm[3]);

  pwm[4] = map(finger2[1], 0, 180, SERVOMIN, SERVOMAX);
  pca9685.setPWM(Finger2mid, 0, pwm[4]);

  pwm[5] = map(finger2[2], 0, 180, SERVOMIN, SERVOMAX);
  pca9685.setPWM(Finger2tip, 0, pwm[5]);

//Finger 3
  pwm[6] = map(finger3[0], 0, 180, SERVOMIN, SERVOMAX);
  pca9685.setPWM(Finger3base, 0, pwm[6]);

  pwm[7] = map(finger3[1], 0, 180, SERVOMIN, SERVOMAX);
  pca9685.setPWM(Finger3mid, 0, pwm[7]);

  pwm[8] = map(finger3[2], 0, 180, SERVOMIN, SERVOMAX);
  pca9685.setPWM(Finger3tip, 0, pwm[8]);

//Palm

  pwm[9] = map(palm[0], 0, 180, SERVOMIN, SERVOMAX);
  pca9685.setPWM(Palm1, 0, pwm[9]);

  pwm[10] = map(palm[1], 0, 180, SERVOMIN, SERVOMAX);
  pca9685.setPWM(Palm2, 0, pwm[10]);

  pwm[11] = map(palm[2], 0, 180, SERVOMIN, SERVOMAX);
  pca9685.setPWM(Palm3, 0, pwm[11]);


  delay(100);
}