/*
 * bms_cosa.h
 *
 *  Created on: 29 apr. 2025
 *      Author: cosaa
 */
#pragma once
#include "Mcu.h"
#ifndef BMS_COSA_H_
#define BMS_COSA_H_
#define BATTERY_CELLS 24
#define NUMARUL_DE_MONITOARE 2
#define NUMARUL_DE_SUNTURI 1
#define MARELE_DELAY 4000 //stabil cu minim 4000 //30000 mergea binex
#define CURENT_MAX 600000 //mA =>600A
#define UNDERVOLTAGE_CELL 350000 //*100mV =>3.5V pentru moment
#define TENSIUNE_MAX 10100 //101V
#define TENSIUNE_MIN 6000 //60V
#define OVERVOLTAGE_CELL 423000 //4.23V pentru moment
#define CURENT_STUPID 1000000  //valoare imposibila pentru a semnifica eroare de coms
#define TENSIUNE_STUPID 1000000 //valoare imposibila pentru a semnifica eroare de coms
#define CELULA_STUPID 500000 //valoare imposibila pentru a semnifica eroare de coms

struct biemese
{
	int packCurrent;
	int packVoltage;
	int cellVoltage[BATTERY_CELLS];
	bool flag;
	uint8 stateBMS[NUMARUL_DE_MONITOARE];
	uint8 stateSHUNT;
};


uint16 pec10_calc(bool rx_cmd, int len, uint8 *data);
uint16 Pec15_Calc
(
	uint8 len, /*!< Number of bytes that will be used to calculate a PEC */
	uint8 *data /*!< Array of data that will be used to calculate  a PEC */
);


void BmsInit(void);
void BmsTest(void);
void parametriiADC(void);
void parametriiADCB(void);
int BmsGetPackCurrent(void);
int BmsGetPackVoltage(void);

void transmisie(void);

void transmisieCMD(void);
void transmisieRD48(void);


void populeazaCMD(char MSB,char LSB);

void flushTX(void);

void SRST(void);
void RDSID(void);
void RDCFGA(void);
void RDCFGB(void);
void CLRFLG(void);
void ADCV(void);
void readBieMieSe(void);
void readBieMieSeOW(void);
void sendAllUart(void);
void sendAMS(void);
void sendOW(void);
void sendErori(void);


int getCelula(int index);
int getCurent(void);
int getVoltagePachet(void);
int CFGAok(void);
void bmsInit(void);
void BmsReadID(void);
void sendEroareUnitate(int index);
void clearStates(void);
void readShuntOW(void);
int BmsGetHighestCellVoltage(void);




#endif /* BMS_COSA_H_ */
