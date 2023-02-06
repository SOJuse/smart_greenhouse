void receivedCallback( uint32_t from, String &msg ) {
  //Serial.printf(msg.c_str(), "\n");
  JSONVar myObject = JSON.parse(msg.c_str());   //парсим полученные данные
  //записываем значения в переменные
  nodeNumber = myObject["node"];
  switch (nodeNumber) {
    case 1:
      temp1 = myObject["temp"];
      hum1 = myObject["hum"];
      ghum1 = myObject["ghum"];
      break;
    case 2:
      temp2 = myObject["temp"];
      hum2 = myObject["hum"];
      ghum2 = myObject["ghum"];
      break;
  }
  temp = (temp1 + temp2) / 2;
  hum = (hum1 + hum2) / 2;
  Serial.println(temp1);
  Serial.println(hum1);
  Serial.println(ghum1);
  Serial.println(temp2);
  Serial.println(hum2);
  Serial.println(ghum2);
  
  
  publishData();
}
void newConnectionCallback(uint32_t nodeId) {
  Serial.printf("New Connection, nodeId = %u\n", nodeId);
}

void disconnecting_mesh() {
  F = false;
  mesh.stop();
}

void connecting_mesh() {
  mesh.setDebugMsgTypes( ERROR | STARTUP );  // установите перед функцией init() чтобы выдавались приветственные сообщения
  mesh.init( MESH_PREFIX, MESH_PASSWORD, &userScheduler, MESH_PORT );
  mesh.onReceive(&receivedCallback);
  mesh.onNewConnection(&newConnectionCallback);
}
