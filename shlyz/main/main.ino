//шлюз

//#include <iocontrol.h>
#include <ESP8266WiFi.h>
#include <Arduino_JSON.h>
#include "painlessMesh.h"
#include "EspMQTTClient.h"
#include <PubSubClient.h>
//#include <WiFi.h>

//*********ПЕРЕМЕННЫЕ*********

boolean F = true;

//-----------RIGHTECHIO-----------

//#define PUB_DELAY (5 * 1000) /* 5 seconds */

//--------------------------------
//--------PAINLESSMESH--------

#define   MESH_PREFIX     "teplitsa"   //логин нашей сети
#define   MESH_PASSWORD   "teplitsa"   //пароль
#define   MESH_PORT       5555   //порт по дефолту 5555
Scheduler userScheduler;   // для контроля
painlessMesh  mesh;   //обозначаем нашу библиотеку как mesh (для удобства)
int nodeNumber; //указываем номер ардуинки
double temp;
double hum;

//----------------------------

//------------WIFI------------

//const char* ssid = "iPhone (Grisha)";
//const char* wifi_password = "12345678";
const char* ssid = "GDR";
const char* wifi_password = "chika16!";
#define   STATION_SSID     "GDR"
#define   STATION_PASSWORD "chika16!"

WiFiClient wifiClient;

//----------------------------

/*//----------IOCONTROL----------

  const char* myPanelName = "Teplitsa2023";   //название панели
  //переменные
  int status;
  const char* VarName_temp = "temp";
  const char* VarName_hum = "hum";
  WiFiClient client;   // Создаём объект клиента класса EthernetClient
  //передаем в конструктр название панели и клиента
  iocontrol mypanel(myPanelName, client);

  //-----------------------------*/

/*//-----------RIGHTECHIO-----------

  //подлкючаем к вайфай и сети комара
  EspMQTTClient client(
  "iPhone (Grisha)",
  "12345678",
  "dev.rightech.io",  // MQTT Broker server ip
  "111",   // Can be omitted if not needed
  "111",   // Can be omitted if not needed
  "mqtt-andrey"      // Client name that uniquely identify your device
  );

  //--------------------------------*/
//------MQTT_CLIENT-----------

const char* mqtt_server = "dev.rightech.io";
const char* mqtt_username = "hihi23"; //MQTT username
const char* mqtt_password = "hihi23"; //MQTT password
const char* clientID = "mqtt-andrey";
PubSubClient client(mqtt_server, 1883, wifiClient);

//---------------------------

void setup() {
  Serial.begin(115200);
 //--------------MESH--------------

  mesh.setDebugMsgTypes( ERROR | STARTUP | CONNECTION );  // установите перед функцией init() чтобы выдавались приветственные сообщения
  mesh.init( MESH_PREFIX, MESH_PASSWORD, &userScheduler, MESH_PORT );

  //назначаем функциям свои события
  mesh.onReceive(&receivedCallback);
  mesh.onNewConnection(&newConnectionCallback);
  
  
}

void loop() {
  mesh.update(); //для коректной работы mesha


}
