#ifndef CLIENTE_H
#define CLIENTE_H

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

const int MAX_NOMBRES = 30;
const unsigned DESCUENTO_INDIVIDUO = 10, DESCUENTO_FAMILIA = 35;

class Cliente{
	private:
		unsigned descuento;
	public:
		Cliente();
		unsigned obtener_descuento();
		void asignar_descuento(unsigned descuento);
		virtual void calcular_descuento()=0;
		virtual void mostrar()=0;
		virtual ~Cliente() = 0;
};



class Individuo: public Cliente{
	private:
		string nombre;
	public:
		Individuo(string nombre);
		void calcular_descuento();
		void mostrar();
		~Individuo();
};

class Familia: public Cliente{
	private:
		string nombres[MAX_NOMBRES];
		unsigned cantidad_integrantes;
	public:
		Familia(string nombres[MAX_NOMBRES], unsigned cantidad_integrantes);
		void calcular_descuento();
		void mostrar();
		~Familia();


};


#endif