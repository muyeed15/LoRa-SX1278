/*  
 *   Transmitter side Code
 * 
  Module SX1278 // Arduino NANO   
    Vcc         ->   3.3V
    MISO        ->   D12
    MOSI        ->   D11     
    SLCK        ->   D13
    Nss         ->   D10 
    GND         ->   GND    
*/

#include <SPI.h>
#include <LoRa.h>

const unsigned long TX_INTERVAL = 100;
const char* MESSAGE = "Hi, Crafters!";

unsigned long lastTxTime = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("LoRa Sender");

  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
  LoRa.setTxPower(20);
}

void loop() {
  if (millis() - lastTxTime >= TX_INTERVAL) {
    lastTxTime = millis();
    
    LoRa.beginPacket();
    LoRa.write((const uint8_t*)MESSAGE, strlen(MESSAGE));
    if (LoRa.endPacket()) {
      Serial.println("Tx success");
    } else {
      Serial.println("Tx failed");
    }
  }
}