//запускается при подключение шлюза к серверу
void onConnectionEstablished() {
  Serial.println("connected");
}

void publishData() {
 disconnecting_mesh();
 //Запускаем WIFI
  WIFIinit();

// ************************ ЧТЕНИЕ ************************

    // Чтение значений переменных из сервиса
    status = mypanel.readUpdate();
    // Если статус равен константе OK...
    if (status == OK) {
        // Выводим текст в последовательный порт
        Serial.println("------- Read OK -------");
        // Записываем считанный из сервиса значения в переменные
        long io_Angle_Door = mypanel.readInt(VarName_Angle_Door);   // целочисленная переменна
        Serial.println((String)"io_Angle_Door = "+io_Angle_Door);
        long io_Door_Up = mypanel.readInt(VarName_Door_Up);   // целочисленная переменна
        Serial.println((String)"io_Door_Up = "+io_Door_Up);
        long io_Door_Down = mypanel.readInt(VarName_Door_Down);   // целочисленная переменна
        Serial.println((String)"io_Door_Down = "+io_Door_Down);
        
    } 

    // ************************ ЗАПИСЬ ************************
    
    // Записываем  значение в переменную для отпраки в сервис
    mypanel.write(VarName_Temperature, 12.345);   // Записали значение 1.2345
    mypanel.write(VarName_Humidity, 123.45);   // Записали значение 1.2345
    mypanel.write(VarName_Water_Level, 1234.5);   // Записали значение 1.2345
    mypanel.write(VarName_Ground_Humidity_1, "start");  // Записали слово "start"
    mypanel.write(VarName_Ground_Humidity_2, "start");  // Записали слово "start"
    
    // Отправляем переменные из контроллера в сервис
    status = mypanel.writeUpdate();
    // Если статус равен константе OK...
    if (status == OK) {
        // Выводим текст в последовательный порт
        Serial.println("------- Write OK -------");
    }

 WiFi.mode(WIFI_OFF);
//  Serial.println(WiFi.status());
  delay(500);
  
 connecting_mesh();
}
