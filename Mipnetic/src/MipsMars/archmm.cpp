/*
 * archmm.cpp
 *
 *  Created on: 1 de may. de 2016
 *      Author: gabriel
 */

#include "archmm.h"

/**
 * @breif Constructor de la clase archmm
 */
archmm::archmm() {
	// TODO Auto-generated constructor stub

	///////////CREACION DE PUNTEROS A FUNCIONES PARA ARREGLO DE///////////////////////////////

	////////////////////////////Punteros
	archmm::punteroFuncion ptrADD= &archmm::ADD;
	archmm::punteroFuncion ptrADDU= &archmm::ADDU;
	archmm::punteroFuncion ptrMULT= &archmm::MULT;
	archmm::punteroFuncion ptrMFLO= &archmm::MFLO;
	archmm::punteroFuncion ptrMFHI= &archmm::MFHI;
	archmm::punteroFuncion ptrDIV= &archmm::DIV;
	archmm::punteroFuncion ptrSRL= &archmm::SRL;
	archmm::punteroFuncion ptrSLL= &archmm::SLL;
	archmm::punteroFuncion ptrOR= &archmm::OR;

	////////////////////////////Punteros I
	archmm::punteroFuncion ptrADDI= &archmm::ADDI;
	archmm::punteroFuncion ptrlw= &archmm::LW;
	archmm::punteroFuncion ptrlui= &archmm::LUI;
	archmm::punteroFuncion ptraddiu= &archmm::ADDIU;
	archmm::punteroFuncion ptrori= &archmm::ORI;
	archmm::punteroFuncion ptrsw= &archmm::SW;
	archmm::punteroFuncion ptrANDI= &archmm::ANDI;
	archmm::punteroFuncion ptrBEQ= &archmm::BEQ;
	archmm::punteroFuncion ptrSLTI= &archmm::SLTI;
	archmm::punteroFuncion ptrBNE= &archmm::BNE;
	archmm::punteroFuncion ptrBGEZ= &archmm::BGEZ;
	archmm::punteroFuncion ptrSB= &archmm::SB;
	archmm::punteroFuncion ptrBGTZ= &archmm::BGTZ;


	////////////////////////////Punteros J
	archmm::punteroFuncion ptrJ= &archmm::J;

	////////////////////////////Punteros sys
	archmm::punteroFuncion ptrsys12= &archmm::SYSCALL12;
	archmm::punteroFuncion ptrsys13= &archmm::SYSCALL13;
	archmm::punteroFuncion ptrsys15= &archmm::SYSCALL15;
	archmm::punteroFuncion ptrsys4= &archmm::SYSCALL4;
	archmm::punteroFuncion ptrsys1= &archmm::SYSCALL1;
	archmm::punteroFuncion ptrsys16= &archmm::SYSCALL16;
	//////////////////////////////////////////////////////////////////////////////
	//AQUI SE AGREGAN LOS PUNTEROS A SU RESPECTIVO ARREGLO//

	///////LOS R
	this->pFuncionesPorLecturaR[32]= ptrADD;
	this->pFuncionesPorLecturaR[33]= ptrADDU;
	this->pFuncionesPorLecturaR[24]= ptrMULT;
	this->pFuncionesPorLecturaR[18]= ptrMFLO;
	this->pFuncionesPorLecturaR[16]= ptrMFHI;
	this->pFuncionesPorLecturaR[26]= ptrDIV;
	this->pFuncionesPorLecturaR[0]= ptrSLL;
	this->pFuncionesPorLecturaR[2]= ptrSRL;
	this->pFuncionesPorLecturaR[37]= ptrOR;
	///////LOS I
	this->pFuncionesPorLecturaI[8]= ptrADDI;
	this->pFuncionesPorLecturaI[35]= ptrlw;
	this->pFuncionesPorLecturaI[15]= ptrlui;
	this->pFuncionesPorLecturaI[9]= ptraddiu;
	this->pFuncionesPorLecturaI[13]= ptrori;
	this->pFuncionesPorLecturaI[43]= ptrsw;
	this->pFuncionesPorLecturaI[44]= ptrsw;

	this->pFuncionesPorLecturaI[12]= ptrANDI;
	this->pFuncionesPorLecturaI[4]= ptrBEQ;
	this->pFuncionesPorLecturaI[10]= ptrSLTI;
	this->pFuncionesPorLecturaI[5]= ptrBNE;
	this->pFuncionesPorLecturaI[1]= ptrBGEZ;
	this->pFuncionesPorLecturaI[40]= ptrSB;
	this->pFuncionesPorLecturaI[7]= ptrBGTZ;

	///////LOS J
	this->pFuncionesPorLecturaJ[2]= ptrJ;

	///////Los Syscall
	this->pFuncionesPorLecturaR[12]= ptrsys12;
	this->pFuncionesPorLecturaSYSCALLS[13]= ptrsys13;
	this->pFuncionesPorLecturaSYSCALLS[26]= ptrsys13;
	this->pFuncionesPorLecturaSYSCALLS[15]= ptrsys15;
	this->pFuncionesPorLecturaSYSCALLS[4]= ptrsys4;
	this->pFuncionesPorLecturaSYSCALLS[1]= ptrsys1;
	this->pFuncionesPorLecturaSYSCALLS[16]= ptrsys16;
	///////////



	//this->pFuncionesPorLectura[2]= ptrLog;
	//this->pFuncionesPorLectura[2]= ptrLog;
	//this->pFuncionesPorLectura[2]= ptrLog;

	/////////////////////////////////////////////////
	pPC =_pinitialCounterConsts; //se coloca el PC en valor inicial 0
	pLO = _pLOConst; //posicion de lo
	pHI = _pHIConst; //posicion de hi
	pNumeroDeInstrucciones = _pinitialCounterConsts; // se setea el valor de la cantidad de instrucciones a 0
	pMipsObject.pMemoria = pMemoriaGeneral; // se le asigna el valor del puntero de memoria general a nuestro objeto de mips
	pMipsObject.pMemoriaRegistros = pMemoriaRegistrosGeneral; // se le asigna el valor del puntero de memoria de regitros a nuestro objeto de mips
	pMipsObject.pMemoriaDatos = pMemoriaDatos; // se le asigna el valor del puntero de memoria de pila a nuestro objeto de mips
	pMipsObject.pTamaMemoria = _pTamanoMemoriaMipsConsts; //se le da el tamano de la memoria

}

/**
 * @brief Logica asociada a los manejos de codigos del archivo objeto, se encarga de recuperar las instrucciones desde el archivo
 * @param char pnameArchive[] Corresponde a la direccion del archivo que se desea procesar
 * @param char pTipo Se encarga de especificar el tipo de archivo que esta procesando
 */
char * archmm::leerFicheroEsp(char pnameArchive[], int pline) {

	ifstream myfile(pnameArchive, std::ifstream::in); //objeto para el stream
	if (myfile.is_open()){
		string s; //string temporal para guardar lo recuperado
		int i = _pinitialCounterConsts; // entero para llevar el numero de linea leida

		while(getline(myfile,s)){


			if (i==pline){
				conversions c; //clase de conversiones
				char* p = new char[_pBusArrayConsts];
				//char p[_pBusArrayConsts]; //char temporal para el parseo
				memset(p,0,sizeof(p)); //seteo de la memoria en 0
				strcpy(p, s.c_str()); //copia en un arreglo de char el string
				//cout<<"ESTOY AQUI "<<p<<endl;
				return p;

			}else{
				i++;
			}
		}
		return "No esta";
		cout << "listo leido"<< endl;
		myfile.close(); //se cierra el archivo
	}
	else {
		cout << "No se pudo abrir el archivo: "<< pnameArchive<<endl; //catch para aviso de error al abrir archivo
		return "No abre";
	}
}

/**
 * @brief Logica asociada a los manejos de codigos del archivo objeto, se encarga de recuperar las instrucciones desde el archivo
 * @param char pnameArchive[] Corresponde a la direccion del archivo que se desea procesar
 * @param char pTipo Se encarga de especificar el tipo de archivo que esta procesando
 */
