//Guilherme Silva Sanches     23/10/19
//Programa destinado ao teste de um modulo bluetooth AT-09 acendendo e apagando leds a partir do envio de dados seriais pelo celular,
// alem da notificação no monitor serial do app do celular após o pressionamento de botões.

#include <SoftwareSerial.h>
SoftwareSerial mySerial(2,3); // RX, TX
char dado_BLE=0; //Armazena o dado recebido do bluetooth
char dado_serial=0; //Armazena o dado recebido da serial
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
dado_BLE = mySerial.read(); //Faz a leitura do dado do celular
Serial.write(dado_BLE); //Apresenta no monitor serial
}
//Se o computador enviou algo...
if (Serial.available()) {
dado_serial = Serial.read(); //Faz a leitura do dado do computador
mySerial.write(dado_serial); //Apresenta no celular
}
//Se o celular enviou o caractere 'A', liga o led
if(dado_BLE == 'A'){
digitalWrite(4, HIGH);
}
//Se mandou 'B', desliga o LED
else if(dado_BLE == 'B'){
digitalWrite(4,LOW);
}
if(dado_BLE == 'C'){
digitalWrite(5, HIGH);
}
//Se mandou 'B', desliga o LED
else if(dado_BLE == 'D'){
digitalWrite(5,LOW);
}
if(dado_BLE == 'E'){
digitalWrite(6, HIGH);
}
//Se mandou 'B', desliga o LED
else if(dado_BLE == 'F'){
digitalWrite(6,LOW);
}
if(dado_BLE == 'G'){
digitalWrite(7, HIGH);
}
//Se mandou 'B', desliga o LED
else if(dado_BLE == 'H'){
digitalWrite(7,LOW);
}
//Se o botão da placa foi pressionado, envia uma frase para o celular.
if(digitalRead(A2)==0){
while(digitalRead(A2)==0);
mySerial.write("Botao 1 Pressionado!");
}
if(digitalRead(A3)==0){
while(digitalRead(A3)==0);
mySerial.write("Botao 2 Pressionado!");
}
dado_BLE = 0; //Limpa o dado recebido
}
