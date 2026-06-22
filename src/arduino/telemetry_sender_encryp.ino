#include <SoftwareSerial.h>
#include <DHT.h>
#include "AESLib.h" // Asegúrate de haber instalado esta librería

SoftwareSerial radio(2, 3); // RX, TX
DHT dht(4, DHT22);

// Llave de 16 bytes (DEBE ser igual en el Arduino y en la Raspberry Pi)
byte key[] = {your key here};
AESLib aesLib;

void setup() {
  radio.begin(9600);
  Serial.begin(9600);
  dht.begin();
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  
  // 1. Empaquetar los datos en un buffer de 16 bytes
  // Usamos un buffer de 16 bytes porque es el tamaño de bloque de AES
  byte data[16];
  memset(data, 0, 16); // Limpiamos el buffer
  
  // Copiamos los floats al buffer. 
  // Nota: Esto es eficiente porque pasamos los bytes directos.
  memcpy(data, &h, sizeof(float));
  memcpy(data + 4, &t, sizeof(float));
  
  // 2. Cifrar el buffer
  // El buffer se cifra "in-place" (el original se reemplaza por el cifrado)
  // Usamos encrypt(buffer, longitud, buffer_salida, llave, bits, iv)
byte iv[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}; // IV básico
aesLib.encrypt(data, 16, data, key, 128, iv);
  
  // 3. Envío al HC-12 (Radio)
  // Ahora enviamos bytes, no texto. Serial.write es clave aquí.
  radio.write(data, 16);

  // 4. Feedback en el monitor serie (para debugging)
  Serial.println("Paquete cifrado enviado por radio.");
  
  delay(5000);
}