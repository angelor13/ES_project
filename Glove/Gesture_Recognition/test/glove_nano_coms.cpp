#include <Arduino.h>
#include "Arduino_LSM9DS1.h"
#include "ArduinoBLE.h"
#include <Arduino_APDS9960.h>
#include <PDM.h>


const float accelerationThreshold = 2.5; // threshold of significant in G's
const int numSamples = 119;

int samplesRead = numSamples;

const char* Service_uuid = {"1809"};

BLEService mySoftGlove(Service_uuid);

BLEUnsignedIntCharacteristic mySoftGloveCharacteristic("2A1C", BLERead | BLENotify);

//  Soft Sensors Pins

#define RPolegar_Pin A0
#define RIndicator_Pin A1
#define RMedio_Pin A2
#define RAnelar_Pin A3
#define RMindinho_Pin A4


void setup() {

  pinMode(RPolegar_Pin,INPUT);
  pinMode(RIndicator_Pin,INPUT);
  pinMode(RMedio_Pin,INPUT);
  pinMode(RAnelar_Pin,INPUT);
  pinMode(RMindinho_Pin,INPUT);

  Serial.begin(9600);
  while (!Serial);

  if(!BLE.begin()){
    Serial.println("Starting BLE failed!");
    while(1);
  }
  Serial.println("Starting BLE!");

  BLE.setLocalName("mySoftGlove");              // Cria o nome do Service e sua aparencia

  BLE.setAdvertisedService(mySoftGlove);      // Cria serviço coomo foi criado

  mySoftGlove.addCharacteristic(mySoftGloveCharacteristic); //Adiciona so serviço a carateristica de comom queremos que sejam acedidos os recursos

  BLE.addService(mySoftGlove);      // Finaliza a criação do serviço

  BLE.advertise();

  // if (!IMU.begin()) {
  //   Serial.println("Failed to initialize IMU!");
  //   while (1);
  // }   


  // // print the header
  // Serial.println("aX,aY,aZ,gX,gY,gZ");
}
int i=0;

void loop() {

  // float aX, aY, aZ, gX, gY, gZ;

  // // wait for significant motion
  // while (samplesRead == numSamples) {
  //   if (IMU.accelerationAvailable()) {
  //     // read the acceleration data
  //     IMU.readAcceleration(aX, aY, aZ);

  //     // sum up the absolutes
  //     float aSum = fabs(aX) + fabs(aY) + fabs(aZ);

  //     // check if it's above the threshold
  //     if (aSum >= accelerationThreshold) {
  //       // reset the sample read count
  //       samplesRead = 0;
  //       break;
  //     }
  //   }
  // }

  // // check if the all the required samples have been read since
  // // the last time the significant motion was detected
  // while (samplesRead < numSamples) {
  //   // check if both new acceleration and gyroscope data is
  //   // available
  //   if (IMU.accelerationAvailable() && IMU.gyroscopeAvailable()) {
  //     // read the acceleration and gyroscope data
  //     IMU.readAcceleration(aX, aY, aZ);
  //     IMU.readGyroscope(gX, gY, gZ);

  //     samplesRead++;

  //     // print the data in CSV format
  //     Serial.print(aX, 3);
  //     Serial.print(',');
  //     Serial.print(aY, 3);
  //     Serial.print(',');
  //     Serial.print(aZ, 3);
  //     Serial.print(',');
  //     Serial.print(gX, 3);
  //     Serial.print(',');
  //     Serial.print(gY, 3);
  //     Serial.print(',');
  //     Serial.print(gZ, 3);
  //     Serial.println();

  //     if (samplesRead == numSamples) {
  //       // add an empty line if it's the last sample
  //       Serial.println();
  //     }
  //   }
  // 
      // Finaliza a criação do serviço
    BLE.addService(mySoftGlove);
    BLE.advertise();                 // Disponibiliza o serviço
    mySoftGloveCharacteristic.writeValue(i);
   // Serial.println(value);

    delay(50);
}
