/*
 * ListaSimple.h
 *
 *  Created on: 1 de may. de 2016
 *      Author: gabriel
 */

#ifndef LinkedList_h
#define LinkedList_h

#include <iostream>
#include <string>
using namespace std;

#include "NodoSimple.h"

template<class AnyType>
class ListaSimple
{
private:
	NodoSimple<AnyType> * _Head;
	int _Length;

public:
	/**
	 * @brief Metodo constructor de LinkedList
	 */
	ListaSimple();

	/**
	 * @brief Metodo inserta un nodo en la lista
	 * @param NodoSimple<AnyType>* pNewItem
	 */
	void insertItem( NodoSimple<AnyType> * pNewItem);

	/**
	 * @breif Metodo inserta un elemento a la lista
	 * @param AnyType* pItem
	 */
	void insertData(AnyType* pItem);

	/**
	 * @brief Metodo elimina el elemento de la lista que contenga el mismo pItemKey
	 * @param string pItemKey
	 */
	bool removeItem( string pItemKey );

	/**
	 * @brief Metodo obtiene el elemento que contiene el mismo pItemKey
	 * @param string pItemKey
	 * @return NodoSimple<AnyType>*
	 */
	NodoSimple<AnyType> * getItem( string pItemKey );

	void insertarOrdenadoNodo( NodoSimple<AnyType> * pNewItem);

	void insertarDatoOrdenado(AnyType* pItem);



	/**
	 * @brief Metodo devuelve el nodo en la posicion
	 * @param int pPosition
	 * @return NodoSimple<AnyType>*
	 */
	NodoSimple<AnyType> * getItemByPosition(int pPosition);

	/**
	 * @brief Metodo devuelve el dato segun la clave
	 * @param string pItemKey
	 * @return AnyType*
	 */
	AnyType* getDataItem(string pItemKey);

	/**
	 * @brief Metodo imprime la lista
	 */
	void printList();

	void ordenarLista();

	/**
	 * @brief Metodo devuelve el atributo _Lenght
	 * @return int
	 */
	int getLength();

	/**
	 * @brief Metodo destructor de LinkedList
	 */
	~ListaSimple();
};


template<class AnyType>
ListaSimple<AnyType>::ListaSimple()
{
	this->_Head = new NodoSimple<AnyType>{"c",NULL,NULL};
	this->_Length = 0;
}

template <class AnyType>
void ListaSimple<AnyType>::insertItem( NodoSimple<AnyType> * newItem )
{
	if (!_Head->getNext())
	{
		_Head->setNext(newItem);
		this->_Length++;
		return;
	}
	NodoSimple<AnyType> * aux1 = this->_Head;
	NodoSimple<AnyType> * aux2 = this->_Head;
	while (aux2)
	{
		aux1 = aux2;
		aux2 = aux1->getNext();
	}
	aux1->setNext(newItem);

	newItem->setNext(NULL);
	this->_Length++;
}

template <class AnyType>
void ListaSimple<AnyType>::insertarOrdenadoNodo(NodoSimple<AnyType> * pNewItem)
{
	cout<< "entre" << endl;
	NodoSimple<AnyType> * current = this->_Head;
	/* Special case for the head end */
	if (_Head->getVal() == NULL)
	{
		cout<< "1" << endl;
		pNewItem->setNext(_Head);
		this->_Head= pNewItem;
		this->_Length++;
	}
	else if((*_Head->getVal()) > (*pNewItem->getVal())){
		cout<< "2" << endl;
		cout<< *_Head->getVal() << endl;
		cout << (*_Head->getVal()) << ">" <<(*pNewItem->getVal()) << endl;
		pNewItem->setNext(this->_Head);
		this->_Head= pNewItem;
	}
	else
	{
		cout<< *_Head->getVal() << endl;
		cout<< "3" << endl;

		NodoSimple<AnyType> * temp = current->getNext();
		/* Locate the node before the point of insertion */
		NodoSimple<AnyType> * prev;
		while (temp->getVal() != NULL && *current->getVal() < *pNewItem->getVal())
		{
			cout<< "4" << endl;
			cout<< *current->getVal()<< "<"<< *pNewItem->getVal() << endl;
			temp=temp->getNext();
			prev = current;
			current = current->getNext();

		}
		cout<< *current->getVal()<<endl;
		cout<< "5" << endl;
		if(temp->getVal()==NULL && *current->getVal() < *pNewItem->getVal() ){
			pNewItem->setNext(current->getNext());
			current->setNext(pNewItem);
		}else{
			cout<< prev->getVal() << endl;
			cout<< "Aqui" << endl;
			pNewItem->setNext(current);
			prev->setNext(pNewItem);
		}

	}

	cout<<  "Fin"<< endl;
	cout<<  this->_Length++<< endl;

}

