//Guilherme Silva Sanches      16/10/2019

//  Teste de escrita e leitura na EEPROM do Arduino com utilizaçao da bibliteca EEPROMANything.h, possibilitando
//gravar informaçõs maiores de 1byte, dividindo-as em mais de uma alocação de memória.
#include <EEPROM.h>
#include "EEPROMAnything.h"

int a = 1500;
int b = 0;
float c = 15.3;
float d = 0;
bool e = true;
bool f = 0; 
char g = 'c';
char h = 0;
char i [] = "String comum";
char j [13];
void setup()
{
  Serial.begin(9600);
     
     
     EEPROM_writeAnything(0, a); //write a to memory and then updates eeprom address
     EEPROM_readAnything(0, b);
     //int tem size 2 bytes
     EEPROM_writeAnything(2, c); //write a to memory and then updates eeprom address
     EEPROM_readAnything(2, d);
     //float tem size 4 bytes
     EEPROM_writeAnything(6, e); //write a to memory and then updates eeprom address
     EEPROM_readAnything(6, f);
     //bool tem size 1 byte
     EEPROM_writeAnything(7, g); //write a to memory and then updates eeprom address
     EEPROM_readAnything(7, h);
     //char tem size 1 byte
     EEPROM_writeAnything(8, i); //write a to memory and then updates eeprom address
     EEPROM_readAnything(8, j);
     //string tem size de acordo com o numero de chars, que equivalem a 1 byte. Lembrando que toda string começa com /0, ou seja
     //    se declarada uma string que possui 12 chars, esta possui 13 na verdade por causa do /0.


   
}

void loop()
{
     Serial.println(a);
     Serial.println(b);
     Serial.println(c);
     Serial.println(d);
     Serial.println(e);
     Serial.println(f);
     Serial.println(g);
     Serial.println(h);
     Serial.println(i);
     Serial.println(j);
     delay(5000);
     
}
