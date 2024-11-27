#include <Arduino.h>
#include "Arduino_LSM9DS1.h"
#include "ArduinoBLE.h"
#include <Arduino_APDS9960.h>
#include <PDM.h>


#define Voice_Mode 0
#define Finger_Mode 1


bool Glove_Mode= Finger_Mode;


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


bool static Polegar_state=0, Indicador_state=0, Medio_state=0, Anelar_state=0,Mindinho_state=0;


void switch_mode(){                 // Switch Glove Mode
  if(Glove_Mode==Finger_Mode){
    Glove_Mode=Voice_Mode;
  }else{
    Glove_Mode=Finger_Mode;
  }
}


void update_states(int Polegar, int Indicador, int Medio, int Anelar, int Mindinho){      // Update each finger state
  if (Polegar<80){
    Polegar_state=1;
  }else{
    Polegar_state=0;
  }

  if (Indicador<30){
    Indicador_state=1;
  }else{
    Indicador_state=0;
  }
  
  if (Medio<40){
    Medio_state=1;
  }else{
    Medio_state=0;
  }

  if (Anelar<40){
    Anelar_state=1;
  }else{
    Anelar_state=0;
  }

  if (Mindinho<80){
    Mindinho_state=1;
  }else{
    Mindinho_state=0;
  }

  Serial.print("Finger State: Polegar: "); 
  Serial.print(Polegar_state);
  Serial.print("   Indicador: ");
  Serial.print(Indicador_state);
  Serial.print("   Medio: ");
  Serial.print(Medio_state);
  Serial.print("  Anelar: ");
  Serial.print(Anelar_state);
  Serial.print("   Midinho: ");
  Serial.println(Mindinho_state);

}

void send_info(bool Polegar_state,bool Indicador_state,bool Medio_state,bool Anelar_state, bool Mindinho_state, int gX, int gY, int gZ){
    // BLE.addService(mySoftGlove);
    // BLE.advertise();                 // Disponibiliza o serviço
    // mySoftGloveCharacteristic.writeValue(cenas);
}




void codify_moves(bool Polegar_state,bool Indicador_state,bool Medio_state,bool Anelar_state, bool Mindinho_state, double aX, double aY, double aZ){

    if (Polegar_state == 1 && Indicador_state == 0 && Medio_state == 0 && Anelar_state == 1 && Mindinho_state == 1 && aX>=0.800){
        Serial.println(" ");
        Serial.println(" ");
        Serial.println(" ");
        Serial.println("Frente");
        Serial.println(" ");
        Serial.println(" ");
        Serial.println(" ");
    }else  if (Polegar_state == 0 && Indicador_state == 1 && Medio_state == 1 && Anelar_state == 1 && Mindinho_state == 1 && aZ<=-0.800){
        Serial.println(" ");
        Serial.println(" ");
        Serial.println(" ");
        Serial.println("Direita");
        Serial.println(" ");
        Serial.println(" ");
        Serial.println(" ");
    }else  if (Polegar_state == 0 && Indicador_state == 1 && Medio_state == 1 && Anelar_state == 1 && Mindinho_state == 1 && aZ>=0.800){
        Serial.println(" ");
        Serial.println(" ");
        Serial.println(" ");
        Serial.println("Esquerda");
        Serial.println(" ");
        Serial.println(" ");
        Serial.println(" ");
    }else  if (Polegar_state == 0 && Indicador_state == 1 && Medio_state==1 && Anelar_state==1 && Mindinho_state == 1 && aY>=0.800){
        Serial.println(" ");
        Serial.println(" ");
        Serial.println(" ");
        Serial.println("Tras");
        Serial.println(" ");
        Serial.println(" ");
        Serial.println(" ");
    }else  if (Polegar_state ==0 && Indicador_state == 1 && Medio_state == 1 && Anelar_state==1 && Mindinho_state == 1 &&  aX>=0.800){
        Serial.println(" ");
        Serial.println(" ");
        Serial.println(" ");
        Serial.println("Cima");
        Serial.println(" ");
        Serial.println(" ");
        Serial.println(" ");
    }
    else  if (Polegar_state == 0 && Indicador_state ==1 && Medio_state==1 && Anelar_state==1 && Mindinho_state == 1 &&  aX<=-0.800){
        Serial.println(" ");
        Serial.println(" ");
        Serial.println(" ");
        Serial.println("Baixo");
        Serial.println(" ");
        Serial.println(" ");
        Serial.println(" ");
    }else  if (Polegar_state == 1 && Indicador_state ==1 && Medio_state==1 && Anelar_state==1 && Mindinho_state ==1){
        Serial.println(" ");
        Serial.println(" ");
        Serial.println(" ");
        Serial.println("Parar");
        Serial.println(" ");
        Serial.println(" ");
        Serial.println(" ");
    }
    else{
        Serial.println(" ");
        Serial.println(" ");
        Serial.println(" ");
    }
}







void setup() {

pinMode(RPolegar_Pin,INPUT);
pinMode(RIndicator_Pin,INPUT);
pinMode(RMedio_Pin,INPUT);
pinMode(RAnelar_Pin,INPUT);
pinMode(RMindinho_Pin,INPUT);

  Serial.begin(9600);
  while (!Serial);

  if (!IMU.begin()) {
    Serial.println("Failed to initialize IMU!");
    while (1);
  }

// if(!BLE.begin()){
//     Serial.println("Starting BLE failed!");
//     while(1);
//   }
//   Serial.println("Starting BLE!");

//   BLE.setLocalName("mySoftGlove");              // Cria o nome do Service e sua aparencia

//   BLE.setAdvertisedService(mySoftGlove);      // Cria serviço coomo foi criado

//   mySoftGlove.addCharacteristic(mySoftGloveCharacteristic); //Adiciona so serviço a carateristica de comom queremos que sejam acedidos os recursos

//   BLE.addService(mySoftGlove);      // Finaliza a criação do serviço

//   BLE.advertise();

}

void loop() {

if(Glove_Mode == Finger_Mode){

int RPolegar = analogRead(RPolegar_Pin);
int RIndicator = analogRead(RIndicator_Pin);
int RMedio = analogRead(RMedio_Pin);
int RAnelar = analogRead(RAnelar_Pin);
int RMindinho = analogRead(RMindinho_Pin);


// Serial.print("Dedos: Polegar: "); 
// Serial.print(RPolegar);
// Serial.print("   Indicador: ");
// Serial.print(RIndicator);
// Serial.print("   Medio: ");
// Serial.print(RMedio);
// Serial.print("  Anelar: ");
// Serial.print(RAnelar);
// Serial.print("   Midinho: ");
// Serial.println(RMindinho);

update_states(RPolegar,RIndicator,RMedio,RAnelar,RMindinho);


float aX, aY, aZ, gX, gY, gZ;

  if (IMU.accelerationAvailable() && IMU.gyroscopeAvailable()) {
      // read the acceleration and gyroscope data
      IMU.readAcceleration(aX, aY, aZ);
      IMU.readGyroscope(gX, gY, gZ);

      // samplesRead++;

      //print the data in CSV format
      // Serial.print("Acelerometro: aX: ");
      // Serial.print(aX, 3);
      // Serial.print("   aY: ");
      // Serial.print(aY, 3);
      // Serial.print("   aZ: ");
      // Serial.println(aZ, 3);

      codify_moves(Polegar_state, Indicador_state, Medio_state, Anelar_state, Mindinho_state, aX,aY, aZ);

    }
  }
  
  delay(150);

}
