#include "Nodo.h"

Nodo::Nodo(unsigned numero, Cliente* datos){
	this->numero = numero;
	this->datos = datos;
	hijo_izquierdo = NULL;
	hijo_derecho = NULL;
}

Nodo* Nodo::obtener_hijo_izquierdo(){
	return hijo_izquierdo;
}

Nodo* Nodo::obtener_hijo_derecho(){
	return hijo_derecho;
}

Cliente* Nodo::obtener_datos(){
	return datos;
}

unsigned Nodo::obtener_numero(){
	return numero;
}

void Nodo::asignar_numero(unsigned numero){
	this->numero = numero;
}

void Nodo::asignar_hijo_izquierdo(Nodo* hijo){
	hijo_izquierdo = hijo;
}

void Nodo::asignar_hijo_derecho(Nodo* hijo){
	hijo_derecho = hijo;
}

void Nodo::asignar_cliente(Cliente* cliente){
	datos = cliente;
}

void Nodo::asignar_datos(Cliente* datos){
	this->datos = datos;
}

void Nodo::mostrar(){
	cout << numero << ",";
	datos->mostrar();
	cout << endl;
	
}
