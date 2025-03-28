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

  Module ACS712 // Arduino NANO
    Vcc         ->   5V
    GND         ->   GND
    OUT         ->   A0
*/

#include <SPI.h>
#include <LoRa.h>

const unsigned long SENSOR_INTERVAL = 300;
const unsigned long TX_INTERVAL = 300;

unsigned long lastSensorTime = 0;
unsigned long lastTxTime = 0;

float globalCurrent = 0.0;
float globalPower = 0.0;
float energyWh = 0.0;

void setup() {
  Serial.begin(9600);
  Serial.println("LoRa Sender with Energy Measurement");

  if (!LoRa.begin(433E6)) {
    Serial.println("Starting LoRa failed!");
    while (1);
  }
  LoRa.setTxPower(20);

  lastSensorTime = millis();
  lastTxTime = millis();
}

void loop() {
  unsigned long currentMillis = millis();
  
  if (currentMillis - lastSensorTime >= SENSOR_INTERVAL) {
    lastSensorTime = currentMillis;

    int adc = analogRead(A0);
    float voltageSensor = adc * 5.0 / 1023.0;  // Assumes a 5V reference for ADC conversion
    globalCurrent = (voltageSensor - 2.5) / 0.066;  // Assumes ACS712 output is centered at 2.5V (midpoint of 5V)

    if (abs(globalCurrent) < 0.05) {
      globalCurrent = 0.0;
    }
    
    globalPower = 5.0 * globalCurrent;  // Assumes a 5V load voltage for power calculation
    energyWh += globalPower * (SENSOR_INTERVAL / 3600000.0);
  }
  
  if (currentMillis - lastTxTime >= TX_INTERVAL) {
    lastTxTime = currentMillis;
    
    char currentStr[10], powerStr[10], energyStr[12];
    dtostrf(globalCurrent, 4, 2, currentStr);
    dtostrf(globalPower, 4, 2, powerStr);
    dtostrf(energyWh, 6, 4, energyStr);
    
    char message[50];
    sprintf(message, "Ampere:%s, Watt:%s, Watt-hour:%s", currentStr, powerStr, energyStr);
    
    LoRa.beginPacket();
    LoRa.print(message);
    if (LoRa.endPacket()) {
      Serial.print("Tx success: ");
      Serial.println(message);
    } else {
      Serial.println("Tx failed");
    }
  }
}
