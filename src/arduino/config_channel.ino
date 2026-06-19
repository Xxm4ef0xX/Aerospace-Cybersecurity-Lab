#include <SoftwareSerial.h>
SoftwareSerial radio(2, 3); // RX, TX

void setup() {
  Serial.begin(9600);
  radio.begin(9600);
  delay(1000);
  
  // Enviamos comando para cambiar a canal 20
  radio.print("AT+C020\r\n");
  Serial.println("Comando AT+C020 enviado");
}

void loop() {
  // Nada aquí, solo configuramos
}