void archmm::leerFicheroCompi(char pnameArchive[], char pTipo[]) {
	ifstream myfile(pnameArchive, std::ifstream::in); //objeto para el stream
	if (myfile.is_open()){
		string s; //string temporal para guardar lo recuperado
		int i = _pinitialCounterConsts; // entero para llevar el numero de linea leida
		while(getline(myfile,s)){
			//cout <<"Leido desde fichero: "<< s << "\n";
			//cout <<"Numero de linea: "<< i << "\n";

			if (strcmp(pTipo, "DATA")){ //revisa que tipo de archivo va a procesar
				subirTextaMemoria(s,i,0, pMemoriaGeneral); ///se manda a la funcion para q procese lo q se debe hacer
				i++; //aumento de numero de instruccion
			}else{
				subirTextaMemoria(s,i,0, pMemoriaDatos); ///se manda a la funcion para q procese lo q se debe hacer
				i++; //aumento de numero de instruccion
			}
		}
		cout << "listo leido"<< endl;
		myfile.close(); //se cierra el archivo
		if (strcmp(pTipo, "DATA")){ //revisa que tipo de archivo va a procesar
			subirTextaMemoria(s,i,1, pMemoriaGeneral); ///se manda a la funcion para q procese lo q se debe hacer
		}else{
			subirTextaMemoria(s,i,1, pMemoriaDatos); ///se manda a la funcion para q procese lo q se debe hacer
		}
	}
	else {
		cout << "No se pudo abrir el archivo: "<< pnameArchive<<endl; //catch para aviso de error al abrir archivo
	}
}

/**
 * @brief Logica asociada a la subida de los valores de cada instruccion que ingresa para la memoria
 * @param string pLine String al cual se desea procesar y colocar en char a la memoria
 * @param int plineNumber Numero de linea en la que va leyendo desde el archivo
 * @param int pflag Bandera que decide si se termina de cargar a memoria o no
 * @param char * pMemoria Corresponde al puntero donde se desea colocar los caracteres
 * @return Es un void
 */
void archmm::subirTextaMemoria(string pLine, int plineNumber, int pflag, int * pMemoria){
	conversions c; //clase de conversiones
	char p[_pBusArrayConsts]; //char temporal para el parseo
	memset(p,0,sizeof(p)); //seteo de la memoria en 0

	if (pflag == 0){ //revisa si ya se termina de
		strcpy(p, pLine.c_str()); //copia en un arreglo de char el string
		long * guardar = new long; //int para pasar a guardar
		memset(guardar,0,sizeof(guardar)); //eteo de la memoria en 0

		*guardar = c.binarioDecimal(c.hexaConvBina(p)); //parseo de los caracteres leidos al numero
		//cout <<"EL DECIMAL PUTO ES EN MOMENTANEO: "<<*guardar<<endl;
		pasarApuntero(pMemoria, *guardar, plineNumber);
	}else{
		if (pMemoria == pMemoriaGeneral){ //revisa a que puntero debe subir los datos
			pNumeroDeInstrucciones = plineNumber; // asigna segun la cantidad de lineas el valor a la cantidad de instruccioines para el control de las mismas
			ingresarLogica(pPC);
		}else{

			//char pPat[]="/home/gabriel/git/ObjetosMips/CongruencialMixtoText"; //se debe cambiar por la direccion
			char pPat[]="/home/acacia/workspace/textt"; //se debe cambiar por la direccion

			leerFicheroCompi(pPat, "TEXTO"); //se procede a cargar las instrucciones
		}
	}
}

/**
 * @brief Se encarha de asignar los valores a determinados espacios en una porcion de memoria
 * @param int  * pMemoria Corresponde al puntero donde se desea colocar los caracteres
 * @param long pPasar Cadena de caracteres que se desean subir a la memoria
 * @param int pPasarBus Entero que lleva el numero de instruccion
 * @return Es un void
 */
void archmm::pasarApuntero(int  * pMemoria, long pPasar, int pPasarBus){

	cout <<"SE ESTA PASANDO A LA MEMORIA "<<pPasar<<endl;

	(*(pMemoria +(pPasarBus*(_pBusConsts)))) = pPasar; //aqui se asigna los valores

	cout <<"CUANDO SE RECUPERA :   "<<(*(pMemoria+(pPasarBus*(_pBusConsts))))<<endl;
}


/**
 * @brief Esta funcion se encarga recuperar desde un punto a otroo de memoria los caracteres guardados
 * @param int * pMemoria Puntero al que se desea recuperar informaacion
 * @param pLineaPC Entero que lleva el numero de linea de la cual se esta procesando desde el fichero
 * @return Retorna un puntero a caracter de lo que se obtuvo desde la memoria
 */

int * archmm::tomarDeMemoria(int * pMemoria, int pLineaPC){
	int * returptr = (pMemoria+(pLineaPC)); //asigna el valor de la memoria

	cout<<"ESTO ES LO QUE SE ENCUENTRA AL PEDIR DE MEMORIA: "<<*returptr<<"  EN LA POS: "<<pLineaPC<<" DE: "<<pMemoria<<endl;


	return returptr;//devuelve memoria
}




/**
 * @brief Este se encarga de desarrollar la logica de parseo de las instrucciones y decidir a que funcione de mips corresponden
 * @param int pPCcode Entero que lleva la linea o instruccion en la que se esta parseando
 * @return Es un void
 */
void archmm::ingresarLogica(int pPCcode){
	if (pPCcode<(pNumeroDeInstrucciones)){
		cout<<"LA LINEA DE CODIGO: "<<pPCcode<<endl;
		conversions c; //clase de conversiones
		char *lecturaBitsPrecisosOP = new char[6]; //cadena para los bits especificos por recoger de OP

		char *lecturaBitsFuncion = new char[6]; // cadena para los bits especificos por recoger de funcion
		char *pCodigoEnProceso = new char[_pBusArrayConsts]; // cadena para la recuperacion de la instruccion
		int * ptrCode; //puntero para dato

		memset(lecturaBitsPrecisosOP,0,sizeof(lecturaBitsPrecisosOP)); //seteo memoria a 0
		memset(lecturaBitsFuncion,0,sizeof(lecturaBitsFuncion)); //seteo memoria a 0
		memset(pCodigoEnProceso,0,sizeof(pCodigoEnProceso)); //seteo memoria a 0



		ptrCode = tomarDeMemoria(pMemoriaGeneral, pPCcode); //asigno el valor en memoria
		long este;

		if (((*ptrCode)<0)){

			cout<<"RUN.........................................................................."<<endl;

			char * est =leerFicheroEsp("/home/acacia/workspace/textt", pPCcode);
			est = c.hexaConvBina(est);
			pCodigoEnProceso = est;


		}else{
			este = (long)(*ptrCode);
			pCodigoEnProceso = c.decimalABinario(este);
		}
		//long este = (long) abs(*ptrCode);

		//cout<<"CODIGO QUE SE PROCESA EN EL MOMENTO: "<<pCodigoEnProceso<<endl;
		//cout <<"DESDE EL BINARIO PARSEADO::::   " <<este<<endl;

		lecturaBitsPrecisosOP = c.tomarBits(pCodigoEnProceso, 0, 5, 5); //recuperacion de los caracteres del OP

		//cout <<"DESDE EL BINARIO PARSEADO EL CODIGO EN BINARIO::   " <<pCodigoEnProceso<<endl;
		//cout <<"AQUI ESTA EL TIPO DE OP:   "<<lecturaBitsPrecisosOP<<endl;

		if ((c.comparaCadenayPuntero("000000", lecturaBitsPrecisosOP))){ //AQUI ENTRAN LOS TIPO R
			//cout<<"TIPO R"<<endl;
			lecturaBitsFuncion = c.tomarBits(pCodigoEnProceso, 26,31, 6); //bits de identificacion para funcion
			int numeroFuncion = c.binarioDecimal(lecturaBitsFuncion); //numero de funcion en arreglo
			archmm::punteroFuncion ptrLogic= this->pFuncionesPorLecturaR[numeroFuncion]; //crea puntero para la funcion extraida de la matriz tipo R
			(this->*ptrLogic)(this->pMipsObject, pCodigoEnProceso); //Llama a la funcion con el puntero pasando el objeto de mips

		}else if((c.comparaCadenayPuntero("001000", lecturaBitsPrecisosOP))|(c.comparaCadenayPuntero("100011", lecturaBitsPrecisosOP))|(c.comparaCadenayPuntero("001111", lecturaBitsPrecisosOP))|(c.comparaCadenayPuntero("001101", lecturaBitsPrecisosOP))|(c.comparaCadenayPuntero("001001", lecturaBitsPrecisosOP))|(c.comparaCadenayPuntero("101011", lecturaBitsPrecisosOP))|(c.comparaCadenayPuntero("101100", lecturaBitsPrecisosOP))|(c.comparaCadenayPuntero("001100", lecturaBitsPrecisosOP))|(c.comparaCadenayPuntero("000100", lecturaBitsPrecisosOP))|(c.comparaCadenayPuntero("001010", lecturaBitsPrecisosOP))|(c.comparaCadenayPuntero("000101", lecturaBitsPrecisosOP))|(c.comparaCadenayPuntero("000001", lecturaBitsPrecisosOP))|(c.comparaCadenayPuntero("101000", lecturaBitsPrecisosOP))|(c.comparaCadenayPuntero("000111", lecturaBitsPrecisosOP))){ //AQUI ENTRAN LOS TIPO I
			//cout <<"TIPO I"<<endl;
			int numeroFuncion = c.binarioDecimal(lecturaBitsPrecisosOP); //numero de funcion en arreglo

			cout <<numeroFuncion<<endl;

			archmm::punteroFuncion ptrLogic= this->pFuncionesPorLecturaI[numeroFuncion]; //crea puntero para la funcion extraida de la matriz tipo I
			(this->*ptrLogic)(this->pMipsObject, pCodigoEnProceso); //Llama a la funcion con el puntero pasando el objeto de mips


		}else if((c.comparaCadenayPuntero("000010", lecturaBitsPrecisosOP))){	//AQUI ENTRAN LOS TIPO J
			//cout <<"TIPO J"<<endl;
			cout <<lecturaBitsPrecisosOP<<endl;
			int numeroFuncion = c.binarioDecimal(lecturaBitsPrecisosOP); //numero de funcion en arreglo
			cout <<numeroFuncion<<endl;

			archmm::punteroFuncion ptrLogic= this->pFuncionesPorLecturaJ[numeroFuncion]; //crea puntero para la funcion extraida de la matriz tipo J
			(this->*ptrLogic)(this->pMipsObject, pCodigoEnProceso); //Llama a la funcion con el puntero pasando el objeto de mips


		}else{ //CATCH PARA ERRORES
			cout<< "ERROR, OPERACION OP NO CORRESPONDE A NINNGUNO DE LOS TIPOS"<<endl; // catch por si no corresponde a ninguna funcion
			cout<<"SE CAYO EN LA INSTRUCCION: "<< pPCcode<<endl;
			aumentarPC();
			ingresarLogica(pPC);
		}
	}else{
		cout<<"YA SE TERMINAN LAS INSTRUCCIONES"<<endl; // Termina de parsear
	}
}



