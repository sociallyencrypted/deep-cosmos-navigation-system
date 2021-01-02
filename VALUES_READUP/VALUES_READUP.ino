//#include <EEPROMex.h>
//#include <EEPROMVar.h>
#include<EEPROM.h>
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
getCode();
}

void loop() {
  // put your main code here, to run repeatedly:

}
void getCode()
{
  int a = 0.00;
int b = 0.00;
int c = 0.00;
int d = 0.00;
int e = 0.00;
int f = 0.00;
int g = 0.00;
int h = 0.00;
int i = 0.00;
int j = 0.00;
int k = 0.00;
int l = 0.00;
int m = 0.00;
          while( !(Serial.available()));
    String v1 = Serial.readStringUntil(':');
    Serial.read(); 
    // delay(200);
    String v2 = Serial.readStringUntil(':');
    Serial.read();
    // delay(200);
    String v3 = Serial.readStringUntil(':');
    Serial.read();
    // delay(200);
    String v4 = Serial.readStringUntil(':');
    Serial.read();
    // delay(200);
    String v5 = Serial.readStringUntil(':');
    Serial.read();
    // delay(200);
    String v6 = Serial.readStringUntil(':');
    Serial.read();
    // delay(200);
    String v7 = Serial.readStringUntil(':');
    Serial.read();
   // // delay(200);
    String v8 = Serial.readStringUntil(':');
    Serial.read();
   // // delay(200);
    String v9 = Serial.readStringUntil(':');
    Serial.read();
   // // delay(200);
    String v10 = Serial.readStringUntil(':');
    Serial.read();
   // // delay(200);
    String v11 = Serial.readStringUntil(':');
    Serial.read();
    // delay(200);
    String v12 = Serial.readStringUntil(':');
    Serial.read();
    // delay(200);
    String v13  = Serial.readStringUntil('|');
   Serial.read();
   // delay(200);
   a = v1.toInt();
   b = v2.toInt();
 c = v3.toInt();
   d = v4.toInt();
   e = v5.toInt();
   f = v6.toInt();
   g = v7.toInt();
h = v8.toInt();
i = v9.toInt();
j = v10.toInt();
k = v11.toInt();
l = v12.toInt();
m = v13.toInt();
    EEPROM.write(0, a);
    // delay(200);
    EEPROM.write(1, b);
    // delay(200);
    EEPROM.write(2, c);
    // delay(200);
    EEPROM.write(3, d);
    // delay(200);
    EEPROM.write(4, e);
    // delay(200);
    EEPROM.write(5, f);
    // delay(200);
    EEPROM.write(6, g);  
    // delay(200);
    EEPROM.write(7, h); 
    // delay(200);
     EEPROM.write(8, i);
     // delay(200);
    EEPROM.write(9, j);
    // delay(200);
    EEPROM.write(10, k);  
    // delay(200);
    EEPROM.write(11, l); 
    // delay(200);
     EEPROM.write(12, m); 
     // delay(200); 
  //  EEPROM.write(13, h); 
    for (int x = 0; x < 13; x++)
    {
      Serial.println(EEPROM.read(x));      
      // delay(200);                                                                            
    }
    
}



