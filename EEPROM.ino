#include <EEPROM.h>

void setup() {
// put your setup code here, to run once:
Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
  Serial.println("Please enter a command");
} 

void loop() {
  // put your main code here, to run repeatedly:
  int value_in_addr = 0; // Value stored in the requested address
  char buff[15] = {0};
  int leng = 15;
  if (Serial.available() > 0) {
    Serial.readBytes(buff,leng);
  }
  //Case: Read
  if (buff[0] == 'r'){ 
    char addr[4] = {buff[5],buff[6],buff[7],buff[8]};
    int addrInt = atoi(addr);
    value_in_addr = EEPROM.read(addrInt);
    Serial.print("The value in the address ");
    Serial.print(addrInt);
    Serial.print(" is ");
    Serial.println(value_in_addr);
    delay(2000);
  } 
  //Case write
  if (buff[0] == 'w'){
    
     if(isDigit(buff[9]) and isDigit(buff[8]) and isDigit(buff[7]) and isDigit(buff[6])) { // Four digit address
       char addr[] = {buff[6],buff[7],buff[8],buff[9]};
       int addrInt = atoi(addr);

       char data[3] = {buff[11],buff[12],buff[13]};
       int dataInt = atoi(data);
       EEPROM.write(addrInt,dataInt);
       value_in_addr = EEPROM.read(addrInt);
       Serial.print("The value written to the address ");
       Serial.print(addrInt);
       Serial.print(" is ");
       Serial.println(value_in_addr);
       delay(1000);
       
       } else if (isDigit(buff[8]) and isDigit(buff[7]) and isDigit(buff[6])){ // Three digit address
        char addr[] = {buff[6],buff[7],buff[8],0};
        int addrInt = atoi(addr);

        char data[3] = {buff[10],buff[11],buff[12]};
        int dataInt = atoi(data);
        EEPROM.write(addrInt,dataInt);
        value_in_addr = EEPROM.read(addrInt);
        Serial.print("The value written to the address ");
        Serial.print(addrInt);
        Serial.print(" is ");
        Serial.println(value_in_addr);
        delay(1000);
     
     } else if (isDigit(buff[7])and isDigit(buff[6])){ // Two digit address
        char addr[] = {buff[6],buff[7],0};
        int addrInt = atoi(addr);
              
        char data[3] = {buff[9],buff[10],buff[11]};
        int dataInt = atoi(data);
        EEPROM.write(addrInt,dataInt);
        value_in_addr = EEPROM.read(addrInt);
        Serial.print("The value written to address ");
        Serial.print(addrInt);
        Serial.print(" is ");
        Serial.println(value_in_addr);
        delay(1000);
        
     } else if (isDigit(buff[6])){ // One digit address
        char addr[] = {buff[6],0};
        int addrInt = atoi(addr);
        
        char data[3] = {buff[8],buff[9],buff[10]};
        int dataInt = atoi(data);
        EEPROM.write(addrInt,dataInt);
        value_in_addr = EEPROM.read(addrInt);
        Serial.print("The value written to the address ");
        Serial.print(addrInt);
        Serial.print(" is ");
        Serial.println(value_in_addr);
        delay(1000);
     }      
  }   
}
