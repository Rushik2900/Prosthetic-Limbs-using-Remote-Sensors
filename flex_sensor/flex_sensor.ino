#include <Servo.h> 
//defining all servos
Servo myServo1;
Servo myServo2;
Servo myServo3;
Servo myServo4;
Servo s1;
//defining all flex sensors
int steady,up,value,avg;
const int flexPin1 = A1; 
const int flexPin2 = A2;
const int flexPin3 = A3; 
const int flexPin4 = A4;
int angle;

void setup() 
{ 
  Serial.begin(9600);
  myServo1.attach(4);
  myServo2.attach(5);
  myServo3.attach(6);
  myServo4.attach(7);
  //s1.attach(3);
//All servos starting position  
  s1.write(10);
  myServo1.write(10);
  myServo2.write(10);
  myServo3.write(10);
  myServo4.write(10);

// Reading for calibration
  Serial.println("STEADY");
  delay(3000);
  steady=analogRead(A0);  
  Serial.println(steady);
  Serial.println("UP");
  delay(3000);
  up=analogRead(A0);
  Serial.println(up);
  delay(5000);
  Serial.print("IN ACTION");

  avg =((up+steady)/2);
  Serial.print("AVG:");
  Serial.println(avg);
  delay(2000);
 
 
} 

void loop() 
{ 
  
  value=analogRead(A0);     
  Serial.println(value);

  if(value>avg)
  {
    s1.write(10);
  }
  else if(value<avg)
  {
    s1.write(90);
  }
  Serial.println("__________________________________");


  int flexValue1;                     //Creating Variable for flex sensor 1
  int servoPosition1;                 //Creating Variable for servo 1
  
  flexValue1 = analogRead(flexPin1);  //Reading from flex sensor 1
  Serial.println("flexValue1");
  Serial.print(flexValue1);
  Serial.println("   ");

  
  servoPosition1 = map(flexValue1, 900,920, 90,0);      //Mapping with servo 1
  servoPosition1 = constrain(servoPosition1,0,90);      //Constrain for servo 1

  //Serial.println(servoPosition1);
  myServo1.write(servoPosition1);                       //input to servo 1

//-----------------------------------------------------------------------------------------------------
  int flexValue2;                     //Creating Variable for flex sensor 2
  int servoPosition2;                 //Creating Variable for servo 2
  
  flexValue2 = analogRead(flexPin2);  //Reading from flex sensor 2
  Serial.println("flexValue2");
  
  Serial.print(flexValue2);
  Serial.println("   ");

  
  servoPosition2 = map(flexValue2,725,810,150,10);      //Mapping with servo 2
  servoPosition2 = constrain(servoPosition2,0,150);     //Constrain for servo 2
  
    Serial.println(servoPosition2);
    myServo2.write(servoPosition2);                     //input to servo 2

//------------------------------------------------------------------------------------------------
  int flexValue3;                     //Creating Variable for flex sensor 3
  int servoPosition3;                 //Creating Variable for servo 3
  
  flexValue3 = analogRead(flexPin3);  //Reading from flex sensor 3
  Serial.println("flexValue3");
  
  Serial.print(flexValue3);
  Serial.println("   ");

  
  servoPosition3 = map(flexValue3,880,920,120,0);         //Mapping with servo 3
  servoPosition3 = constrain(servoPosition3,0,120);       //Constrain for servo 3
  
    Serial.println(servoPosition3);
    myServo3.write(servoPosition3);                       //input to servo 3

//-----------------------------------------------------------------------------------------------------
  int flexValue4;                     //Creating Variable for flex sensor 4
  int servoPosition4;                 //Creating Variable for servo 4
  
  flexValue4 = analogRead(flexPin4);  //Reading from flex sensor 4
  Serial.println("flexValue4");
  
  Serial.print(flexValue4);
  Serial.println("   ");

  
  servoPosition4 = map(flexValue4,800,750,0,120);             //Mapping with servo 4
  servoPosition4 = constrain(servoPosition4,0,120);           //Constrain for servo 4
  
    Serial.println(servoPosition4);
    myServo4.write(servoPosition4);                   //input to servo 4
   
//-----------------------------------------------------------------------------------------------------  
  
  
  delay(500);
} 
