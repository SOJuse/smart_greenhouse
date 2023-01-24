void receivedCallback( uint32_t from, String &msg ) {
  Serial.printf(msg.c_str(), "\n");
  JSONVar myObject = JSON.parse(msg.c_str());   //парсим полученные данные
  //записываем значения в переменные
  int node = myObject["node"];
  double temp = myObject["temp"];
  double hum = myObject["hum"];
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