/**
 * @brief Se encarga de tomar ciertos caracteres de un punto de inicio a un final
 * @param char pCadena Corresponde a la cadena de caracteres donde se desea extraer los caracteres
 * @param int pInicio Entero de la posicion inicial de la cadena donde se empieza a extraer
 * @param int pFinal Entero de la posicion final de la cadena donde se finaliza de extraer
 */
//char * archmm::c.tomarBits(char pCadena[], int pInicio, int pFinal, int pTama){
//	char* charRetur = new char[pTama];
//
//	cout<<"POR RE::::   "<<strlen(charRetur)<<endl;
//	memset(charRetur,0,sizeof(charRetur));
//
//	int elemento = pInicio; //entero asociado al aumento en bucle
//	int controlReturn = _pinitialCounterConsts; //entero de control para char de retorno
//
//	while(controlReturn<=pTama){ // ciclo para recorrer los arreglos y tomar los caracteres especificos, mientras el entero elemento sea menor al final
//		charRetur[controlReturn] = pCadena[elemento]; // recupera valor
//		//cout<<"EL CHAR: "<<pCadena[elemento]<<"    EN POCICION: "<<controlReturn<<endl;
//
//		elemento++; // aumenta variable
//		controlReturn++; // aumenta variable
//	}
//	cout<<"POR RETORNAR::::::::   "<<(charRetur)<<endl;
//	cout<<"POR RETORNAR::::::::   "<<strlen(charRetur)<<endl;
//	return charRetur; // retorna el arreglo
//}


/**
 * @brief Aumenta la variable del PC
 */
void archmm::aumentarPC(){
	pPC = pPC + _pPCplusConsts; //aumenta el PC
}

/**
 * @brief Regresa el PC a 0
 * @param
 */
void archmm::setearPC(){
	pPC = 0; //asigna PC a 0
}

/**
 * @brief Setea el pPc a un valor en especifico
 * @param int pValor Entero al q se desea ajustar el PC
 */
void archmm::putInPC(int pValor){
	pPC = pValor; //Le da un valor al PC
}

/**
 * @brief Mete en la pila
 * @param
 */
void archmm::pushPila(){

}

/**
 * @brief Saca de la pila
 * @param
 */
void archmm::popPila(){

}

/**
 * @brief Carga direcciones de datos y texto
 * @param
 */
void archmm::cargarRegistrosText(){

	if ("" == ""){

		pMipsObject.pBinarioPathtext = strcat (_pRutaCodigosMipsConsts, "");

		pMipsObject.pBinarioPathdata = "";
	}else if("" == ""){

		pMipsObject.pBinarioPathtext =  "";
		pMipsObject.pBinarioPathdata = "";
	}else if("" == ""){

		pMipsObject.pBinarioPathtext = "";
		pMipsObject.pBinarioPathdata =  "";
	}else if("" == ""){

		pMipsObject.pBinarioPathtext =   "";
		pMipsObject.pBinarioPathdata =  "";
	}else if("" == ""){

		pMipsObject.pBinarioPathtext =   "";
		pMipsObject.pBinarioPathdata =   "";
	}else{

		pMipsObject.pBinarioPathtext =  "";
		pMipsObject.pBinarioPathdata =  "";
	}
}


//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////
//		METODOS ASOCIADOS A LA TRADUCCION DE BITS

/**
 * @brief Corresponde al ADD de Mips
 * @param arch_mm pMips Estructura de objeto mips para trabajar
 * @param char pCode[] Codigo a procesar
 */
void archmm::ADD(arch_mm pMips, char pCode[]){
	cout <<"En Add"<<endl;
	conversions c; //objeto de la clase conversions

	char* rs = c.tomarBits(pCode, rsi, rsf, 4); //char para especificador de registro fuente
	char* rt = c.tomarBits(pCode, rti, rtf, 4); // char especificador de registro objetivo
	char* rd = c.tomarBits(pCode, rdi, rdf, 4); // char especificador de registro destino.
	char* sa = c.tomarBits(pCode, sai, saf, 4); // char cantidad de desplazamiento

	int s = c.binarioDecimal(rs); //parseo del caracter a decimal
	int t = c.binarioDecimal(rt); //parseo del caracter a decimal
	int d = c.binarioDecimal(rd); //parseo del caracter a decimal
	int a = c.binarioDecimal(sa); //parseo del caracter a decimal

	int *valorot = tomarDeMemoria(pMips.pMemoriaRegistros, t); //se busca en la memoria el valor
	int *valors = tomarDeMemoria(pMips.pMemoriaRegistros, s); //se busca en la memoria el valor

	int operacion = (*valors) + (*valorot); //resultado de operacion

	pasarApuntero(pMips.pMemoriaRegistros, operacion, d); //colocar los resultados en memoria

	aumentarPC(); //aumento en uno del PC
	ingresarLogica(pPC); // vuelve a llamar la funcion para la proxima instruccion
}

/**
 * @brief Corresponde al ADDI de Mips
 * @param arch_mm pMips Estructura de objeto mips para trabajar
 * @param char pCode[] Codigo a procesar
 */
void archmm::ADDI(arch_mm pMips, char pCode[]){
	cout <<"En Addi"<<endl;
	conversions c; //objeto de la clase conversions
	char* rs = c.tomarBits(pCode, rsi, rsf, 4); //char para especificador de registro fuente
	char* rt = c.tomarBits(pCode, rti, rtf, 4);  // char especificador de registro objetivo
	char* offset = c.tomarBits(pCode, offseti, offsetf, 15); // char correspondiente al inmediato

	int s = c.binarioDecimal(rs); //parseo del caracter a decimal
	int t = c.binarioDecimal(rt); //parseo del caracter a decimal
	int off = c.binarioDecimal(offset); //parseo del caracter a decimal

	int *valors = tomarDeMemoria(pMips.pMemoriaRegistros, s); //se busca en la memoria el valor
	int operacion = (*valors) + (off); //resultado de operacion

	pasarApuntero(pMips.pMemoriaRegistros, operacion, t); //colocar los resultados en memoria
	aumentarPC(); //aumento en uno del PC
	ingresarLogica(pPC); // vuelve a llamar la funcion para la proxima instruccion
}

