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

#define RPolegar_Pin 4
#define RIndicator_Pin 5
#define RMedio_Pin 30
#define RAnelar_Pin 29
#define RMindinho_Pin 31


void setup() {
  Serial.begin(9600);
  while (!Serial);

  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }

  // print the header
  Serial.println("aX,aY,aZ,gX,gY,gZ");
}

void loop() {
  float aX, aY, aZ, gX, gY, gZ;

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

  // check if the all the required samples have been read since
  // the last time the significant motion was detected

    // check if both new acceleration and gyroscope data is
    // available
    if (IMU.accelerationAvailable() && IMU.gyroscopeAvailable()) {
      // read the acceleration and gyroscope data
      IMU.readAcceleration(aX, aY, aZ);
      IMU.readGyroscope(gX, gY, gZ);

      samplesRead++;

      //print the data in CSV format
      Serial.print("Acelerometro: aX: ");
      Serial.print(aX, 3);
      Serial.print("   aY: ");
      Serial.print(aY, 3);
      Serial.print("   aZ: ");
      Serial.println(aZ, 3);
      Serial.print("Giroscopio: gX: ");
      Serial.print(gX, 3);
      Serial.print("   gY: ");
      Serial.print(gY, 3);
      Serial.print("   gZ: ");
      Serial.println(gZ, 3);
    }
    delay(50);
}
