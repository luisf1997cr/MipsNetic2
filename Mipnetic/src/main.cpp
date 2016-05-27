/*
 * main.cpp
 *
 *  Created on: 2 de may. de 2016
 *      Author: gabriel
 */


#include <iostream>
#include "Structures/ListaSimple.h"
#include "ConsSys/Consts.h"
#include "DataManager/conversions.h"
#include "MipsMars/archmm.h"


#include<iostream>


using namespace std;
int main(){

	//	NodoSimple<char> *e = new NodoSimple<char>{"h", "ggg", 0};

	//ListaSimple<char>* prueba = new ListaSimple<char>();


	//	prueba->insertItem(e);

	/**
	conversions m;

	archmm j;

	char * n ="2402000d";
	char * a = m.hexaConvBina(n);

	cout<<"Es este loco: "<<a<<endl;

	char * w ="123";

	int b;

	b = m.parsearCharAInt(w);=

	cout<<b+1<<endl;

	char * v= j.tomarBits(a, 2, 6);
binarioDecimal(w)
	cout<<"Al tomar: "<<v<<endl;
	 */

	hamt:
	arch_mm p;
	archmm * dos =new archmm();
	char tipo[] ="DATA";

	char path[] = "/home/acacia/workspace/data";

	char pathi[] = "/home/gabriel/Escritorio/ad";

	char path4[] = "/home/gabriel/Escritorio/AQUI.txt";

	char l[] = "00100100000000100000000000001101";


	conversions u;
	//u.tomarBits(l, 16, 29, 14);
	dos->leerFicheroCompi(path, tipo);

	//cout<<dos->tomarBits(l, 16, 31, 15)<<endl;
	//cout<<dos->tomarBits(l, 16, 31, 15)<<endl;
	//cout<<dos->tomarBits(l, 16, 31, 15)<<endl;

	//	char w[] = "10001110101101010000000000000000";
	//
	//
	//	int i = 8;
	//
	//	long o = (long) i



	//	conversions b;
	//	int n = 654666445;
	//	int r = 46;
	//
	//	cout<< r<<endl;
	//	int MoverDerecha = r>>2;
	//	cout<< MoverDerecha<<endl;
	//	int MoverIzquierda= MoverDerecha<< 3;
	//	cout<< MoverIzquierda<<endl;
	//
	//	int andi = MoverIzquierda & n;
	//	cout<< andi<<endl;





	//	cout<<dos->tomarBits(w, 3, 6)<<endl;
	//	conversions b;
	//	char h[] ="8eb50000";
	//
	//	long i = 12;
	//
	//	char *o = (b.voltearChar(h));
	//
	//	cout <<o<<endl;

	return 0;

}
