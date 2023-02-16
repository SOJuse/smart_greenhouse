//------------JSON------------

//получаем показания с датчиков
String getReadings () {
  JSONVar jsonReadings;
  jsonReadings["node"] = nodeNumber;
  jsonReadings["temp"] = 70.0;
  jsonReadings["hum"] = 71.0;
  //readings = JSON.stringify(jsonReadings);
  return JSON.stringify(jsonReadings);
}

//----------------------------