/**
 * @brief Corresponde al SB de Mips
 * @param arch_mm pMips Estructura de objeto mips para trabajar
 * @param char pCode[] Codigo a procesar
 */
void archmm::SB(arch_mm pMips, char pCode[]){
	cout <<"En Sb"<<endl;
	conversions c; //objeto de la clase conversions
	char* rs = c.tomarBits(pCode, rsi, rsf, 4); //char para especificador de registro fuente
	char* rt = c.tomarBits(pCode, rti, rtf, 4);  // char especificador de registro objetivo
	char* offset = c.tomarBits(pCode, offseti, offsetf, 15); // char correspondiente al inmediato

	int s = c.binarioDecimal(rs); //parseo del caracter a decimal
	int t = c.binarioDecimal(rt); //parseo del caracter a decimal
	int off = c.binarioDecimal(offset); //parseo del caracter a decimal

	int *valors = tomarDeMemoria(pMips.pMemoriaRegistros, s); //se busca en la memoria el valor
	int *valort = tomarDeMemoria(pMips.pMemoriaRegistros, t); //se busca en la memoria el valor

	int *valor4B = tomarDeMemoria(pMips.pMemoriaRegistros, t);
	int valorGB = (*valor4B)<<24;
	int valorB = valorGB>>24;

	int operacion2 = (valorB)&(*valort);
	int operacion = (*valors) + (off); //resultado de operacion


	pasarApuntero(pMips.pMemoriaDatos, operacion, operacion2); //colocar los resultados en memoria



	aumentarPC(); //aumento en uno del PC
	ingresarLogica(pPC); // vuelve a llamar la funcion para la proxima instruccion
}


/**
 * @brief Corresponde al J de Mips
 * @param arch_mm pMips Estructura de objeto mips para trabajar
 * @param char pCode[] Codigo a procesar
 */
void archmm::J(arch_mm pMips, char pCode[]){
	cout <<"En J"<<endl;
	conversions c; //objeto de la clase conversions
	char* offset = c.tomarBits(pCode, rsi, offsetf, 25); // char correspondiente al inmediato

	//cout<<"en jjjjjjjjjjjjjjjjj   " <<pCode<<endl;
	//cout<<"en jjjjjjjjjjjjjjjjj   " <<offset<<endl;
	int off = c.binarioDecimal(offset); //parseo del caracter a decimal

	cout<<off<<endl;
	int od = off<<2;
	//cout<<od<<endl;

	int nPC1 = ((pPC*4)&0xf0000000);
	//cout<<nPC1<<endl;

	int nPC2 = ((nPC1|od));

	//cout<<"GG"<<nPC2<<endl;

	//	cout<<"EN EL J SE OBTIENE ESTA OPERACION PAPU:.........."<<nPC1<<endl;
	//	cout<<"EN EL J SE OBTIENE ESTA OPERACION PAPU:.........."<<nPC2/4<<endl;
	//
	//	cout<<"EN EL J pc :.........."<<pPC<<endl;
	//	cout<<"EN EL J SE OBTIENE pc:.........."<<nPC2<<endl;

	putInPC(nPC2/4); //aumento en uno del PC
	//	cout<<"EN EL J nuevo:.........."<<pPC<<endl;

	ingresarLogica(pPC); // vuelve a llamar la funcion para la proxima instruccion
}



/**
 * @brief Corresponde al BEQ de Mips
 * @param arch_mm pMips Estructura de objeto mips para trabajar
 * @param char pCode[] Codigo a procesar
 */
void archmm::BEQ(arch_mm pMips, char pCode[]){
	cout <<"En Beq"<<endl;
	conversions c; //objeto de la clase conversions
	char* rs = c.tomarBits(pCode, rsi, rsf, 4); //char para especificador de registro fuente
	char* rt = c.tomarBits(pCode, rti, rtf, 4);  // char especificador de registro objetivo
	char* offset = c.tomarBits(pCode, offseti, offsetf, 15); // char correspondiente al inmediato

	int s = c.binarioDecimal(rs); //parseo del caracter a decimal
	int t = c.binarioDecimal(rt); //parseo del caracter a decimal
	int off = c.binarioDecimal(offset); //parseo del caracter a decimal

	int *valors = tomarDeMemoria(pMips.pMemoriaRegistros, s); //se busca en la memoria el valor
	int *valort = tomarDeMemoria(pMips.pMemoriaRegistros, t); //se busca en la memoria el valor


	if ((*valors)==(*valort)){
		int operacion = (off<<2);
		cout<<"EN EL BEQ L OPERACION ES "<<operacion<<endl;
		int ope2= (pPC*4) + (operacion);

		ope2 = (ope2/4);

		//		cout<<"EN EL BEQ SE OBTIENE ESTA OPERACION PAPU:.........."<<operacion<<endl;
		//
		//
		//		cout<<"EN EL BEQ pc :.........."<<pPC<<endl;
		//		cout<<"EN EL BEQ SE OBTIENE pc:.........."<<ope2<<endl;
		putInPC(ope2); //aumento en uno del PC
		//		cout<<"EN EL BEQ nuevo:.........."<<pPC<<endl;
		ingresarLogica(pPC); // vuelve a llamar la funcion para la proxima instruccion
	}else{
		cout<<"EN EL BEQ L OPERACION ES NOOOOO"<<endl;
		aumentarPC(); //aumento en uno del PC
		ingresarLogica(pPC); // vuelve a llamar la funcion para la proxima instruccion
	}
}

/**
 * @brief Corresponde al BNE de Mips
 * @param arch_mm pMips Estructura de objeto mips para trabajar
 * @param char pCode[] Codigo a procesar
 */
void archmm::BNE(arch_mm pMips, char pCode[]){
	cout <<"En Bne"<<endl;
	conversions c; //objeto de la clase conversions
	char* rs = c.tomarBits(pCode, rsi, rsf, 4); //char para especificador de registro fuente
	char* rt = c.tomarBits(pCode, rti, rtf, 4);  // char especificador de registro objetivo
	char* offset = c.tomarBits(pCode, offseti, offsetf, 15); // char correspondiente al inmediato

	int s = c.binarioDecimal(rs); //parseo del caracter a decimal
	int t = c.binarioDecimal(rt); //parseo del caracter a decimal
	int off = c.binarioDecimal(offset); //parseo del caracter a decimal

	int *valors = tomarDeMemoria(pMips.pMemoriaRegistros, s); //se busca en la memoria el valor
	int *valort = tomarDeMemoria(pMips.pMemoriaRegistros, t); //se busca en la memoria el valor

	if ((*valors)!=(*valort)){
		int operacion = (off<<2);
		int ope2= (pPC*4) + (operacion);

		ope2 = (ope2/4);
		//		cout<<"EN EL BNE SE OBTIENE ESTA OPERACION PAPU:.........."<<operacion<<endl;
		//
		//		cout<<"EN EL BNE pc :.........."<<pPC<<endl;
		//		cout<<"EN EL BNE SE OBTIENE pc:.........."<<ope2<<endl;
		putInPC(ope2); //aumento en uno del PC
		//		cout<<"EN EL BNE nuevo:.........."<<pPC<<endl;

		ingresarLogica(pPC); // vuelve a llamar la funcion para la proxima instruccion

	}else{
		aumentarPC(); //aumento en uno del PC
		ingresarLogica(pPC); // vuelve a llamar la funcion para la proxima instruccion
	}
}


/**
 * @brief Corresponde al BGEZ de Mips
 * @param arch_mm pMips Estructura de objeto mips para trabajar
 * @param char pCode[] Codigo a procesar
 */
