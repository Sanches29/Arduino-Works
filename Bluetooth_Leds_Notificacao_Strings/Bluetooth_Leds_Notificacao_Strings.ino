//Guilherme Silva Sanches        23/10/19
// Teste executado em modulo bluetooth AT-09 com ativação de led a partir da escrita de strings no monitor serial do app do celular
// alem de leitura de estado de dois botões devolvendo uma string indicando o estado destes.
#include <SoftwareSerial.h>
SoftwareSerial mySerial(2,3); // RX, TX
String dado_BLE; //Armazena o dado recebido do bluetooth
String dado_serial; //Armazena o dado recebido da serial
void setup() {
Serial.begin(9600);
mySerial.begin(9600); //Ativa a serial do bluetooth
pinMode(4, OUTPUT);
pinMode(5, OUTPUT);
pinMode(6, OUTPUT);
pinMode(7, OUTPUT);

pinMode(A2, INPUT_PULLUP);
pinMode(A3, INPUT_PULLUP);
}
void loop() {
//Se o celular enviou algo...
if (mySerial.available()) {
//Faz a leitura da string enviada pelo celular até encontrar o caractere '.'
dado_BLE = mySerial.readStringUntil('.');
//Serial.println(dado_BLE); //Apresenta no monitor serial
Serial.write(dado_BLE[1]);
}
//Se o computador enviou algo...
if (Serial.available()) {
//Faz a leitura da string do computador até encontrar o caractere '.'
dado_serial = Serial.readStringUntil('.');
mySerial.println(dado_serial); //Apresenta no celular
}
//Protocolo: L = LED, 6 = Número do LED, 1 = Acende ou 0 = Apaga
if(dado_BLE[0] == 'L'){
if(dado_BLE[1] == '4'){
if(dado_BLE[2] == '0') digitalWrite(4, LOW);
if(dado_BLE[2] == '1') digitalWrite(4, HIGH);
}
if(dado_BLE[1] == '5'){
if(dado_BLE[2] == '0') digitalWrite(5, LOW);
if(dado_BLE[2] == '1') digitalWrite(5, HIGH);
}
if(dado_BLE[1] == '6'){
if(dado_BLE[2] == '0') digitalWrite(6, LOW);
if(dado_BLE[2] == '1') digitalWrite(6, HIGH);
}
if(dado_BLE[1] == '7'){
if(dado_BLE[2] == '0') digitalWrite(7, LOW);
if(dado_BLE[2] == '1') digitalWrite(7, HIGH);
}
}
if(dado_BLE[0] == 'B'){
if(dado_BLE[1] == '0') {
  if (digitalRead(A2) == 0) mySerial.write("Botao A2 pressionado");
  else if (digitalRead(A2) == 1) mySerial.write("Botao A2 solto");    
}
else if(dado_BLE[1] == '1'){
  if (digitalRead(A3) == 0) mySerial.write("Botao A3 pressionado");
   else if (digitalRead(A3) == 1) mySerial.write("Botao A3 solto"); 
}
}

dado_BLE = ' '; //Apaga a string
}
//Em C++ é possível comparar uma string diretamente pelo if:
//L = LED, 6 = Número do LED, 1 = Acende
//else if(dado_BLE == "L61"){
// digitalWrite(6, HIGH);
//}
//L = LED, 6 = Número do LED, 0 = Apaga
//else if(dado_BLE == "L60"){
// digitalWrite(6, LOW);
//}
//}
