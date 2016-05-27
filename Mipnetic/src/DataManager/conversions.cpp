/*
 * conversions.cpp
 *
 *  Created on: 7 de may. de 2016
 *      Author: gabriel
 */

#include "conversions.h"

conversions::conversions() {
	// TODO Auto-generated constructor stub

}

conversions::~conversions() {
	// TODO Auto-generated destructor stub

}
/**
 * @brief Se encarga de tomar ciertos caracteres de un punto de inicio a un final
 * @param char pCadena Corresponde a la cadena de caracteres donde se desea extraer los caracteres
 * @param int pInicio Entero de la posicion inicial de la cadena donde se empieza a extraer
 * @param int pFinal Entero de la posicion final de la cadena donde se finaliza de extraer
 */
char * conversions::tomarBits(char pCadena[], int pInicio, int pFinal, int pTama){
	char* charRetur = new char[pTama];
	char *term = "\0";
//	cout<<"POR RE::::   "<<strlen(charRetur)<<endl;
	memset(charRetur,0,sizeof(charRetur));

	int elemento = pInicio; //entero asociado al aumento en bucle
	int controlReturn = _pinitialCounterConsts; //entero de control para char de retorno

	while(controlReturn<=pTama){ // ciclo para recorrer los arreglos y tomar los caracteres especificos, mientras el entero elemento sea menor al final
		charRetur[controlReturn] = pCadena[elemento]; // recupera valor
		//cout<<"EL CHAR: "<<pCadena[elemento]<<"    EN POCICION: "<<controlReturn<<endl;

		elemento++; // aumenta variable
		controlReturn++; // aumenta variable
	}

	charRetur[controlReturn] = *term;

	//cout<<"POR RETORNAR::::::::   "<<(charRetur)<<endl;
	//cout<<"POR RETORNAR::::::::   "<<strlen(charRetur)<<endl;

	return charRetur; // retorna el arreglo
}

/**
 * @breif Metodo que realiza conversion de base hexadecimal a binario
 * @param char pHexadechar Cadena a convertir
 * @return Devuelve un puntero a una cadena de caracteres
 */
char * conversions::hexaConvBina(char pHexadechar[])
{
	int i=_pinitialCounterConsts;
	char* binaryNumb = new char[_pBusArrayConsts];
	memset(binaryNumb,0,sizeof(binaryNumb));

	//cout<<"Se debe parsear: "<<pHexadechar<<endl;
	while(pHexadechar[i]) // ciclo para recorrer el arreglo y obtener cada valor
	{
		switch(pHexadechar[i]) //evalua el char
		{
		case '0': strcat(binaryNumb,"0000"); break;
		case '1': strcat(binaryNumb,"0001"); break;
		case '2': strcat(binaryNumb,"0010"); break;
		case '3': strcat(binaryNumb,"0011"); break;
		case '4': strcat(binaryNumb,"0100"); break;
		case '5': strcat(binaryNumb,"0101"); break;
		case '6': strcat(binaryNumb,"0110"); break;
		case '7': strcat(binaryNumb,"0111"); break;
		case '8': strcat(binaryNumb,"1000"); break;
		case '9': strcat(binaryNumb,"1001"); break;
		case 'A': strcat(binaryNumb,"1010"); break;
		case 'B': strcat(binaryNumb,"1011"); break;
		case 'C': strcat(binaryNumb,"1100"); break;
		case 'D': strcat(binaryNumb,"1101"); break;
		case 'E': strcat(binaryNumb,"1110"); break;
		case 'F': strcat(binaryNumb,"1111"); break;
		case 'a': strcat(binaryNumb,"1010"); break;
		case 'b': strcat(binaryNumb,"1011"); break;
		case 'c': strcat(binaryNumb,"1100"); break;
		case 'd': strcat(binaryNumb,"1101"); break;
		case 'e': strcat(binaryNumb,"1110"); break;
		case 'f': strcat(binaryNumb,"1111"); break;

		//default:  cout<<"Digito hexadecimal no admitido "<<pHexadechar[i]; //cath por si no corresponde a ninguno de los tipos
		}
		//cout<<"Numero de caracter:"<< i<< "   Valor: "<< pHexadechar[i]<<endl;
		i++;
	}

	//cout<<"Binario equivalente: "<< binaryNumb<<endl;

	return binaryNumb; //Devuelve el arreglo
}

/**
 * @breif Metodo que realiza conversion de numero en caracteres a entero
 * @param char pCaracter Numero en caracteres que se desea convertir
 * @return Devuelve un entero
 */

int conversions::parsearCharAInt(char pCadenaEntero[]){
	int intReturn; //entero para el retorno
	intReturn = atoi (pCadenaEntero); //conversion de la cadena al numero
	return intReturn; //retorno de la funcion

}

/**
 * @breif Convierte una cadena de caracteres en formato binario y lo hace un entero
 * @param char * pBinario Cadena de caracteres que se desea parsear
 * @return Devuelve un entero correspondiente
 */

