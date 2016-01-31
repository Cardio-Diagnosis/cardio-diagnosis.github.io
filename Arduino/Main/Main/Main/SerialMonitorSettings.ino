int cal = 1.6;
boolean exer = false;
void serialOutput(boolean exercise){   
  exer = exercise;
 if (serialVisual == true){  
     arduinoSerialMonitorVisual('-', Signal);   
 } 
 else{
      sendDataToSerial('S', Signal);     
 }        
}

void serialOutputWhenBeatHappens(){    
 if (serialVisual == true){            
    Serial.print("{Heart-Beat Occured} ");  
    Serial.print("BPM: ");
    Serial.print(BPM/cal);
    Serial.print("  \n");
     if(BPM/cal > 100)
    {
      if(!exer)
      {
        for(int i = 0; i < 3; i++)
        Serial.print("V-TAC WARNING V-TAC \n");
      }
    }
 } else{
        sendDataToSerial('B',BPM);   
        sendDataToSerial('Q',IBI);   
 }   
}

void sendDataToSerial(char symbol, int data ){
    Serial.print(symbol);
    Serial.println(data);                
  }

void arduinoSerialMonitorVisual(char symbol, int data ){    
  const int sensorMin = 0;      
  const int sensorMax = 1024;    

  int sensorReading = data;
  int range = map(sensorReading, sensorMin, sensorMax, 0, 11);

  switch (range) {
  case 0:     
    Serial.println("");     
    break;
  case 1:   
    Serial.println("---");
    break;
  case 2:    
    Serial.println("------");
    break;
  case 3:    
    Serial.println("---------");
    break;
  case 4:   
    Serial.println("------------");
    break;
  case 5:   
    Serial.println("--------------|-");
    break;
  case 6:   
    Serial.println("--------------|---");
    break;
  case 7:   
    Serial.println("--------------|-------");
    break;
  case 8:  
    Serial.println("--------------|----------");
    break;
  case 9:    
    Serial.println("--------------|----------------");
    break;
  case 10:   
    Serial.println("--------------|-------------------");
    break;
  case 11:   
    Serial.println("--------------|-----------------------");
    break;
  } 
}



