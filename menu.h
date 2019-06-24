#ifndef MENU_H
#define MENU_H

#include "Abb.h"


const int TIPO_FAMILIA = 2, TIPO_INDIVIDUO = 1;
const unsigned NUMERO_PADRON = 102792;

class Menu{
	private:
		Abb* arbol_de_busqueda;
		unsigned numero_actual;
	public:
		Menu();

		void leer_archivo(char const* clientes_txt);

		void menu_de_opciones(char const* archivo);

	private:
		void agregar_cliente(unsigned tipo_de_cliente, string nombres[MAX_NOMBRES],unsigned cantidad_nombres,unsigned numero);

		unsigned dividir_linea_leida(string linea_leida, unsigned &numero, string nombres[MAX_NOMBRES], unsigned &cantidad_nombres);

		void dar_de_baja();		

		void mostrar_arbol();

		void buscar_cliente();

		void agregar_nuevo_cliente();

		void ejecutar_opcion(int opcion);
};

#endif
