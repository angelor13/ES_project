#include <Arduino.h>
#include "Arduino_LSM9DS1.h"
#include "ArduinoBLE.h"
#include <Arduino_APDS9960.h>
#include <PDM.h>

const float accelerationThreshold = 2.5; // threshold of significant in G's
const int numSamples = 119;

int samplesRead = numSamples;

const char *Device_uuid = {"2A1C"};

const char *service_uuid = {"1809"};

String serviceName = "mySoftGlove";

BLEDevice peripheral;

BLECharacteristic myGlove_charateristic;

void setup()
{
  Serial.begin(9600);
  while (!Serial)
    ;

  if (!BLE.begin())
  {
    Serial.println("Starting BLE failed!");
    while (1);
  }
  Serial.println("Starting BLE!");

  BLE.scan();

}

void loop()
{

 peripheral = BLE.available();

 if (peripheral) {
    BLE.stopScan();
    Serial.print("Dispositivo encontrado: ");
    Serial.println(peripheral.localName());

    // Se o dispositivo encontrado tem o nome que estamos á procura, depois tenta se conectar
    if (peripheral.localName() == "mySoftGlove") {
      BLE.stopScan();  // Para a busca uma vez que encontramos o dispositivo
      
      Serial.println("Conectando ao mySoftGlove...");
      
      if (peripheral.connect()) {
        Serial.println("Conectado ao mySoftGlove!");

          if (peripheral.discoverAttributes()) {  // Descobrir todos os serviços e características
          Serial.println("Serviços encontrados:");
          
          // Imprimir todos os serviços encontrados
          for (int i = 0; i < peripheral.serviceCount(); i++) {
            BLEService service = peripheral.service(i);
            Serial.print("Service UUID: ");
            Serial.println(service.uuid());
          }
        } else {
          Serial.println("Nenhum serviço encontrado.");
          peripheral.disconnect();
        }

        // Descobre o serviço e a característica
        if (peripheral.discoverService(service_uuid)) {
          myGlove_charateristic = peripheral.characteristic(Device_uuid);

          if (myGlove_charateristic) {
            //myGlove_charateristic.subscribe();
            Serial.println("Característica de mySoftGlove encontrada!");
          } else {
            Serial.println("Falha ao encontrar a característica de mySoftGlove.");
            BLE.disconnect();
          }
        } 
      } else {
        Serial.println("Falha na conexão com o dispositivo.");
        BLE.disconnect();
      }
    }
  }
  
  // Se estiver conectado, tenta ler o valor da característica
  while ( peripheral.connected()) {
    if (myGlove_charateristic.read()  && myGlove_charateristic) {
      // Obtém o valor da temperatura
      int value = *myGlove_charateristic.value();
      Serial.print("mySoftGlove: ");
      Serial.println(value);



      // Do things here-...............................



    } else {
      Serial.println("Falha ao ler a característica.");
      BLE.disconnect();
    }
  }


  // Se o dispositivo se desconectar, volta a escanear
  if (peripheral && !peripheral.connected()) {
    Serial.println("Desconectado. Reiniciando busca...");
    BLE.scan();  // Reinicia a busca por dispositivos
  }

  BLE.scan();
  delay(50);
}
