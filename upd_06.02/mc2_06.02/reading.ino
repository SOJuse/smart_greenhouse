//------------JSON------------

//получаем показания с датчиков
String getReadings () {
  JSONVar jsonReadings;
  jsonReadings["node"] = nodeNumber;
  sensors_event_t humidity, temp;
  aht.getEvent(&humidity, &temp);
  jsonReadings["temp"] = temp.temperature;
  jsonReadings["hum"] = humidity.relative_humidity;
  jsonReadings["ghum"] = readSensor();

  /*Serial.print("Temperature: ");
  Serial.print(temp.temperature);
  Serial.println("*C");
  Serial.print("Humidity: ");
  Serial.print(humidity.relative_humidity);
  Serial.println("%rH"); */

 
  return JSON.stringify(jsonReadings);
}

//----------------------------

int readSensor() 
{
  digitalWrite(sensorPower, HIGH);  // Включить датчик
  delay(10);                        // Дать время питанию установиться
  int val = analogRead(sensorPin);  // Прочитать аналоговое значение от датчика
  digitalWrite(sensorPower, LOW);   // Выключить датчик
  return val;                       // Вернуть аналоговое значение влажности
}
