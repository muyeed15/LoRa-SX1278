/* 
 *  Receiver Side Code
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

#define MAX_PACKET_SIZE 64
char receivedMessage[MAX_PACKET_SIZE];
uint8_t msgIndex = 0;

void setup() {
  Serial.begin(9600);
  Serial.println("LoRa Receiver");

  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
  LoRa.setSignalBandwidth(125E3);
}

void loop() {
  int packetSize = LoRa.parsePacket();
  
  if (packetSize) {
    msgIndex = 0;
    memset(receivedMessage, 0, MAX_PACKET_SIZE);
    
    while (LoRa.available() && msgIndex < MAX_PACKET_SIZE-1) {
      receivedMessage[msgIndex++] = (char)LoRa.read();
    }
    
    Serial.print("RSSI:");
    Serial.print(LoRa.packetRssi());
    Serial.print(" dBm | Message: ");
    Serial.println(receivedMessage);
  }
}