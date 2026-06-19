#include <SoftwareSerial.h>
#include <DHT.h>

SoftwareSerial radio(2, 3); // RX, TX
DHT dht(4, DHT22);

void setup() {
  radio.begin(9600);
  Serial.begin(9600);
    dht.begin();
}

void loop() {
  // ... dentro de tu loop() ...
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  
  // 1. Envío al HC-12 (Radio)
  radio.print("H:");
  radio.print(h);
  radio.print(",T:");
  radio.println(t);

  // 2. Envío al Monitor Serie (USB para que lo veas tú)
  Serial.print("Enviando por radio: ");
  Serial.print("H:");
  Serial.print(h);
  Serial.print(",T:");
  Serial.println(t);
  
  delay(5000);
}