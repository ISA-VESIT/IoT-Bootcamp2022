#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>
#include <BLE2902.h>

#define potPin 33 
int sensorRead = 0;
uint8_t value = 0;  

#define serviceID BLEUUID((uint16_t)0x1700)


BLECharacteristic customCharacteristic(
  BLEUUID((uint16_t)0x1A00), 
  BLECharacteristic::PROPERTY_READ | 
  BLECharacteristic::PROPERTY_NOTIFY
);


bool deviceConnected = false;
class ServerCallbacks: public BLEServerCallbacks {
    void onConnect(BLEServer* MyServer) {
      deviceConnected = true;
    };

    void onDisconnect(BLEServer* MyServer) {
      deviceConnected = false;
    }
};

void setup() {
  Serial.begin(9600);

  // Create and name the BLE Device
  BLEDevice::init("MyESP32");

  BLEServer *MyServer = BLEDevice::createServer();
  MyServer->setCallbacks(new ServerCallbacks());  // Set the function that handles Server Callbacks


  BLEService *customService = MyServer->createService(BLEUUID((uint16_t)0x1700)); //  A random ID has been selected

 
  customService->addCharacteristic(&customCharacteristic);  //customCharacteristic was defined above


  customCharacteristic.addDescriptor(new BLE2902());  //Add this line only if the characteristic has the Notify property

  
  MyServer->getAdvertising()->addServiceUUID(serviceID);

  // Start the service
  customService->start();

  // Start the Server/Advertising
  MyServer->getAdvertising()->start();

  Serial.println("Waiting for a Client to connect...");
}

void loop() {
  sensorRead = analogRead(potPin);  //read the value of the potentiometer
  value = map(sensorRead,0,4095,0,255); //change the value to a range of 0-255 so that it can fit in a single byte
  Serial.println(value);
  if (deviceConnected) {
    /* Set the value */
    customCharacteristic.setValue(&value,2);  
    customCharacteristic.notify();  // Notify the client of a change
  }
  delay(50);
}
