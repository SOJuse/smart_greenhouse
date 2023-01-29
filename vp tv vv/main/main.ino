//контроллер №1

#include <ESP8266WiFi.h>
#include "painlessMesh.h"
#include <Arduino_JSON.h>

//*********ПЕРЕМЕННЫЕ*********

//--------PAINLESSMESH--------

#define   MESH_PREFIX     "teplitsa"   //логин нашей сети
#define   MESH_PASSWORD   "teplitsa"   //пароль
#define   MESH_PORT       5555   //порт по дефолту 5555
Scheduler userScheduler;   // для контроля
painlessMesh  mesh;   //обозначаем нашу библиотеку как mesh (для удобства)
void sendMessage() ;   //задаем пустышку для коректной работы task
Task taskSendMessage( TASK_SECOND * 5 , TASK_FOREVER, &sendMessage );   //указываем задание
int nodeNumber = 2; //указываем номер ардуинки

//----------------------------

void setup() {
  Serial.begin(115200);
  mesh.setDebugMsgTypes(ERROR | STARTUP );  // установите перед функцией init() чтобы выдавались приветственные сообщения
  mesh.init( MESH_PREFIX, MESH_PASSWORD, &userScheduler, MESH_PORT );

  //назначаем функциям свои события

  mesh.onReceive(&receivedCallback);
  mesh.onNewConnection(&newConnectionCallback);

  userScheduler.addTask(taskSendMessage);   //добавляем задание в обработчик
  taskSendMessage.enable();   //включаем задание
}

void loop() {
  // она также запустит пользовательский планировщик
  mesh.update();
}