void archmm::BGEZ(arch_mm pMips, char pCode[]){
	cout <<"En Bgez"<<endl;
	conversions c; //objeto de la clase conversions
	char* rs = c.tomarBits(pCode, rsi, rsf, 4); //char para especificador de registro fuente
	char* rt = c.tomarBits(pCode, rti, rtf, 4);  // char especificador de registro objetivo
	char* offset = c.tomarBits(pCode, offseti, offsetf, 15); // char correspondiente al inmediato

	int s = c.binarioDecimal(rs); //parseo del caracter a decimal
	int t = c.binarioDecimal(rt); //parseo del caracter a decimal
	int off = c.binarioDecimal(offset); //parseo del caracter a decimal

	int *valors = tomarDeMemoria(pMips.pMemoriaRegistros, s); //se busca en la memoria el valor
	int *valort = tomarDeMemoria(pMips.pMemoriaRegistros, t); //se busca en la memoria el valor

	if ((*valors)>= 0){
		int operacion = (off<<2);
		int ope2= (pPC*4) + (operacion);

		ope2 = (ope2/4);
		//		cout<<"EN EL BGEZ SE OBTIENE ESTA OPERACION PAPU:.........."<<operacion<<endl;
		//
		//		cout<<"EN EL BGEZ pc :.........."<<pPC<<endl;
		//		cout<<"EN EL BGEZ SE OBTIENE pc:.........."<<ope2<<endl;
		putInPC(ope2); //aumento en uno del PC
		//		cout<<"EN EL BGEZ nuevo:.........."<<pPC<<endl;
		ingresarLogica(pPC); // vuelve a llamar la funcion para la proxima instruccion

	}else{
		aumentarPC(); //aumento en uno del PC
		ingresarLogica(pPC); // vuelve a llamar la funcion para la proxima instruccion
	}
}

/**
 * @brief Corresponde al BGTZ de Mips
 * @param arch_mm pMips Estructura de objeto mips para trabajar
 * @param char pCode[] Codigo a procesar
 */
void archmm::BGTZ(arch_mm pMips, char pCode[]){
	cout <<"En Bgtz"<<endl;
	conversions c; //objeto de la clase conversions
	char* rs = c.tomarBits(pCode, rsi, rsf, 4); //char para especificador de registro fuente
	char* rt = c.tomarBits(pCode, rti, rtf, 4);  // char especificador de registro objetivo
	char* offset = c.tomarBits(pCode, offseti, offsetf, 15); // char correspondiente al inmediato

	int s = c.binarioDecimal(rs); //parseo del caracter a decimal
	int t = c.binarioDecimal(rt); //parseo del caracter a decimal
	int off = c.binarioDecimal(offset); //parseo del caracter a decimal

	int *valors = tomarDeMemoria(pMips.pMemoriaRegistros, s); //se busca en la memoria el valor
	int *valort = tomarDeMemoria(pMips.pMemoriaRegistros, t); //se busca en la memoria el valor

	if ((*valors)> 0){

		int operacion = (off<<2);
		int ope2= (pPC*4) + (operacion);
		ope2 = (ope2/4);
		//		cout<<"EN EL BGTZ SE OBTIENE ESTA OPERACION PAPU:.........."<<operacion<<endl;
		//
		//		cout<<"EN EL BGTZ pc :.........."<<pPC<<endl;
		//		cout<<"EN EL BGTZ SE OBTIENE pc:.........."<<ope2<<endl;
		putInPC(ope2); //aumento en uno del PC
		//		cout<<"EN EL BGTZ nuevo:.........."<<pPC<<endl;
		ingresarLogica(pPC); // vuelve a llamar la funcion para la proxima instruccion

	}else{
		aumentarPC(); //aumento en uno del PC
		ingresarLogica(pPC); // vuelve a llamar la funcion para la proxima instruccion
	}
}

/**
 * @brief Corresponde al SLTI de Mips
 * @param arch_mm pMips Estructura de objeto mips para trabajar
 * @param char pCode[] Codigo a procesar
 */
void archmm::SLTI(arch_mm pMips, char pCode[]){
	cout <<"En Slti"<<endl;
	conversions c; //objeto de la clase conversions
	char* rs = c.tomarBits(pCode, rsi, rsf, 4); //char para especificador de registro fuente
	char* rt = c.tomarBits(pCode, rti, rtf, 4);  // char especificador de registro objetivo
	char* offset = c.tomarBits(pCode, offseti, offsetf, 15); // char correspondiente al inmediato

	int s = c.binarioDecimal(rs); //parseo del caracter a decimal
	int t = c.binarioDecimal(rt); //parseo del caracter a decimal
	int off = c.binarioDecimal(offset); //parseo del caracter a decimal

	int *valors = tomarDeMemoria(pMips.pMemoriaRegistros, s); //se busca en la memoria el valor
	int *valort = tomarDeMemoria(pMips.pMemoriaRegistros, t); //se busca en la memoria el valor

	if ((*valors)<off){
		pasarApuntero(pMips.pMemoriaRegistros, 1, t);

	}else{
		pasarApuntero(pMips.pMemoriaRegistros, 0, t);

	}
	aumentarPC(); //aumento en uno del PC
	ingresarLogica(pPC); // vuelve a llamar la funcion para la proxima instruccion
}


/**
 * @brief Corresponde al SRL de Mips
 * @param arch_mm pMips Estructura de objeto mips para trabajar
 * @param char pCode[] Codigo a procesar
 */
void archmm::SRL(arch_mm pMips, char pCode[]){
	cout <<"En Srl"<<endl;
	conversions c; //objeto de la clase conversions

	char* rs = c.tomarBits(pCode, rsi, rsf, 4); //char para especificador de registro fuente
	char* rt = c.tomarBits(pCode, rti, rtf, 4); // char especificador de registro objetivo
	char* rd = c.tomarBits(pCode, rdi, rdf, 4); // char especificador de registro destino.
	char* sa = c.tomarBits(pCode, sai, saf, 4); // char cantidad de desplazamiento

	//	int s = c.binarioDecimal(rs); //parseo del caracter a decimal
	int t = c.binarioDecimal(rt); //parseo del caracter a decimal
	int d = c.binarioDecimal(rd); //parseo del caracter a decimal
	int a = c.binarioDecimal(sa); //parseo del caracter a decimal

	int *valorot = tomarDeMemoria(pMips.pMemoriaRegistros, t); //se busca en la memoria el valor

	int operacion = (*valorot)>>a; //resultado de operacion
	pasarApuntero(pMips.pMemoriaRegistros, operacion, d); //colocar los resultados en memoria

	aumentarPC(); //aumento en uno del PC
	ingresarLogica(pPC); // vuelve a llamar la funcion para la proxima instruccion
}


/**
 * @brief Corresponde al SLL de Mips
 * @param arch_mm pMips Estructura de objeto mips para trabajar
 * @param char pCode[] Codigo a procesar
 */
void archmm::SLL(arch_mm pMips, char pCode[]){
	cout <<"En Sll"<<endl;
	conversions c; //objeto de la clase conversions

	char* rs = c.tomarBits(pCode, rsi, rsf, 4); //char para especificador de registro fuente
	char* rt = c.tomarBits(pCode, rti, rtf, 4); // char especificador de registro objetivo
	char* rd = c.tomarBits(pCode, rdi, rdf, 4); // char especificador de registro destino.
	char* sa = c.tomarBits(pCode, sai, saf, 4); // char cantidad de desplazamiento

	//	int s = c.binarioDecimal(rs); //parseo del caracter a decimal
	int t = c.binarioDecimal(rt); //parseo del caracter a decimal
	int d = c.binarioDecimal(rd); //parseo del caracter a decimal
	int a = c.binarioDecimal(sa); //parseo del caracter a decimal

	int *valorot = tomarDeMemoria(pMips.pMemoriaRegistros, t); //se busca en la memoria el valor

	int operacion = (*valorot)<<a; //resultado de operacion

	pasarApuntero(pMips.pMemoriaRegistros, operacion, d); //colocar los resultados en memoria

	aumentarPC(); //aumento en uno del PC
	ingresarLogica(pPC); // vuelve a llamar la funcion para la proxima instruccion
}


/**
 * @brief Corresponde al SUB de Mips
 * @param arch_mm pMips Estructura de objeto mips para trabajar
 * @param char pCode[] Codigo a procesar
 */
