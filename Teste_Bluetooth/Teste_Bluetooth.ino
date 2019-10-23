//Guilherme Silva Sanches       23/10/29
//Programa destinado ao teste de um módulo bluetooth AT-09, com simples envios de comandos AT e configurações a partir destes.


//ESTE MODULO É UM AT-09
//Nome configurado: gui
//BaudRate: 9600
//Modo: peripherical (ROLE = 0)
#include <SoftwareSerial.h>

SoftwareSerial mySerial(4,5);

void setup()
{
  mySerial.begin(9600);               // the GPRS baud rate   
  Serial.begin(9600);                 // the GPRS baud rate   
}

void loop()
{
  if (mySerial.available())
    Serial.write(mySerial.read());
  if (Serial.available())
    mySerial.write(Serial.read()); 

}
