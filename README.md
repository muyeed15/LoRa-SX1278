# LoRa-SX1278

This repository provides streamlined Arduino Nano sketches to interface with the SX1278 (XL1278-SMT) LoRa transceiver. The examples use SPI communication with configurable frequency, bandwidth, and spreading factor settings.

## Code Files

- **LoRa_SX1278_Transmitter.ino**: Configures and sends data using the SX1278 module.
- **LoRa_SX1278_Receiver.ino**: Receives data from the SX1278 module and outputs it to the Serial Monitor.
- **LoRa_SX1278_Current_Transmitter.ino**: Integrates current measurement using an ACS712 sensor. This sketch reads the current on A0, calculates power and energy (Watt-hours), and transmits the data via LoRa.

## License

This project is licensed under the [MIT License](LICENSE).

## Contributing

Contributions are welcome. Please submit issues or pull requests to help improve functionality or resolve bugs.
