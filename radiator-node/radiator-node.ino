/*
  NodeManager is intended to take care on your behalf of all those common tasks a MySensors node has to accomplish, speeding up the development cycle of your projects.

  NodeManager includes the following main components:
  - Sleep manager: allows managing automatically the complexity behind battery-powered sensors spending most of their time sleeping
  - Power manager: allows powering on your sensors only while the node is awake
  - Battery manager: provides common functionalities to read and report the battery level
  - Remote configuration: allows configuring remotely the node without the need to have physical access to it
  - Built-in personalities: for the most common sensors, provide embedded code so to allow their configuration with a single line

  Documentation available on: https://github.com/mysensors/NodeManager
*/


// load user settings
#include "config.h"
// include supporting libraries
#ifdef MY_GATEWAY_ESP8266
#include <ESP8266WiFi.h>
#endif
// load MySensors library
#include <MySensors.h>
// load NodeManager library
#include "NodeManager.h"

#define TEMPERATURE_SENSOR_PIN 4

#define WINDOW1_PIN 2
#define WINDOW2_PIN 3

// create a NodeManager instance
NodeManager nodeManager;

// before
void before() {
  // setup the serial port baud rate
  Serial.begin(MY_BAUD_RATE);
  /*
     Register below your sensors
  */
  nodeManager.setSleep(SLEEP,10,SECONDS); 

  // first two ids used for temp sensors are 10 and 11
  nodeManager.registerSensor(SENSOR_DS18B20, TEMPERATURE_SENSOR_PIN);
  
  nodeManager.registerSensor(SENSOR_DOOR, WINDOW1_PIN,6);
  nodeManager.registerSensor(SENSOR_DOOR, WINDOW2_PIN,7);
  
  /*
     Register above your sensors
  */
  nodeManager.before();
}

// presentation
void presentation() {
  // call NodeManager presentation routine
  nodeManager.presentation();
}

// setup
void setup() {
  // call NodeManager setup routine
  nodeManager.setup();
}

// loop
void loop() {
  // call NodeManager loop routine
  nodeManager.loop();

}

// receive
void receive(const MyMessage &message) {
  // call NodeManager receive routine
  nodeManager.receive(message);
}

// receiveTime
void receiveTime(unsigned long ts) {
  // call NodeManager receiveTime routine
  nodeManager.receiveTime(ts);
}


