/*Begining of Auto generated code by Atmel studio */
#include <Arduino.h>
/*End of auto generated code by Atmel studio */




//Beginning of Auto generated function prototypes by Atmel Studio
void runLeftMotor(int Speed);
void runRightMotor(int Speed);
void moveRobot(int Speed);
void turnRobot(int Speed);
int sensor(char which);
//End of Auto generated function prototypes by Atmel Studio





#include <Ultrasonic.h>
Ultrasonic ultrasonic(12, 3); // (Trig PIN,Echo PIN)



String status,search;
const int approachUntil=150,backUntil=150,leftUntil=700,rightUntil=700;
int approachValue,backValue,leftValue,rightValue;
int moveSpeed,turnSpeed;
int Loop;
int nbUltra;

void setup() {

  
  status="start";
  moveSpeed=255;
  turnSpeed=155;
  search="";
  Loop=0;
  
  
}

void loop() {

  Loop++;

    if(Loop==220)status="search";

  if (  sensor('u')<=48   ){
    status="attack";
    
  }
  else{
    if(     (  status=="attack" )  &&    ( sensor('u')>48 )  &&    ( sensor('u')>48 ) &&    ( sensor('u')>48 ) &&    ( sensor('u')>48 )  &&    ( sensor('u')>48 )  &&    ( sensor('u')>48 ) &&    ( sensor('u')>48 ) &&    ( sensor('u')>48 )  &&    ( sensor('u')>48 )  &&    ( sensor('u')>48 ) &&    ( sensor('u')>48 ) &&    ( sensor('u')>48 )  &&    ( sensor('u')>48 ) ){
      
      status="refresh";
    }
  }
  
  
  if( sensor('b')==0 )     {
    
    status="approach";
    
    
  }


  if(   sensor('f')==0        ){
    status="back";
  }
  
  


  

  
  
  
  if(status!="approach") approachValue=0;
  if(status!="back") backValue=0;
  if(  (status!="search")   &&   (status!="refresh")  ){
    leftValue=0;
    rightValue=0;
  }

  
  if ( status=="start"  ){
    if(Loop==1)delay(3360);
    moveRobot(-moveSpeed);
  }
  
  
  if( status=="attack"){
    
    moveRobot(+moveSpeed);
    
  }
  
  if (      status=="approach"   )
  {
    if(  approachValue<approachUntil  ){
      approachValue++;
      moveRobot(+moveSpeed);
    }
    else  {
      status="search";
    }
  }
  
  if (      status=="back"   )
  {
    if( backValue<backUntil  ){
      backValue++;
      moveRobot(-moveSpeed);
    }
    else  {
      status="search";
    }
  }
  if(status=="search"){
    if(leftValue<leftUntil){
      leftValue++;
      search="left";
      turnRobot(-turnSpeed);
    }
    else{
      if(rightValue<rightUntil){
        rightValue++;
        search="right";
        turnRobot(turnSpeed);
      }
      else{
        leftValue=0;
        rightValue=0;
      }
    }
    
  }

  if(status=="refresh"){
    if(search=="left"){
      status="search";
      leftValue=leftUntil;
    }
    if(search=="right"){
      status="search";
      leftValue=0;
    }
    if(search=="")status="search";
  }
  
  
  
  
  

}


void runLeftMotor(int Speed) { //to go forward :+ and to go backward -
  if (Speed != 0) {
    if (Speed > 0) {
      digitalWrite(8, 0);
      digitalWrite(9, 1);
      analogWrite(10, Speed);
    }
    else {
      digitalWrite(8, 1);
      digitalWrite(9, 0);
      analogWrite(10, - Speed);
    }
  }
  else {//to stop working when speed=0
    digitalWrite(8, 0);
    digitalWrite(9, 0);
    analogWrite(10, 0);
  }
}

void runRightMotor(int Speed) { //to go forward :+ and to go backward -
  if (Speed != 0) {
    if (Speed > 0) {
      digitalWrite(7, 0);
      digitalWrite(6, 1);
      analogWrite(5, Speed);
    }
    else {
      digitalWrite(7, 1);
      digitalWrite(6, 0);
      analogWrite(5, - Speed);
    }
  }
  else { //to stop working when Speed =0
    digitalWrite(7, 0);
    digitalWrite(6, 0);
    analogWrite(5, 0);
  }
}


void moveRobot(int Speed) {//to go forward :+ and to go backward -
  runRightMotor(Speed);
  runLeftMotor(Speed);
}

void turnRobot(int Speed) { //  - to turn left and + to turn right
  runRightMotor(- Speed);
  runLeftMotor(Speed);
}

int sensor( char which) {
  switch (which) {
    case 'b': return digitalRead(13); break; // read the behind line tracking
    case 'f': return digitalRead(2); break; // read the front line tracking
    case 'u': return ultrasonic.Ranging(CM); break; // read the distance by the ultrasonic
  }
  
}














