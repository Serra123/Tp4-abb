#include <iostream>
#include "Abb.h"

Abb::Abb(){
	raiz = NULL;
}

Abb::Abb(Nodo* raiz){
	this->raiz = raiz;
}

Abb::~Abb(){
	while(!es_vacio()){
		eliminar_nodo(raiz->obtener_numero());
	}
}

Nodo* Abb::buscar_nodo(unsigned numero){
	return buscar_nodo(raiz, numero);
}

Nodo* Abb::buscar_nodo(Nodo* comienzo, unsigned numero){
	Nodo* nuevo_comienzo = comienzo;
	if(nuevo_comienzo == NULL){
		return nuevo_comienzo;
	}
	unsigned aux = comienzo->obtener_numero();
	if(numero < aux){
		nuevo_comienzo = nuevo_comienzo->obtener_hijo_izquierdo();
		return buscar_nodo(nuevo_comienzo,numero);
	}else if(numero > aux){
		nuevo_comienzo = nuevo_comienzo->obtener_hijo_derecho();
		return buscar_nodo(nuevo_comienzo,numero);
	}
	return comienzo;
}

Nodo* Abb::buscar_padre(unsigned numero){
	return buscar_padre(raiz, numero);
}

Nodo* Abb::buscar_padre(Nodo* comienzo, unsigned numero){
	unsigned aux = comienzo->obtener_numero();
	if(aux == numero){
		if(comienzo == raiz){
			return NULL;
		}else{
			return comienzo;
		}
	}
	if(numero < aux){
		Nodo* hijo_izquierdo = comienzo->obtener_hijo_izquierdo();
		if(hijo_izquierdo == NULL || numero == hijo_izquierdo->obtener_numero()){
			return comienzo;
		}else return buscar_padre(comienzo->obtener_hijo_izquierdo(),numero);
	}else{
		Nodo* hijo_derecho = comienzo->obtener_hijo_derecho();
		if(hijo_derecho == NULL || numero == hijo_derecho->obtener_numero()){
			return comienzo;
		}else{
			return buscar_padre(comienzo->obtener_hijo_derecho(),numero);
		}	
	}
}

bool Abb::insertar_nodo(unsigned numero, Cliente* datos){
	Nodo* aux = Abb::buscar_nodo(numero);
	if(aux){
		cout << "El numero que quiere asignar ya se encuentra ocupado!!!" << endl;
		cout << "Nuevo Numero: "; 
		numero ++;
		cout << numero;
		return insertar_nodo(numero,datos);
	}else{
		Nodo* nuevo_nodo = new Nodo(numero, datos);
		Nodo* padre = buscar_padre(numero);
		if(numero < padre->obtener_numero()){
			padre->asignar_hijo_izquierdo(nuevo_nodo);
			return true;
		}else{
			padre->asignar_hijo_derecho(nuevo_nodo);
			return true;	
		}
	}
}

Nodo* Abb::buscar_siguiente_inorder(Nodo* nodo){
	Nodo* siguiente = nodo->obtener_hijo_derecho();
	Nodo* aux = siguiente->obtener_hijo_izquierdo();
	if(aux == NULL){
		return siguiente;
	}else{
		while(aux){
			siguiente = aux;
			aux = siguiente->obtener_hijo_izquierdo();
		}
	}
	return siguiente;
}

Nodo* Abb::buscar_anterior_inorder(Nodo* nodo){
	Nodo* anterior = nodo->obtener_hijo_izquierdo();
	Nodo* aux = anterior->obtener_hijo_derecho();
	if(aux == NULL){
		return anterior;
	}else{
		while(aux){
			anterior = aux;
			aux = anterior->obtener_hijo_derecho();
		}
	}
	return anterior;
}

bool Abb::eliminar_nodo(unsigned numero){
	Nodo* aux;
	aux = buscar_nodo(numero);
	bool eliminado = false;
	if(aux == NULL){
		cout << "El nodo que quiere eliminar no se encuentra en el arbol" << endl;
		return eliminado;
	}else{
		unsigned tipo_de_nodo = detectar_tipo(aux);
		switch(tipo_de_nodo){
			case DOS_HIJOS:
				eliminado = eliminar_con_dos_hijos(aux);
				break;
			case HIJO_IZQUIERDO:
				eliminado = eliminar_con_hijo_izquierdo(aux);
				break;
			case HIJO_DERECHO:
				eliminado = eliminar_con_hijo_derecho(aux);
				break;
			default:
				 eliminado = eliminar_sin_hijos(aux); 
		}
		return eliminado;
	}
}

unsigned Abb::detectar_tipo(Nodo* nodo){
	if(nodo->obtener_hijo_izquierdo() && nodo->obtener_hijo_derecho()){
		return DOS_HIJOS;
	}else if(nodo->obtener_hijo_izquierdo()){
		return HIJO_IZQUIERDO;
	}else if(nodo->obtener_hijo_derecho()){
		return HIJO_DERECHO;
	}else return SIN_HIJOS;
}

bool Abb::eliminar_con_dos_hijos(Nodo* nodo){
	Nodo* siguiente = buscar_siguiente_inorder(nodo);
	swap(siguiente,nodo);
	return eliminar_sin_hijos(siguiente);
}

bool Abb::eliminar_con_hijo_derecho(Nodo* nodo){
	return eliminar_con_dos_hijos(nodo);
}

bool Abb::eliminar_con_hijo_izquierdo(Nodo* nodo){
	Nodo* anterior = buscar_anterior_inorder(nodo);
	swap(anterior, nodo);
	return eliminar_sin_hijos(anterior);
}

bool Abb::eliminar_sin_hijos(Nodo* nodo){
	unsigned numero = nodo->obtener_numero();
	Nodo* padre = buscar_padre(numero);
	if(padre == NULL){
		raiz = NULL;
	}else{
		if(padre->obtener_hijo_izquierdo() == nodo){
			padre->asignar_hijo_izquierdo(NULL);
		}else padre->asignar_hijo_derecho(NULL);
	}
	delete nodo->obtener_datos();
	delete nodo;
	return true;
}

void Abb::swap(Nodo* nodo1, Nodo* nodo2){
	unsigned numero_aux = nodo1->obtener_numero();
	Cliente* cliente_aux = nodo1->obtener_datos();
	nodo1->asignar_numero(nodo2->obtener_numero());
	nodo1->asignar_datos(nodo2->obtener_datos());
	nodo2->asignar_numero(numero_aux);
	nodo2->asignar_datos(cliente_aux);
}

bool Abb::es_vacio(){
	return raiz;
}

void Abb::mostrar_arbol(){
	mostrar_in_order(raiz);
}

void Abb::mostrar_in_order(Nodo* nodo){
	if(nodo){
		mostrar_in_order(nodo->obtener_hijo_izquierdo());
		nodo->mostrar();
		mostrar_in_order(nodo->obtener_hijo_derecho());
	}
}

