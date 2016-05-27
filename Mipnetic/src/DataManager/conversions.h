/*
 * conversions.h
 *
 *  Created on: 7 de may. de 2016
 *      Author: gabriel
 */

#ifndef SRC_DATAMANAGER_CONVERSIONS_H_
#define SRC_DATAMANAGER_CONVERSIONS_H_


#include<iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>     /* atoi */
#include <sstream>
#include <string>
#include <stack> //stack
#include <math.h>

#include "../ConsSys/Consts.h"
using namespace std;



class conversions: public Consts {
public:
	conversions();
	char* hexaConvBina(char pHexadechar[]);

	int parsearCharAInt(char pCadenaEntero[]);

	long binarioDecimal(char pBinario[]);

	int comparaCadenayPuntero(char pCadenaEntero[], char* pCadenaptr);

	char * tomarBits(char pCadena[], int pInicio, int pFinal, int pTama);

	long exponencia(int pnumero, int pExpo);

	int safeLongToInt(long l);

	char* decimalABinario(long pNumero);

	char * voltearChar(char pChart[]);

	virtual ~conversions();
};

#endif /* SRC_DATAMANAGER_CONVERSIONS_H_ */
