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

  return JSON.stringify(jsonReadings);
}

//----------------------------

String readSensor() 
{
  digitalWrite(sensorPower, HIGH);  // Включить датчик
  delay(10);                        // Дать время питанию установиться
  int val = analogRead(sensorPin);  // Прочитать аналоговое значение от датчика
  digitalWrite(sensorPower, LOW);   // Выключить датчик
  if (val>850) val=0;
  if (val>400 && val<850) val=1;
  if (val<400) val=2;
  Serial.println(val);
  return val;                       // Вернуть аналоговое значение влажности
}
