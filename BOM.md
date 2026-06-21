# Bill of Materials (BOM) — Aerospace Cybersecurity Lab
**Version 1.3 | June 2026**

This document outlines the components required for the dual-radio FlatSat and Ground Station prototypes. All estimates are provided in Polish Złoty (PLN) for procurement via local partners like Satland or Elhurt EMS.

## PCB-1: FlatSat Node (Dual-Radio)

| Category | Key Components | Ref | Est. PLN |
| :--- | :--- | :--- | :--- |
| MCU | ATmega328P-PU (DIP-28) | U1 | 10.75 |
| RF 1 | HC-12 433MHz Transceiver | U2 | 15.05 |
| RF 2 | RFM95W (LoRa SX1276) | U3 | 32.25 |
| Sensor | DHT22 Temperature/Humidity | U4 | 12.90 |
| Crypto | ATECC608A-MAHDA (SOIC-8) | U5 | 5.16 |
| Power | AMS1117-3.3 + AMS1117-5.0 | U6, U7 | 2.58 |
| Connectors | USB-C, ISP, 2xSMA, GPIO, LiPo | J1-J6 | 17.20 |
| Control | Reset + Radio Selector DIP | SW1, SW2 | 2.80 |
| LEDs | Status (Power/TX/RX/Crypto/Alarm) | LED1-5 | 1.07 |
| Passives | Resistors (incl. 33Ω SPI), Capacitors | R1-R15 | 4.30 |
| Test Pts | 1Ω Shunt for ChipWhisperer | TP1, TP2 | 0.43 |
| **PCB Fab** | 2L FR4 ~100x80mm | PCB1 | 172.00 |
| **SUBTOTAL** | | | **~276.49** |

## PCB-2: Ground Station (RPi Carrier)

| Category | Key Components | Ref | Est. PLN |
| :--- | :--- | :--- | :--- |
| RF 1 | HC-12 433MHz Transceiver | U10 | 15.05 |
| RF 2 | RFM95W (LoRa SX1276) | U11 | 32.25 |
| USB-UART | CP2102 debug bridge | U12 | 7.74 |
| Level Shift | TXS0102 3.3V↔5V | U13 | 3.44 |
| Power | AMS1117-3.3 | U14 | 1.29 |
| Connectors | RPi, 2xSMA, 2xUSB, RJ45, FTDI | J10-J18 | 28.16 |
| Control | Shutdown + Radio Selector DIP | SW10, SW11 | 3.23 |
| LEDs | Status (Power/Boot/TX/RX/LoRa) | LED10-14 | 1.07 |
| Passives | Resistors (incl. 33Ω SPI), Capacitors | R10-R18 | 2.15 |
| **PCB Fab** | 2L FR4 ~120x90mm | PCB2 | 193.50 |
| **SUBTOTAL** | | | **~287.88** |

## Total Estimated Project Cost

*   **Materials Subtotal:** ~564.37 PLN
*   **Assembly (SMD+THT Est.):** ~430–645 PLN
*   **TOTAL ESTIMATED:** **~994–1,209 PLN**

---

## Engineering Notes
1. **Radio Configuration:** HC-12 on 2x8 headers; RFM95W soldered directly to PCB.
2. **Signal Integrity:** 33Ω resistors included on SPI lines for LoRa modules.
3. **Power:** 10µF + 100nF decoupling capacitors required near all RF power pins.
4. **Layout:** Maximize physical separation between HC-12 and RFM95W SMA connectors.
5. **Security:** Layout supports direct I2C access to ATECC608A for AES-CTR implementation.
