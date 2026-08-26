# VCU_Battery

Acest repo conține codul pentru VCU-ul (Vehicle Control Unit) de baterie al mașinii noastre.

---

## Hardware

Acest ECU (Electronic Control Unit) este plasat în interiorul TSAC (Tractive System Accumulator Container) alături de:

* 2 x module BMS ADBMS2950B
* 1 x modul de măsurare HV și șunt de curent ADBMS6830B
* 1 x transceiver SPI la iso-SPI

---

## Funcționalități (Stadiul 2024-2025)

Începând cu sezonul 2024-2025, avem în stare de funcționare:

* Măsurarea tensiunii celulelor
* Detecție OW (Open Wire) pe celule
* Măsurarea pachetului HV
* Date despre curentul pachetului
* Semnal AMS (Accumulator Management System) în caz de defecțiune
* Comunicație cu un încărcător CAN

## Funcționalități (Stadiul 2025-2026)

S-au adaugat
* integrare termistori
* balansare celule (half-backed)
* adaugat librarie comunicatii

# K3 Legacy Firmware

LEGACY / NO MAINTENANCE

Target: K3 board

For future archaeological expeditions:

1. Clone repository
2. Checkout `main`
3. Build using the documented toolchain
4. Flash board
5. If it works, congratulations.
6. If it doesn't, you own it now.