void archmm::SUB(arch_mm pMips, char pCode[]){
	cout <<"En Sub"<<endl;
	conversions c; //objeto de la clase conversions
	char* rs = c.tomarBits(pCode, rsi, rsf, 4); //char para especificador de registro fuente
	char* rt = c.tomarBits(pCode, rti, rtf, 4); // char especificador de registro objetivo
	char* rd = c.tomarBits(pCode, rdi, rdf, 4); // char especificador de registro destino.
	char* sa = c.tomarBits(pCode, sai, saf, 4); // char cantidad de desplazamiento

	int s = c.binarioDecimal(rs); //parseo del caracter a decimal
	int t = c.binarioDecimal(rt); //parseo del caracter a decimal
	int d = c.binarioDecimal(rd); //parseo del caracter a decimal
	int a = c.binarioDecimal(sa); //parseo del caracter a decimal

	int * valorot = tomarDeMemoria(pMips.pMemoriaRegistros, t); //se busca en la memoria el valor
	int * valors = tomarDeMemoria(pMips.pMemoriaRegistros, s); //se busca en la memoria el valor

	int operacion = (*valors) - (*valorot); //resultado de operacion

	pasarApuntero(pMips.pMemoriaRegistros, operacion, d); //colocar los resultados en memoria

	aumentarPC(); //aumento en uno del PC
	ingresarLogica(pPC); // vuelve a llamar la funcion para la proxima instruccion

}

/**
 * @brief Corresponde al MULT de Mips
 * @param arch_mm pMips Estructura de objeto mips para trabajar
 * @param char pCode[] Codigo a procesar
 */
void archmm::MULT(arch_mm pMips, char pCode[]){ //NO SE Q HACER EN ESTE
	cout <<"En Mult"<<endl;
	conversions c; //objeto de la clase conversions

	char* rs = c.tomarBits(pCode, rsi, rsf, 4); //char para especificador de registro fuente
	char* rt = c.tomarBits(pCode, rti, rtf, 4); // char especificador de registro objetivo

	int s = c.binarioDecimal(rs); //parseo del caracter a decimal
	int t = c.binarioDecimal(rt); //parseo del caracter a decimal

	int * valorot = tomarDeMemoria(pMips.pMemoriaRegistros, t); //se busca en la memoria el valor
	int * valors = tomarDeMemoria(pMips.pMemoriaRegistros, s); //se busca en la memoria el valor

	int operacion = (*valors)*(*valorot); //resultado de operacion

	pasarApuntero(pMips.pMemoriaRegistros, operacion, pLO); //colocar los resultados en memoria

	aumentarPC(); //aumento en uno del PC
	ingresarLogica(pPC); // vuelve a llamar la funcion para la proxima instruccion

}

/**
 * @brief Corresponde al MFLO de Mips
 * @param arch_mm pMips Estructura de objeto mips para trabajar
 * @param char pCode[] Codigo a procesar
 */
void archmm::MFLO(arch_mm pMips, char pCode[]){ //NO SE Q HACER EN ESTE
	cout <<"En Mflo"<<endl;
	conversions c; //objeto de la clase conversions

	char* rd = c.tomarBits(pCode, rdi, rdf, 4); //char para especificador de registro fuente

	int d = c.binarioDecimal(rd); //parseo del caracter a decimal

	int * valorLO = tomarDeMemoria(pMips.pMemoriaRegistros, pLO); //se busca en la memoria el valor
	pasarApuntero(pMips.pMemoriaRegistros,(*valorLO) , d); //colocar los resultados en memoria

	aumentarPC(); //aumento en uno del PC
	ingresarLogica(pPC); // vuelve a llamar la funcion para la proxima instruccion

}

/**
 * @brief Corresponde al MFHI de Mips
 * @param arch_mm pMips Estructura de objeto mips para trabajar
 * @param char pCode[] Codigo a procesar
 */
void archmm::MFHI(arch_mm pMips, char pCode[]){ //NO SE Q HACER EN ESTE
	cout <<"En Mfhi"<<endl;
	conversions c; //objeto de la clase conversions

	char* rd = c.tomarBits(pCode, rdi, rdf, 4); //char para especificador de registro fuente

	int d = c.binarioDecimal(rd); //parseo del caracter a decimal

	int * valorHI = tomarDeMemoria(pMips.pMemoriaRegistros, pHI); //se busca en la memoria el valor
	pasarApuntero(pMips.pMemoriaRegistros,(*valorHI) , d); //colocar los resultados en memoria

	aumentarPC(); //aumento en uno del PC
	ingresarLogica(pPC); // vuelve a llamar la funcion para la proxima instruccion

}

/**
 * @brief Corresponde al DIV de Mips
 * @param arch_mm pMips Estructura de objeto mips para trabajar
 * @param char pCode[] Codigo a procesar
 */
void archmm::DIV(arch_mm pMips, char pCode[]){
	cout <<"En Div"<<endl;
	conversions c; //objeto de la clase conversions

	char* rs = c.tomarBits(pCode, rsi, rsf, 4); //char para especificador de registro fuente
	char* rt = c.tomarBits(pCode, rti, rtf, 4); // char especificador de registro objetivo
	char* rd = c.tomarBits(pCode, rdi, rdf, 4); // char especificador de registro destino.
	char* sa = c.tomarBits(pCode, sai, saf, 4); // char cantidad de desplazamiento

	int s = c.binarioDecimal(rs); //parseo del caracter a decimal
	int t = c.binarioDecimal(rt); //parseo del caracter a decimal
	int d = c.binarioDecimal(rd); //parseo del caracter a decimal
	int a = c.binarioDecimal(sa); //parseo del caracter a decimal

	int *valorot = tomarDeMemoria(pMips.pMemoriaRegistros, t); //se busca en la memoria el valor
	int *valors = tomarDeMemoria(pMips.pMemoriaRegistros, s); //se busca en la memoria el valor

	int operacion1 = (*valors) / (*valorot); //resultado de operacion
	int operacion2 = (*valors)%(*valorot); //resultado de operacion

	pasarApuntero(pMips.pMemoriaRegistros, operacion1, pLO); //colocar los resultados en memoria
	pasarApuntero(pMips.pMemoriaRegistros, operacion2, pHI); //colocar los resultados en memoria

	aumentarPC(); //aumento en uno del PC
	ingresarLogica(pPC); // vuelve a llamar la funcion para la proxima instruccion

}


/**
 * @brief Corresponde al LW de Mips
 * @param arch_mm pMips Estructura de objeto mips para trabajar
 * @param char pCode[] Codigo a procesar
 */
void archmm::LW(arch_mm pMips, char pCode[]){
	cout <<"En lw"<<endl;

	conversions c; //objeto de la clase conversions
	char* rs = c.tomarBits(pCode, rsi, rsf, 4); //char para especificador de registro fuente
	char* rt = c.tomarBits(pCode, rti, rtf, 4); // char especificador de registro objetivo
	char* ri = c.tomarBits(pCode, offseti, offsetf, 15); // char especificador de registro destino.

	int s = c.binarioDecimal(rs); //parseo del caracter a decimal

	int t = c.binarioDecimal(rt); //parseo del caracter a decimal
	int i = c.binarioDecimal(ri); //parseo del caracter a decimal

	int * valors = tomarDeMemoria(pMips.pMemoriaRegistros, s); //se busca en la memoria el valor

	int posMem = ((*valors)+i+_pOFFSETDatos); //operacion para calculo de direccion

	posMem = posMem/4; //ajuste de relacion 4 a 1

	cout<<"EN LWLW ES LA PUTA:   ................................."<<posMem<<endl;

	int * valori = tomarDeMemoria(pMemoriaDatos, (posMem)); //se busca en la memoria el valor

	int operacion1 = (*valors) + (*valori); //resultado de operacion

	char * corrabora = c.decimalABinario((long) operacion1); //extrae el decimal a binario
	char * corrabora1 = c.tomarBits(corrabora, 30, 31, 2);  //revisa sus dos ultimos digitos del binario

	if (c.comparaCadenayPuntero(corrabora1, "00")){ //se encarga de corraborar direccion.
		pasarApuntero(pMips.pMemoriaRegistros, *valori, t); //se pasa a registro t

	}else{
		cout<<"EXCEPCION DE LW Y EL ADDRESS GENERADO"<<endl; //excepcion de hardware
	}

	aumentarPC(); //aumento en uno del PC
	ingresarLogica(pPC); // vuelve a llamar la funcion para la proxima instruccion

}

