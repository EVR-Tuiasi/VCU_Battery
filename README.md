# VCU_Battery

This repo contains the code for the Battery VCU of our car.
This ECU is placed inside the TSAC alongside
  2 ADBMS2950B BMS modules
  1 ADBMS6830B HV measuring and current shunt
  1 SPI to iso-SPI transceiver

As of the 2024-2025 we have in working order
  Cell voltage measurement
  OW detection on the cells
  HV packet measurement
  Pack current data
  AMS signal in case of failure
  Communication with a CAN charger
