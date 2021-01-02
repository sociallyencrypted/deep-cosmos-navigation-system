#include <EEPROMex.h>
#include <EEPROMVar.h>
#include<math.h>
const int buttonPin = 12;     
const int ledPin =  13; 
int MasterPower1 = 255;
int SlavePower1 = 235;
int MasterPower2 = 0;
int SlavePower2 = 0;
#define sensor1 A1 // 10 right enc
#define sensor2 A0 // 9 left enc
#define Master1 10 //left
#define Slave1 9 // right
#define Master2 5 // left_2
#define Slave2 6
char i = 0;
int finalResult;
float De1 = 0.00;
float De2 = 0.00;
int direction_base_Hd = 0;
float base_distance_Hd = 0;
float base_distance_Hd_new = 0;
float base_angle_Hd = 0;
float point1_distance_base = 0;
float point2_distance_base = 0;
float point3_distance_base  = 0;
float point1_angle_base  = 0;
float point2_angle_base  = 0;
float point3_angle_base  = 0;
float point1_angle_Hd  = 0;
float point2_angle_Hd  = 0;
float point3_angle_Hd  = 0;
float final_D = 0.00;
int Re1 = 0;
int Re2 = 0;
int Re3 = 0;
float angle_move_base_Hd = 0;
float point1_angle_Hd_navigation = 0;
float point2_angle_Hd_navigation = 0;
float point3_angle_Hd_navigation = 0;
float point1_angle_base_navigation = 0;
float point2_angle_base_navigation = 0;
float  point3_angle_base_navigation = 0;
float base_p_point1 = 0; 
float base_p_point2 = 0; 
float base_p_point3 = 0; 
float base_b_point1  = 0;
float base_b_point2  = 0;
float base_b_point3  = 0;
float point1_b_Hd = 0;
float point2_b_Hd = 0;
float point3_b_Hd = 0;
float point1_distance_robot = 0;
float point2_distance_robot = 0;
float point3_distance_robot = 0;
int p = 1;
float D2 = 0.00;
float S2 = 0.00;
float RadS2 = 0.00;
float Rad2 = 0.00;
float Degree2 = 0.00;
float D = 0.00;
float S = 0.00;
float RadS = 0.00;
float Rad = 0.00;;
float Degree = 0.00;;
int error;
const int numReadings = 10;
int val_new2;
int val_old2;
int val_new;
int val_old;
int clicks2 = 0;
int turns2 = 0;
int clicks = 0;
int turns = 0;
int limit = 450;
int readings2[numReadings];
int readings[numReadings];
int readIndex2 = 0;
int total2 = 0;
int average2 = 0;
int readIndex = 0;             
int total = 0;                 
int average = 0;
int SlavePower = 200;
int MasterPower = 200;
int Kp = 100;
int switchState;
int switchPin = 2;
int totalErrors = 0;
int Ki = 0;
int Kd = 0;
int Eprev;
int Ed;
int C;
int R;
int scale = 0;
int finalDistance = 0;
float T = 0.00;
float point1_distance_base_old;
void setup(){
 analogWrite(6,15);
  pinMode(4, OUTPUT);
  pinMode(11, OUTPUT);
digitalWrite(11, HIGH);
  digitalWrite(4, HIGH);
  Serial.begin(115200);
pinMode(13, OUTPUT);
pinMode(12, OUTPUT);
pinMode(sensor1, INPUT);
  pinMode(sensor2, INPUT);
  pinMode(Slave1, OUTPUT);
  pinMode(Slave2, OUTPUT);
  pinMode(Master1, OUTPUT);
  pinMode(Master2, OUTPUT);
  pinMode(switchPin, INPUT);
  val_old = val_new;
  val_old2 = val_new2;
  for (int thisReading = 0; thisReading < numReadings; thisReading++) {
      readings[thisReading] = 0;
    }
    
    for (int thisReading = 0; thisReading < numReadings; thisReading++) {
      readings2[thisReading] = 0;
    }
  
 direction_base_Hd = EEPROM.read(0);
  base_distance_Hd =  EEPROM.read(1) / 100.00;
  base_angle_Hd =  EEPROM.read(2) / 100.00;
  point1_distance_base = EEPROM.read(3) / 100.00;
  point2_distance_base =  EEPROM.read(4)/ 100.00;
  point3_distance_base =  EEPROM.read(5)/ 100.00;
  point1_angle_base =  EEPROM.read(6)/ 100.00;
  point2_angle_base = EEPROM.read(7)/ 100.00;
  point3_angle_base =  EEPROM.read(8)/ 100.00;
  point1_angle_Hd =  EEPROM.read(9)/ 100.00;
  point2_angle_Hd =  EEPROM.read(10)/ 100.00;
  point3_angle_Hd =  EEPROM.read(11)/ 100.00;
scale = EEPROM.read(12);
 angle_move_base_Hd = 90 - base_angle_Hd;
if (direction_base_Hd == 2) // left
{ digitalWrite(Master1, HIGH);
digitalWrite(Master2, 1);
digitalWrite(Slave1, 1);
digitalWrite(Slave2, LOW);
  }
else if (direction_base_Hd == 1) // right
{
  digitalWrite(Slave1, 0);
  digitalWrite(Slave2, LOW);
  digitalWrite(Master1, 1);
  digitalWrite(Master2, LOW);
   }
   // this part is done when values are assigned
   
}
void loop() {
   
face_base(direction_base_Hd);
 navigate();
}
int compare(float x, float y){
  int result;
  if (x > y){
    result = x - y;
  }
  else {
    result = y - x;
  }
  if (result > 2.00){
     finalResult = 0;
  }
  else{
    finalResult = 1;
  }
  return finalResult;
}


