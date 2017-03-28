
#include <Nextion.h>

/*************************************

  โปรเจค IV Monitor Version 1.0
  08/01/2017
  GreatODev.LTD Maker
  God & Top Maker

 *************************************/

#include <Nextion.h>

const int analogInPin = A0;  // Analog input pin that the potentiometer is attached to
const int analogOutPin = 9;  // Analog output pin that the LED is attached to

int sensorValue = 0;        // value read from the pot
int outputValue = 0;        // value output to the PWM (analog out)
unsigned int ntime = 0, otime = 0;
bool flag = 0;
float sumDrop = 0;

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  ntime = millis();
  otime = millis();
}

void loop() {
  // read the analog in value:
  sensorValue = analogRead(analogInPin);
  // map it to the range of the analog out:
  outputValue = map(sensorValue, 0, 1023, 0, 255);

  // print the results to the serial monitor:
  /*Serial.print("sensor = ");
    Serial.print(sensorValue);
    Serial.print("\t output = ");
    Serial.println(outputValue);
  */

  // funtion Math IV Monitor
  
  if ((sensorValue >= 600) && (flag == 0)) {    // อ่านค่า heart rate Sensor ถ้าได้ค่ามากกว่า 600 เร่มนับ
    flag = 1;                                   // เก็บเฉพาะค่าแรก
    sumDrop += 1.00;                            // นับจำนวน Drop
    float total = sumDrop * 0.05;               // sumDrop / Drop/ml
    unsigned int cal = millis() - otime;
    float drop = 3600000 / cal;
    float cc = drop / 20;
    otime = millis();
    Serial.print("rate : ");
    Serial.print(cc);
    Serial.print(" ml/h");
    Serial.print(", total: ");
    Serial.print(total);
    Serial.println(" ml");
    
    // Send Data to Nextion HMI
    /*
      String str = "t0.txt=\""+String(cc)+"\"";   //ส่งค่าแบบ Text 
      senddata(str);
      str = "t1.txt=\""+String(total)+"\"";
      senddata(str);
    */
  }
  if (sensorValue < 600) {
    flag = 0;
  }

  // wait 2 milliseconds before the next loop
  // for the analog-to-digital converter to settle
  // after the last reading:
  delay(2);
}

void senddata(String data) {
  Serial.print(data);
  Serial.write(0xff);
  Serial.write(0xff);
  Serial.write(0xff);
}