/**
 * @brief Corresponde al SW de Mips
 * @param arch_mm pMips Estructura de objeto mips para trabajar
 * @param char pCode[] Codigo a procesar
 */
void archmm::SW(arch_mm pMips, char pCode[]){
	cout <<"En sw"<<endl;
	conversions c; //objeto de la clase conversions
	char* rs = c.tomarBits(pCode, rsi, rsf, 4); //char para especificador de registro fuente
	char* rt = c.tomarBits(pCode, rti, rtf, 4); // char especificador de registro objetivo
	char* ri = c.tomarBits(pCode, offseti, offsetf, 15); // char especificador de registro destino.

	int s = c.binarioDecimal(rs); //parseo del caracter a decimal

	int t = c.binarioDecimal(rt); //parseo del caracter a decimal
	int i = c.binarioDecimal(ri); //parseo del caracter a decimal

	int * valors = tomarDeMemoria(pMips.pMemoriaRegistros, s); //se busca en la memoria el valor
	int * valort = tomarDeMemoria(pMips.pMemoriaRegistros, t); //se busca en la memoria el valor

	cout<<"valor de t en sw  "<<(*valort)<<endl;
	cout<<"valor de posicion   "<<((*valors)+i+_pOFFSETDatos)<<endl;
	pasarApuntero(pMips.pMemoriaDatos, (long)valort,((*valors)+i+_pOFFSETDatos));

	aumentarPC(); //aumento en uno del PC
	ingresarLogica(pPC); // vuelve a llamar la funcion para la proxima instruccion


}

/**
 * @brief Corresponde al LUI de Mips
 * @param arch_mm pMips Estructura de objeto mips para trabajar
 * @param char pCode[] Codigo a procesar
 */
void archmm::LUI(arch_mm pMips, char pCode[]){
	cout <<"En lui"<<endl;
	conversions c; //objeto de la clase conversions

	char* rt = c.tomarBits(pCode, rti, rtf, 4); // char especificador de registro objetivo
	char* ri = c.tomarBits(pCode, offseti, offsetf, 15); // char especificador de registro destino.

	int t = c.binarioDecimal(rt); //parseo del caracter a decimal
	int i = c.binarioDecimal(ri); //parseo del caracter a decimal

	cout<<"EN LUI VAA :  "<<i<<endl;
	int operacion = (i<<16); //operacion de bitwise

	pasarApuntero(pMips.pMemoriaRegistros, (long) operacion, t); //se pasa a registro t

	aumentarPC(); //aumento en uno del PC
	ingresarLogica(pPC); // vuelve a llamar la funcion para la proxima instruccion
}

/**
 * @brief Corresponde al ADDIU de Mips
 * @param arch_mm pMips Estructura de objeto mips para trabajar
 * @param char pCode[] Codigo a procesar
 */
void archmm::ADDIU(arch_mm pMips, char pCode[]){
	cout <<"En Addiu"<<endl;
	conversions c; //objeto de la clase conversions
	char* rs = c.tomarBits(pCode, rsi, rsf, 4); //char para especificador de registro fuente
	char* rt = c.tomarBits(pCode, rti, rtf, 4); // char especificador de registro objetivo

	conversions p;
	char* offset = p.tomarBits(pCode, offseti, offsetf, 15); // char especificador de registro destino.

	int s = c.binarioDecimal(rs); //parseo del caracter a decimal
	int t = c.binarioDecimal(rt); //parseo del caracter a decimal

	int off = c.binarioDecimal(offset); //parseo del caracter a decimal

	if(t == 2){

		cout<<"LLAMANDO A SYSTEM..........................................................................: "<<offset<<endl;
		cout<<"LLAMANDO A SYSTEM..........................................................................: "<<off<<endl;
		archmm::punteroFuncion ptrLogic= this->pFuncionesPorLecturaSYSCALLS[off]; //crea puntero para la funcion extraida de la matriz tipo R
		(this->*ptrLogic)(this->pMipsObject, pCode); //Llama a la funcion con el puntero pasando el objeto de mips

	}else{
		int *valors = tomarDeMemoria(pMips.pMemoriaRegistros, s); //se busca en la memoria el valor

		cout<<"ES EL INMEDIATO A METER: ....................: "<<offset<<endl;
		cout<<"ES EL INMEDIATO A METER: ....................: "<<off<<endl;
		int operacion = (*valors) + (off); //resultado de operacion

		pasarApuntero(pMips.pMemoriaRegistros, (operacion), t); //colocar los resultados en memoria
		aumentarPC(); //aumento en uno del PC
		ingresarLogica(pPC); // vuelve a llamar la funcion para la proxima instruccion
	}
}


/**
 * @brief Corresponde al ANDI de Mips
 * @param arch_mm pMips Estructura de objeto mips para trabajar
 * @param char pCode[] Codigo a procesar
 */
void archmm::ANDI(arch_mm pMips, char pCode[]){
	cout <<"En Andi"<<endl;
	conversions c; //objeto de la clase conversions
	char* rs = c.tomarBits(pCode, rsi, rsf, 4); //char para especificador de registro fuente
	char* rt = c.tomarBits(pCode, rti, rtf, 4); // char especificador de registro objetivo
	char* offset = c.tomarBits(pCode, offseti, offsetf, 15); // char especificador de registro destino.

	int s = c.binarioDecimal(rs); //parseo del caracter a decimal
	int t = c.binarioDecimal(rt); //parseo del caracter a decimal
	int off = c.binarioDecimal(offset); //parseo del caracter a decimal

	//int *valoroff = tomarDeMemoria(pMips.pMemoriaDatos, off); //se busca en la memoria el valor
	int *valors = tomarDeMemoria(pMips.pMemoriaRegistros, s); //se busca en la memoria el valor

	int operacion = (*valors)&(off); //resultado de operacion

	pasarApuntero(pMips.pMemoriaRegistros, operacion, t); //colocar los resultados en memoria

	aumentarPC(); //aumento en uno del PC
	ingresarLogica(pPC); // vuelve a llamar la funcion para la proxima instruccion

}

/**
 * @brief Corresponde al ORI de Mips
 * @param arch_mm pMips Estructura de objeto mips para trabajar
 * @param char pCode[] Codigo a procesar
 */
void archmm::ORI(arch_mm pMips, char pCode[]){
	cout <<"En Ori"<<endl;
	conversions c; //objeto de la clase conversions
	char* rs = c.tomarBits(pCode, rsi, rsf, 4); //char para especificador de registro fuente
	char* rt = c.tomarBits(pCode, rti, rtf, 4); // char especificador de registro objetivo
	char* offset = c.tomarBits(pCode, offseti, offsetf, 15); // char especificador de registro destino.

	int s = c.binarioDecimal(rs); //parseo del caracter a decimal
	int t = c.binarioDecimal(rt); //parseo del caracter a decimal
	int off = c.binarioDecimal(offset); //parseo del caracter a decimal

	//int *valoroff = tomarDeMemoria(pMips.pMemoriaDatos, off); //se busca en la memoria el valor
	int *valors = tomarDeMemoria(pMips.pMemoriaRegistros, s); //se busca en la memoria el valor


	int operacion = (*valors)|(off); //resultado de operacion

	pasarApuntero(pMips.pMemoriaRegistros, operacion, t); //colocar los resultados en memoria

	aumentarPC(); //aumento en uno del PC
	ingresarLogica(pPC); // vuelve a llamar la funcion para la proxima instruccion

}

/**
 * @brief Corresponde al Or de Mips
 * @param arch_mm pMips Estructura de objeto mips para trabajar
 * @param char pCode[] Codigo a procesar
 */
void archmm::OR(arch_mm pMips, char pCode[]){
	cout <<"En Or"<<endl;
	conversions c; //objeto de la clase conversions

	char* rs = c.tomarBits(pCode, rsi, rsf, 4); //char para especificador de registro fuente
	char* rt = c.tomarBits(pCode, rti, rtf, 4); // char especificador de registro objetivo
	char* rd = c.tomarBits(pCode, rdi, rdf, 4); // char especificador de registro destino.

	int s = c.binarioDecimal(rs); //parseo del caracter a decimal
	int t = c.binarioDecimal(rt); //parseo del caracter a decimal
	int d = c.binarioDecimal(rd); //parseo del caracter a decimal

	int *valorot = tomarDeMemoria(pMips.pMemoriaRegistros, t); //se busca en la memoria el valor
	int *valors = tomarDeMemoria(pMips.pMemoriaRegistros, s); //se busca en la memoria el valor

	int operacion = (*valors)|(*valorot); //resultado de operacion

	pasarApuntero(pMips.pMemoriaRegistros, operacion, d); //colocar los resultados en memoria

	aumentarPC(); //aumento en uno del PC
	ingresarLogica(pPC); // vuelve a llamar la funcion para la proxima instruccion
}

