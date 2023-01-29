//------------JSON------------

//получаем показания с датчиков
String getReadings () {
  JSONVar jsonReadings;
  jsonReadings["node"] = nodeNumber;
  jsonReadings["temp"] = 18.0;
  jsonReadings["hum"] = 54.0;
  //readings = JSON.stringify(jsonReadings);
  return JSON.stringify(jsonReadings);
}

//----------------------------
