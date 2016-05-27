/*
 * Constants.h
 *
 *  Created on: 27 de abr. de 2016
 *      Author: gabriel
 */

#ifndef SRC_CONSSYS_CONSTS_H_
#define SRC_CONSSYS_CONSTS_H_

/**
 * Clase que mantiene todas las constantes del proyecto, de aqui se heredan a las demas clases
 */

class Consts {

public:

	int _pTamanoMemoriaMipsConsts = 64000000; // memoria para manejo de variables entre mips y c++
	int _pTamanoMemoriaDatosConsts = 62000000; //tamaño de memoria para calloc stack
	int _pTamanoMemoriaHeapConsts = 2000000; //tamaño de memoria para calloc heap
	int _pCantidadDeRegistrosDatosConsts = 1024; // numero de registros para mips
	int _pTamanoMemoriaRegistrosConsts = 4; // tamaño de los registros
	char *_pRutaCodigosMipsConsts = "/home/gabriel/git/MIPSnetic/src/ObjetosMips/"; // ruta de los binarios de mips
	int _pinitialCounterConsts = 0; //contador inicial para procesos
	const int _pOFFSETDatos = -8192; // offset de memoria de datos
	const int _pPCplusConsts = 1; // aumentos en PC
	const int _pBusConsts = 1; // cantidad de bits de bus, son 32 pero aqui no se considera el 0 por ser arreglo de caracteres, por lo tanto se suma uno
	const int _pBusArrayConsts = 31;
	const static int _pArreglosFunciones = 60;
	const int rsi = 6;// Numero de bits inicial de la posicion dato guardado
	const int rsf = 10;// Numero de bits final de la posicion dato guardado
	const int rti = 11;// Numero de bits inicial de la posicion temporal
	const int rtf = 15;// Numero de bits final de la posicion temporal
	const int rdi = 16;// Numero de bits inicial de la posicion d
	const int rdf = 20;// Numero de bits final de la posicion d
	const int sai = 21;//Numero de bits inicial de la posicion sa
	const int saf = 25;//Numero de bits final de la posicion sa
	const int offseti = 16;// Numero de bits inicial del valor del inmediato
	const int offsetf = 31;// Numero de bits final del valor del inmediato
	const int _pLOConst = 34; //posicion de lo
	const int _pHIConst = 35; //posicion de hi
};

#endif /* SRC_CONSSYS_CONSTS_H_ */
