/*
 * archmm.h
 *
 *  Created on: 28 de abr. de 2016
 *      Author: gabriel
 */

#ifndef SRC_MIPSMARS_ARCHMM_H_
#define SRC_MIPSMARS_ARCHMM_H_

#include<iostream>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <iostream>
#include <fstream>
#include <sys/types.h>
#include <dirent.h>


#include "../ConsSys/Consts.h"
#include "../DataManager/conversions.h"

//estructura para instanciar el compilador
struct arch_mm: public Consts{
	int * pMemoria; // puntero memoria
	int * pMemoriaDatos; //puntero a memoria de pila
	int * pMemoriaRegistros; //puntero a memoria de registros

	int pTamaMemoria; // tamano de memoria

	char *pBinarioPathtext; //direccion del codigo objetotex
	char *pBinarioPathdata; //direccion del codigo objetodata

};
/**
 * @breif Clase encargada de toda la logica para el manejo de las instrucciones y datos de la compilacion obtenida desde Mars Mips
 */

class archmm : public Consts {
	typedef void (archmm::*punteroFuncion)(arch_mm, char*); //definicion para el tipo de puntero a una funcion, este formato resulta ser general para las funciones

private:
	arch_mm pMipsObject; //estructura para objeto simulador de compilador
	punteroFuncion pFuncionesPorLecturaR[_pArreglosFunciones]; //Matriz para punteros a funciones R para los bits
	punteroFuncion pFuncionesPorLecturaI[_pArreglosFunciones]; //Matriz para punteros a funciones I para los bits
	punteroFuncion pFuncionesPorLecturaJ[_pArreglosFunciones]; //Matriz para punteros a funciones J para los bits
	punteroFuncion pFuncionesPorLecturaSYSCALLS[_pArreglosFunciones]; //Matriz para punteros a funciones Syscall para los bits
	int * pMemoriaGeneral = (int *) calloc(1, _pTamanoMemoriaMipsConsts); // puntero memoria
	int * pMemoriaDatos = (int *)calloc(1, _pTamanoMemoriaDatosConsts); //puntero a memoria de pila
	int * pMemoriaRegistrosGeneral = (int *)calloc(1, (_pTamanoMemoriaRegistrosConsts*(_pCantidadDeRegistrosDatosConsts+3))); //puntero a memoria de registros

	static int pThreadFlag; //entero que lleva el orden de bandera del hilo

public:
	int pPC; //entero que lleva el orden de las instrucciones
	int pLO;
	int pHI;

	int pNumeroDeInstrucciones; //entero de control de la cantidad de instrucciones por procesar


	archmm();
	void ingresarLogica(int pPCcode);
	void aumentarPC();
	void setearPC();
	void putInPC(int pValor);

	void leerFicheroCompi(char pnameArchive[], char pTipo[]);
	char * leerFicheroEsp(char pnameArchive[], int line);
	void pasarApuntero(int  * pMemoria, long pPasar, int pPasarBus);

	void subirTextaMemoria(string pLine, int plineNumber, int flag, int * pMemoria);

	int * tomarDeMemoria(int * pMemoria, int pLineaPPC);



	void pushPila();
	void popPila();
	void cargarRegistrosText();
	////////FUNCIONES PARA TRADUCCION/////////////////
	void ADD(arch_mm pMips, char pCode[]); //suma
	void SUB(arch_mm pMips, char pCode[]); //resta
	void MULT(arch_mm pMips, char pCode[]); //multiplicacion
	void ADDI(arch_mm pMips, char pCode[]); // add inmediato con overflow
	void LW(arch_mm pMips, char pCode[]);
	void SW(arch_mm pMips, char pCode[]);
	void LUI(arch_mm pMips, char pCode[]);
	void ADDIU(arch_mm pMips, char pCode[]);
	void ORI(arch_mm pMips, char pCode[]);
	void ADDU(arch_mm pMips, char pCode[]); //suma
	void MFLO(arch_mm pMips, char pCode[]);
	void DIV(arch_mm pMips, char pCode[]);
	void MFHI(arch_mm pMips, char pCode[]);
	void BEQ(arch_mm pMips, char pCode[]);
	void SRL(arch_mm pMips, char pCode[]);
	void SLL(arch_mm pMips, char pCode[]);
	void OR(arch_mm pMips, char pCode[]);
	void ANDI(arch_mm pMips, char pCode[]);
	void SLTI(arch_mm pMips, char pCode[]);
	void BNE(arch_mm pMips, char pCode[]);
	void BGEZ(arch_mm pMips, char pCode[]);
	void SB(arch_mm pMips, char pCode[]);
	void J(arch_mm pMips, char pCode[]);
	void BGTZ(arch_mm pMips, char pCode[]);

	void SYSCALL12(arch_mm pMips, char pCode[]); //SystemCall
	void SYSCALL13(arch_mm pMips, char pCode[]); //SystemCall
	void SYSCALL15(arch_mm pMips, char pCode[]); //SystemCall
	void SYSCALL4(arch_mm pMips, char pCode[]); //SystemCall
	void SYSCALL1(arch_mm pMips, char pCode[]); //SystemCall
	void SYSCALL16(arch_mm pMips, char pCode[]); //SystemCall
	/////////////////////////
	virtual ~archmm();
};


#endif /* SRC_MIPSMARS_ARCHMM_H_ */
