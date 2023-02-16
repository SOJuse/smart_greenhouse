//запускается при подключение шлюза к серверу
void onConnectionEstablished() {
  Serial.println("connected");
}

void publishData() {
 disconnecting_mesh();
/*
 //  delay(500);
  Serial.print("Connecting to ");
  Serial.println(ssid);

  //Connect to the WiFi
  WiFi.begin(ssid, wifi_password);

  //wait until the connection has been confirmed before continuing
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  //Debugging-Output the IP Address of the ESP32
  Serial.println("WiFi connected");
  Serial.println("IP Address");
  Serial.println(WiFi.localIP());
  */
 //Запускаем WIFI
  WIFIinit();

  
  //Connect to MQTT Broker
  //client.connect returns a boolean value to let us know if the connection was successful
  //if the connection is failing, make sure you are using the correct MQTT Username and Password
  if (client.connect(clientID, mqtt_username, mqtt_password)) {
    Serial.println("Connected to MQTT Broker");
  }
  else {
    Serial.println("Connection to MQTT Broker failed...");
  }

  if (client.publish("base/state/temperature", String(temp).c_str())) { // Загрузка первого значения температуры.
    Serial.println("Message sent 1");
  }
  else {
    Serial.println("Message failed to send. Reconnecting to MQTT Broker and trying again");
    client.connect(clientID, mqtt_username, mqtt_password);
    delay(10);
    client.publish("base/state/temperature", String(temp).c_str());


    
  }
  if (client.publish("base/state/humidity", String(hum).c_str())) { // Загрузка первого значения влажности.
    Serial.println("Message sent 3");
  }
  else {
    Serial.println("Message failed to send. Reconnecting to MQTT Broker and trying again");
    client.connect(clientID, mqtt_username, mqtt_password);
    delay(10);
    client.publish("base/state/humidity", String(hum).c_str());
  }



  
  if (client.publish("base/state/ground-humidity-1", String(s_ghum1).c_str())) { // Загрузка первого значения влажности почвы.
    Serial.println("Message sent 5");
  }
  else {
    Serial.println("Message failed to send. Reconnecting to MQTT Broker and trying again");
    client.connect(clientID, mqtt_username, mqtt_password);
    delay(10);
    client.publish("base/state/ground-humidity-1", String(s_ghum1).c_str());
  }




  if (client.publish("base/state/ground-humidity-2", String(s_ghum2).c_str())) { // Загрузка первого значения влажности почвы.
    Serial.println("Message sent 6");
  }
  else {
    Serial.println("Message failed to send. Reconnecting to MQTT Broker and trying again");
    client.connect(clientID, mqtt_username, mqtt_password);
    delay(10);
    client.publish("base/state/ground-humidity-2", String(s_ghum2).c_str());
  }
  
  
  
  
  
  if (client.publish("base/state/water-lvl", String(water).c_str())) { // Загрузка второго значения влажности почвы.
    Serial.println("Message sent 7");
  }
  else {
    Serial.println("Message failed to send. Reconnecting to MQTT Broker and trying again");
    client.connect(clientID, mqtt_username, mqtt_password);
    delay(10);
    client.publish("base/state/water-lvl", String(water).c_str());
  }


  
  client.disconnect();
  WiFi.mode(WIFI_OFF);
//  Serial.println(WiFi.status());
  delay(500);
  
 connecting_mesh();
}
