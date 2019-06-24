#ifndef NODO_H
#define NODO_H

#include "cliente.h"

class Nodo{
	private:
		unsigned numero;
		Cliente* datos;
		Nodo* hijo_izquierdo;
		Nodo* hijo_derecho;
	public:
		Nodo(unsigned numero, Cliente* datos);
		unsigned obtener_numero();
		Cliente* obtener_datos();
		Nodo* obtener_hijo_izquierdo();
		Nodo* obtener_hijo_derecho();
		void asignar_numero(unsigned numero);
		void asignar_cliente(Cliente* cliente);
		void asignar_hijo_izquierdo(Nodo* hijo);
		void asignar_hijo_derecho(Nodo* hijo);
		void asignar_datos(Cliente* datos);
		void mostrar();

};

#endif