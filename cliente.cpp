#include "cliente.h"


using namespace std;

Cliente::Cliente(){
	this->descuento = 0;;
}

unsigned Cliente::obtener_descuento(){
	return descuento;
}

void Cliente::asignar_descuento(unsigned descuento){
	this->descuento = descuento;
}

Individuo::Individuo(string nombre):Cliente(){
	this->nombre = nombre;
}

Individuo::~Individuo(){

}


void Individuo::calcular_descuento(){
	asignar_descuento(DESCUENTO_INDIVIDUO);
}

void Individuo::mostrar(){
	cout << nombre << endl;
}

Familia::Familia(string nombres[MAX_NOMBRES],unsigned cantidad_integrantes):Cliente(){
	for(unsigned int i =0;i < cantidad_integrantes;i++){
		this->nombres[i] = nombres[i];
	}
	this->cantidad_integrantes = cantidad_integrantes;
}

void Familia::calcular_descuento(){
	asignar_descuento(DESCUENTO_FAMILIA);
}

void Familia::mostrar(){
	for(unsigned int i=0; i < cantidad_integrantes;i++){
		cout << nombres[i] << ",";
	}
	cout << endl;
}

Familia::~Familia(){
	
}