/**
 * @brief Corresponde al SYSTCALL de Mips
 * @param arch_mm pMips Estructura de objeto mips para trabajar
 * @param char pCode[] Codigo a procesar
 */
void archmm::ADDU(arch_mm pMips, char pCode[]){
	cout <<"En Addu"<<endl;

	conversions c; //objeto de la clase conversions

	char* rs = c.tomarBits(pCode, rsi, rsf, 4); //char para especificador de registro fuente
	char* rt = c.tomarBits(pCode, rti, rtf, 4); // char especificador de registro objetivo
	char* rd = c.tomarBits(pCode, rdi, rdf, 4); // char especificador de registro destino.

	int s = c.binarioDecimal(rs); //parseo del caracter a decimal
	int t = c.binarioDecimal(rt); //parseo del caracter a decimal
	int d = c.binarioDecimal(rd); //parseo del caracter a decimal

	int *valorot = tomarDeMemoria(pMips.pMemoriaRegistros, t); //se busca en la memoria el valor
	int *valors = tomarDeMemoria(pMips.pMemoriaRegistros, s); //se busca en la memoria el valor

	int operacion = (*valors) + (*valorot); //resultado de operacion

	pasarApuntero(pMips.pMemoriaRegistros, operacion, d); //colocar los resultados en memoria

	aumentarPC(); //aumenta pc
	ingresarLogica(pPC); // vuelve a llamar la funcion para la proxima instruccion
}
//////////////////////////////////////////////////////////////////////////////////////////
/**
 * @brief Corresponde al SYSTCALL12 de Mips
 * @param arch_mm pMips Estructura de objeto mips para trabajar
 * @param char pCode[] Codigo a procesar
 */
void archmm::SYSCALL12(arch_mm pMips, char pCode[]){
	cout <<"SYSTEMCALL12"<<endl;

	cout<<"NO SE LOCO Q HACER"<<endl;

	aumentarPC(); //aumento en uno del PC
	ingresarLogica(pPC); // vuelve a llamar la funcion para la proxima instruccion

}

/**
 * @brief Corresponde al SYSTCALL13 de Mips
 * @param arch_mm pMips Estructura de objeto mips para trabajar
 * @param char pCode[] Codigo a procesar
 */
void archmm::SYSCALL13(arch_mm pMips, char pCode[]){
	cout <<"SYSTEMCALL13"<<endl;



	int *valoroa0 = tomarDeMemoria(pMips.pMemoriaRegistros, 4); //se busca en la memoria el valor
	int *valoroa1 = tomarDeMemoria(pMips.pMemoriaRegistros, 5); //se busca en la memoria el valor
	int *valora2 = tomarDeMemoria(pMips.pMemoriaRegistros, 6); //se busca en la memoria el valor

	char nombreArchivo[] = "/home/acacia/Escritorio/temp.txt";

	std::fstream myfile(nombreArchivo, ios::in| std::fstream::out |ios::binary);
	if(!myfile.is_open()){
		std::fstream myfile(nombreArchivo, ios::in| std::fstream::out | ios::trunc |ios::binary);
	}

	FILE *my = new FILE;

	void * ptrFile;

	cout<<"EN EL  SYS13 EL A0 ES:::::::"<<(*valoroa0)<<endl;

	if ((*valoroa0)!=-1){
		pasarApuntero(pMips.pMemoriaRegistros, 1, 2);

	}else{
		cout<<"NO SE ABRE EL ARCHIVO"<<endl;
		pasarApuntero(pMips.pMemoriaRegistros, -1, 2);
	}
	aumentarPC(); //aumento en uno del PC
	ingresarLogica(pPC); // vuelve a llamar la funcion para la proxima instruccion
}

/**
 * @brief Corresponde al SYSTCALL15 de Mips
 * @param arch_mm pMips Estructura de objeto mips para trabajar
 * @param char pCode[] Codigo a procesar
 */
void archmm::SYSCALL15(arch_mm pMips, char pCode[]){
	cout <<"SYSTEMCALL15"<<endl;

//	FILE * prtFile = (FILE*)tomarDeMemoria(pMips.pMemoriaRegistros, 2);

	int *Y=tomarDeMemoria(pMips.pMemoriaRegistros, 2);

	char nombreArchivo[] = "/home/acacia/Escritorio/temp.txt";

	std::fstream myfile;

	int *valoroa1 = tomarDeMemoria(pMips.pMemoriaRegistros, 5); //se busca en la memoria el valor

	cout<<"ELL VALOR DE ESA VARIABLE A1:   "<<(*valoroa1)<<endl;

	int *valora2 = tomarDeMemoria(pMips.pMemoriaRegistros, 6); //se busca en la memoria el valor

	myfile.open(nombreArchivo, std::fstream::in | std::fstream::out | std::fstream::app);

	char * parseoAsciia1 = nombreArchivo;

	char * parseoAsciia2 = (char*)(*valora2);

	if (myfile.is_open()){
		myfile<<"parseoAsciia2"<<endl;
		myfile.close();
	}
	//	prtFile = fopen(parseoAsciia1, "w");
	//
	//	if (prtFile != NULL){
	//		fputs(parseoAsciia2, prtFile);
	//		cout << "Se escribio"<< endl;
	//		fclose(prtFile);
	//	}
	//	else {
	//		cout << "No se pudo abrir el archivo";
	//	}

	if((*Y)!=-1){
		if (myfile.is_open()){
			myfile<<parseoAsciia2<<endl;
			myfile.close();

			pasarApuntero(pMips.pMemoriaRegistros, *Y, 4);
			pasarApuntero(pMips.pMemoriaRegistros, (strlen(parseoAsciia2)), 2);
		}else{
			cout<<"NO SE ABRE"<<endl;
		}
	}else{

	}

	aumentarPC(); //aumento en uno del PC
	ingresarLogica(pPC); // vuelve a llamar la funcion para la proxima instruccion

}

/**
 * @brief Corresponde al SYSTCALL4 de Mips
 * @param arch_mm pMips Estructura de objeto mips para trabajar
 * @param char pCode[] Codigo a procesar
 */
void archmm::SYSCALL4(arch_mm pMips, char pCode[]){
	cout <<"SYSTEMCALL4"<<endl;

	int * address = tomarDeMemoria(pMips.pMemoriaRegistros, 4);

	cout << address <<endl;

	pasarApuntero(pMips.pMemoriaRegistros, 1, 4);

	aumentarPC(); //aumento en uno del PC
	ingresarLogica(pPC); // vuelve a llamar la funcion para la proxima instruccion

}

/**
 * @brief Corresponde al SYSTCALL1 de Mips
 * @param arch_mm pMips Estructura de objeto mips para trabajar
 * @param char pCode[] Codigo a procesar
 */
void archmm::SYSCALL1(arch_mm pMips, char pCode[]){
	cout <<"SYSTEMCALL1"<<endl;

	int * a0 = tomarDeMemoria(pMips.pMemoriaRegistros, 4);
	cout <<(*a0)<<endl;

	aumentarPC(); //aumento en uno del PC
	ingresarLogica(pPC); // vuelve a llamar la funcion para la proxima instruccion

}

/**
 * @brief Corresponde al SYSTCALL1 de Mips
 * @param arch_mm pMips Estructura de objeto mips para trabajar
 * @param char pCode[] Codigo a procesar
 */
void archmm::SYSCALL16(arch_mm pMips, char pCode[]){
	cout <<"SYSTEMCALL16"<<endl;

	pasarApuntero(pMips.pMemoriaRegistros, -1, 4);
	aumentarPC(); //aumento en uno del PC
	ingresarLogica(pPC); // vuelve a llamar la funcion para la proxima instruccion

}
//////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////////////////////
archmm::~archmm() {
	// TODO Auto-generated destructor stub
}

