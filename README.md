# LoRa-SX1278

This repository provides streamlined Arduino Nano sketches to interface with the SX1278 (XL1278-SMT) LoRa transceiver. The examples use SPI communication with configurable frequency, bandwidth, and spreading factor settings.

## Code Files

- **LoRa_SX1278_Transmitter.ino**: Configures and sends data using the SX1278 module.
- **LoRa_SX1278_Receiver.ino**: Receives data from the SX1278 module and outputs it to the Serial Monitor.
- **LoRa_SX1278_DC_5V_Current_Transmitter.ino**: Integrates DC 5V current measurement using an ACS712 sensor. This sketch reads the current on A0, calculates power and energy (Watt-hours), and transmits the data via LoRa.

## Figures

### LoRa Transceiver

A setup showcasing the LoRa SX1278 module connected via SPI for wireless communication.

![LoRa Transceiver](https://github.com/user-attachments/assets/f03d1620-78d2-4801-a89d-d29faf3297c5)

### LoRa Current Meter

This setup integrates the ACS712 current sensor with the LoRa SX1278 module, enabling real-time transmission of power and energy consumption data.

![LoRa Current Meter](https://github.com/user-attachments/assets/1e3c7c61-0969-4067-b147-ff041a24b758)

## License

This project is licensed under the [MIT License](LICENSE).

## Contributing

Contributions are welcome. Please submit issues or pull requests to help improve functionality or resolve bugs.
