//------------JSON------------

//получаем показания с датчиков
String getReadings () {
  JSONVar jsonReadings;
  jsonReadings["node"] = nodeNumber;
  jsonReadings["temp"] = 45.0;
  jsonReadings["hum"] = 12.0;
  //readings = JSON.stringify(jsonReadings);
  return JSON.stringify(jsonReadings);
}

//----------------------------