int compareAngle(float x, float y){
int result;
if (x > y){
    result = x - y;
  }
  else {
    result = y - x;
  }
  if (result > 10.00){
     finalResult = 0;
  }
  else{
    finalResult = 1;
  }
  return finalResult;
}
float getDegree(int num1){
  T = millis();
 
  if (num1 == 1){ // left
    
    D = clicks * 0.028;
    S = (D / T) * 1000;
    
    RadS = (S)/0.164;
    Rad = (RadS * T)/ 1000;
    Degree = Rad *(180 / (22/7));
    return Degree;
  }
else if(num1 == 2){ // right
D2 = clicks2 * 0.028;
 S2 = (D2 / T) * 1000;
RadS2 = S2 / 0.164;
Rad2 = (RadS2 * T) / 1000;
Degree2 = Rad2 * (180 / (22/7));
return Degree2;
}
  }
void face_base(int x){
  
  if (x == 1) {
  while (R != 1){
  angle_move_base_Hd = 90 - base_angle_Hd;
 total = total - readings[readIndex];
    readings[readIndex] = digitalRead(sensor2); // rigth
    
    total = total + readings[readIndex];
    readIndex = readIndex + 1;
    if (readIndex >= numReadings) {
      readIndex = 0;
    }
    average = total / numReadings;
    val_new = average;
  if (val_new != val_old){
    clicks++;
    val_old = val_new;
  }


  De1 = getDegree(1);
  R = compareAngle(angle_move_base_Hd, De1);
  
  


  if (R == 1){
    digitalWrite(Master1, LOW);
    digitalWrite(Master2, LOW);
    digitalWrite(Slave1, LOW);
    digitalWrite(Slave2, LOW);
   
  }
  }
  }
  else {
     while (R != 1){
  angle_move_base_Hd = 90 - base_angle_Hd;
 
  
  total2 = total2 - readings2[readIndex2];
    readings2[readIndex2] = digitalRead(sensor1); // right
    total2 = total2 + readings2[readIndex2];
    readIndex2 = readIndex2 + 1;
    if (readIndex2 >= numReadings) {
      readIndex2 = 0;
    }
    average2 = total2 / numReadings;
    val_new2 = average2; 
  if (val_new2 != val_old2){
    clicks2++;
    val_old2 = val_new2;
  }


  De2 = getDegree(2);
  
  R = compareAngle(angle_move_base_Hd, De2);
 
  if (R == 1){
    digitalWrite(Slave1, LOW);
   digitalWrite(Slave2, LOW);
   digitalWrite(Master1, LOW);
   digitalWrite(Master2, LOW);
  }
    
  }
}

Serial.println("Here In FACE_BASE");
}






 void navigate(){
clicks = 0;
clicks2 = 0;
D = 0.00;
D2 = 0.00;  


  Serial.println("HERE IN NAVIG");


  




while(Re1 == 0 && Re2 == 0 && Re3 == 0){


 
analogWrite(Master1, MasterPower);
analogWrite(Master2, 0);
analogWrite(Slave1, SlavePower);
analogWrite(Slave2, 0);


  total = total - readings[readIndex];
    readings[readIndex] = digitalRead(sensor1); // right
    
    total = total + readings[readIndex];
    readIndex = readIndex + 1;
    if (readIndex >= numReadings) {
      readIndex = 0;
    }
    average = total / numReadings;
    val_new = average;
    
    total2 = total2 - readings2[readIndex2];
    readings2[readIndex2] = digitalRead(sensor2); // left
    total2 = total2 + readings2[readIndex2];
    readIndex2 = readIndex2 + 1;
    if (readIndex2 >= numReadings) {
      readIndex2 = 0;
    }
    average2 = total2 / numReadings;
    val_new2 = average2; 




    // counting rotations
if (val_new != val_old) { // left
      clicks++;
      val_old = val_new;
    }
    if (val_new2 != val_old2) { // right
      clicks2++;
      val_old2 = val_new2;
    }
    //navigation main part

    
    if(clicks > clicks2)
    {MasterPower -= 1;
    SlavePower += 1;
    }
    else if(clicks < clicks2)
    {MasterPower += 1;
    SlavePower -= 1;
    }
    
    
    // average
    
  if (scale == 1){  
    D = (clicks *  2.8);
D2 = (clicks2 *  2.8); 


  }
  else if(scale == 2){
    D = (clicks *  0.028);
D2 = (clicks2 *  0.028); 
final_D = (D + D2) / 2;
  }
else if(scale == 3){
  D = (clicks *  0.000028);
D2 = (clicks2 *  0.000028); 
}
else if(scale == 4){
  D = (clicks * 2.958267300581088219756999471738e-18);
D2 = (clicks2 *  2.958267300581088219756999471738e-18);
}
    
   point1_angle_Hd_navigation = (90 - ( angle_move_base_Hd + point1_angle_Hd));
   point2_angle_Hd_navigation = (90 - ( angle_move_base_Hd + point2_angle_Hd));
   point3_angle_Hd_navigation = (90 - ( angle_move_base_Hd + point3_angle_Hd));
point1_angle_base_navigation = (180 - (point1_angle_Hd_navigation + point1_angle_Hd)) - point1_angle_base;
point2_angle_base_navigation = (180 - (point2_angle_Hd_navigation + point2_angle_Hd)) - point2_angle_base;
point3_angle_base_navigation = (180 - (point3_angle_Hd_navigation + point3_angle_Hd)) - point3_angle_base;


    
      base_distance_Hd_new = (base_distance_Hd - final_D);
    
    
     
    
base_p_point1 = (sin((point1_angle_base_navigation * ((22/7) / 180))) * point1_distance_base);
base_p_point2 = (sin((point2_angle_base_navigation * ((22/7) / 180))) * point2_distance_base);
base_p_point3 = (sin((point3_angle_base_navigation * ((22/7) / 180))) * point3_distance_base);


base_b_point1 =  ( sqrt(square (point1_distance_base) - square(base_p_point1)));
base_b_point2 =  ( sqrt(square (point2_distance_base) - square(base_p_point2)));
base_b_point3 =  ( sqrt(square (point3_distance_base) - square(base_p_point3)));


point1_b_Hd =(base_distance_Hd_new - base_b_point1);
point2_b_Hd =(base_distance_Hd_new - base_b_point2);
point3_b_Hd =(base_distance_Hd_new - base_b_point3);
point1_distance_robot =(sqrt (square(point1_b_Hd) + square(base_p_point1)));
point2_distance_robot =(sqrt (square(point2_b_Hd) + square(base_p_point2)));
point3_distance_robot =(sqrt (square(point3_b_Hd) + square(base_p_point3)));
Re1 = compareDIS(point1_distance_robot, point1_distance_base);
Re2 = compareDIS(point2_distance_robot, point2_distance_base);
Re3 = compareDIS(point3_distance_robot, point3_distance_base);
 if (Re1 == 1 || Re2 == 1 || Re3 == 1){
  analogWrite(Master1, 0);
  analogWrite(Master2, 0);
  analogWrite(Slave2, 0);
  analogWrite(Slave1, 0);   
  }
  }
  }
int compareDIS(float x, float y){
  int result;
  if (x > y){
    result = x - y;
  }
  else {
    result = y - x;
  }
  if (result > 0.01){
     finalResult = 0;
  }
  else{
    finalResult = 1;
  }
  return finalResult;
}



























































































































































































































  
  
 
    


   