long conversions::binarioDecimal(char pBinario[]){

	long intReturn = _pinitialCounterConsts; // le da el valor de 0
	int i = _pinitialCounterConsts; // le da el valor de 0
	int tama = strlen(pBinario); //asigna el valor de la longitud del arreglo que imgresa

	while(i<tama){ //while para recorrer los elementos
		char u = pBinario[i]; // agarra un caracter
		char * ptr = &u; //crea puntero a este
		if (comparaCadenayPuntero("1", ptr)){ //compara si es 1
			intReturn = intReturn + (exponencia(2, (tama-(i+1)))); //realiza la suma para la exponencia del 2 correspondiente a la posicion
			i++; //aumenta variable

		}else{
			i++; //aumenta variable
		}
	}
	return intReturn; //retorna el entero
}

/**
 * @breif Metodo que se encarga de elevar a una potencia cierto numero
 * @param int pnumero Numero que se desea elevar
 * @param int pExpo Numero para la potencia
 * @return Devuelve un entero resultante
 */

long conversions::exponencia(int pnumero, int pExpo){
	long intReturn = (long) pnumero; //numero q entra
	int i = pExpo-1; //se encarga de llevar el control de la exponencia

	if (pExpo == 0){ //compara si es 0
		return 1; //retorna un 1 en este caso
	}else{
		while (i>0){ //ciclo para la exponencia
			intReturn = (intReturn*pnumero); //asigna nuevo valor
			i--; //decrece la variable
		}

		return intReturn; //retorna el valor
	}
}

int conversions::safeLongToInt(long l) {

	// return (int) Math.max(Math.min(Integer.MAX_VALUE, l), Integer.MIN_VALUE);

}

/**
 * @breif Metodo compara un arreglo con array al que apunta un puntero
 * @param char pCadenaEntero[] Cadena con que comparar
 * @param char * pCadenaptr Puntero para comparar
 * @return Devuelve un entero 1 si es cierto o 0 falso
 */
int conversions::comparaCadenayPuntero(char pCadenaEntero[], char* pCadenaptr){
	int t = strlen(pCadenaEntero); //para saber cuando terminar
	int i = _pinitialCounterConsts; //para llevar recorrido

	while (i<t){ //ciclo para avanzar por los arreglos
		if ((*(pCadenaptr +i)) == pCadenaEntero[i]){ //revisa si los valores son iguales
			i++; //aumenta la variable
		}else{
			//cout<<"FALSE"<<endl;
			return false; //retorna falso
		}
	}
	//cout<<"TRUE"<<endl;
	return true; //si recorre todo y termina devuelve verdadero
}

/**
 * @breif Metodo pasa un numero en decimal a una cadena de caracteres de este en binaro
 * @param long pNumero Numero que se desea obtener su cadena de caracteres binaria
 * @return Devuelve
 */
char * conversions::decimalABinario(long pNumero){
	//cout<<"Esssssssssss:      "<<pNumero<<endl;

	char* decimalNumero=new char[_pBusArrayConsts];
	memset(decimalNumero,0,sizeof(decimalNumero));

	int contDeIterativo=_pinitialCounterConsts;
	int contMaxBinary = _pBusArrayConsts;
	int Acomodar;
	int arrayNumero[_pBusArrayConsts+1];
	std::string s;
	std::stringstream out;

	while(pNumero>0)
	{
		arrayNumero[contDeIterativo]=pNumero%2;
		contDeIterativo++;
		pNumero /= 2;
	}
	while(contMaxBinary+1!=0){
		if(contMaxBinary==contDeIterativo-1){
			for(Acomodar=contDeIterativo-1;Acomodar>=0;Acomodar--){
				out << arrayNumero[Acomodar];
			}
			s = out.str();
			const char * c = s.c_str();
			strcat(decimalNumero,c);
			break;
		}
		strcat(decimalNumero,"0");
		contMaxBinary--;
	}
	//cout<<"CCRACK LUISFER:       :::::::::::::::"<<decimalNumero<<endl;
	return decimalNumero;
}

/**
 * @breif Metodo que toma un char y cambia sus caracteres de posicion
 * @param char pChart[] Cadena que se desea modificar
 * @return Devuelve un char del cambio de posicion de los bits
 */
char * conversions::voltearChar(char pChart[]){
	char* nuevoChar= new char[_pBusArrayConsts]; //puntero al arreglo
	memset(nuevoChar,0,sizeof(nuevoChar)); //seteo de memoria a 0

	int i = strlen(pChart); //entero para llevar el conteo regresivo de caracteres en el arreglo entrante
	int pos = _pinitialCounterConsts; //entero para el orden del arreglo por generar

	while (i>0){ //ciclo para el cambio
		nuevoChar[pos] = pChart[i-1]; // asignacion de valores de arreglo
		pos++; //aumento de variable de posicion para el nuevo arreglo
		i--;// disminucion de variable de posicion en arreglo entrante
	}

	return nuevoChar; //retorno de char

}
