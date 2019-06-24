#ifndef ABB_H
#define ABB_H

#include "Nodo.h"

const int DOS_HIJOS = 1, HIJO_IZQUIERDO = 2, HIJO_DERECHO = 3, SIN_HIJOS = 4;

class Abb{
	private:
		Nodo* raiz;

	public:
		Abb();


		Abb(Nodo* raiz);


		~Abb();


		bool insertar_nodo(unsigned numero, Cliente* datos);


		bool eliminar_nodo(unsigned numero);


		void swap(Nodo* nodo1, Nodo* nodo2);


		Nodo* buscar_padre(unsigned numero);


		Nodo* buscar_padre(Nodo* comienzo, unsigned numero);


		Nodo* buscar_nodo(unsigned numero);

		Nodo* buscar_nodo(Nodo* comienzo, unsigned numero);


		bool es_vacio();

		Nodo* buscar_siguiente_inorder(Nodo* nodo);

		Nodo* buscar_anterior_inorder(Nodo* nodo);

		unsigned detectar_tipo(Nodo* nodo);

		bool eliminar_con_dos_hijos(Nodo* nodo);

		bool eliminar_con_hijo_derecho(Nodo* nodo);

		bool eliminar_con_hijo_izquierdo(Nodo* nodo);

		bool eliminar_sin_hijos(Nodo* nodo);

		void mostrar_arbol();

		void mostrar_in_order(Nodo* nodo);

		void mostrar(Nodo* nodo);
};

#endif