template<class AnyType>
void ListaSimple<AnyType>::insertData(AnyType* pItem){
	NodoSimple<AnyType> *nodo = new NodoSimple<AnyType>{"c", pItem, NULL};
	insertItem(nodo);
}

template<class AnyType>
void ListaSimple<AnyType>::insertarDatoOrdenado(AnyType* pItem){
	NodoSimple<AnyType> *nodo = new NodoSimple<AnyType>{"c", pItem, NULL};
	insertarOrdenadoNodo(nodo);
}

template<class AnyType>
bool ListaSimple<AnyType>::removeItem( string itemKey )
{
	if (!_Head->getNext()) return false;
	NodoSimple<AnyType> * aux1 = this->_Head;
	NodoSimple<AnyType> * aux2 = this->_Head;
	while (aux2)
	{
		if (aux2->getKey() == itemKey)
		{
			aux1->setNext(aux2->getNext());
			free (aux2);
			this->_Length--;
			return true;
		}
		aux1 = aux2;
		aux2 = aux1->getNext();
	}
	return false;
}

template<class AnyType>
NodoSimple<AnyType> * ListaSimple<AnyType>::getItem( string itemKey )
{
	NodoSimple<AnyType> * aux1 = this->_Head;
	NodoSimple<AnyType> * aux2 = this->_Head;
	while (aux2)
	{
		aux1 = aux2;
		if ((aux1 != this->_Head) && (aux1->getKey() == itemKey))
			return aux1;
		aux2 = aux1->getNext();
	}
	return NULL;
}

template<class AnyType>
NodoSimple<AnyType>* ListaSimple<AnyType>::getItemByPosition(int pPosition){
	NodoSimple<AnyType>* nodo = this->_Head;
	for(int index = 1; index < pPosition+1; index++){
		nodo = nodo->getNext();
	}
	return nodo;
}

template<class AnyType>
AnyType* ListaSimple<AnyType>::getDataItem(string pItemKey){
	NodoSimple<AnyType>* nodo = getItem(pItemKey);
	return nodo->getVal();
}

template<class AnyType>
void ListaSimple<AnyType>::printList()
{
	if (this->_Length == 0)
	{
		cout << "\n{ }\n";
		return;
	}
	NodoSimple<AnyType> * aux1 = this->_Head;
	NodoSimple<AnyType> * aux2 = this->_Head;
	cout << "\n{ ";
	while (aux2)
	{
		aux1 = aux2;
		if (aux1 != this->_Head)
		{
			cout << *aux1->getVal() << ":"<< aux1->getKey(); //AQUI CAMBIE KEY POR VAL
			if (aux1->getNext()) cout << ", ";
			else cout << " ";
		}

		aux2 = aux1->getNext();
	}
	cout << "}\n";
}

template<class AnyType>
int ListaSimple<AnyType>::getLength()
{
	return this->_Length;
}

template<class AnyType>
ListaSimple<AnyType>::~ListaSimple()
{
	NodoSimple<AnyType> * aux1 = this->_Head;
	NodoSimple<AnyType> * aux2 = this->_Head;
	while (aux2)
	{
		aux1 = aux2;
		aux2 = aux1->getNext();
		if (aux2) delete aux1;
	}
}
#endif
