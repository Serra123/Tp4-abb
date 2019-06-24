#include "menu.h"


Menu::Menu(){
	arbol_de_busqueda = new Abb();
	numero_actual = NUMERO_PADRON;
}

void Menu::leer_archivo(char const* clientes_txt){
	string linea_leida;
	ifstream entrada;
	entrada.open(clientes_txt);
	if(!entrada.is_open()){
		cout << "Error, no se pudo abrir el archivo" << endl;
	}else{
		while(getline(entrada,linea_leida)){
			unsigned numero;
			string nombres[MAX_NOMBRES];
			unsigned cantidad_nombres;
			unsigned tipo_de_cliente = dividir_linea_leida(linea_leida,numero,nombres,cantidad_nombres);
			agregar_cliente(tipo_de_cliente ,nombres ,cantidad_nombres ,numero);
		}
		entrada.close();
	}
}

void Menu::agregar_cliente(unsigned tipo_de_cliente, string nombres[MAX_NOMBRES],unsigned cantidad_nombres,unsigned numero){
	if(tipo_de_cliente == TIPO_FAMILIA){
		Familia* nueva_familia = new Familia(nombres,cantidad_nombres);
		arbol_de_busqueda->insertar_nodo(numero,nueva_familia);
	}else if (tipo_de_cliente == TIPO_INDIVIDUO){
		string nombre = nombres[0];
		Individuo* nuevo_individuo = new Individuo(nombre);
		arbol_de_busqueda->insertar_nodo(numero,nuevo_individuo);
	}
}


unsigned Menu::dividir_linea_leida(string linea_leida,unsigned &numero, string nombres[MAX_NOMBRES],unsigned &cantidad_nombres){
	string aux;
	unsigned int i = 0;
	unsigned pos = linea_leida.find(',');
	numero = stoul(linea_leida.substr(0,pos));
	linea_leida = linea_leida.substr(pos+1);
	pos = linea_leida.find(',');
	while(pos != string::npos){
		nombres[i++] = linea_leida.substr(0,pos);
		linea_leida = linea_leida.substr(pos+1);
		pos = linea_leida.find(',');
	}
	cantidad_nombres = i + 1;
	if(cantidad_nombres > 1){
		return TIPO_FAMILIA;
	}else return TIPO_INDIVIDUO;
}

void Menu::dar_de_baja(){
	int numero;
	cout << "Por favor ingrese el numero del cliente que desea dar de baja";
	cin >> numero;

	bool dado_de_baja = arbol_de_busqueda->eliminar_nodo(numero);
	if(dado_de_baja){
		cout << "El cliente fue dado de baja" << endl;
	}else{
		cout << "El numero de telefono del cliente a eliminar no se encuentra disponible entre los clientes del sistema" << endl;
	}
}

void Menu::mostrar_arbol(){
	arbol_de_busqueda->mostrar_arbol();
}

void Menu::buscar_cliente(){
	int numero;
	cout << "Ingrese numero del cliente a buscar" << endl;
	cin >> numero;

	Nodo* nodo = arbol_de_busqueda->buscar_nodo(numero);
	if(!nodo){
		cout << "El cliente que desea buscar no existe";
	}else{
		cout << "Cliente encontrado, mostrando datos del cliente" << endl;
		nodo->mostrar();
	}
}

void Menu::agregar_nuevo_cliente(){
	string linea_leida;
	cout << "Ingrese los datos del cliente a ingresar siguiendo el siguiente formato:" << endl;
	cout << "NUMERO,NOMBRE1,NOMBRE2,NOMBRE3,->->-> etc" << endl;
	cin >> linea_leida;
	string nombres[MAX_NOMBRES];
	unsigned numero,tipo_de_cliente;
	unsigned cantidad_nombres;
	tipo_de_cliente = dividir_linea_leida(linea_leida,numero,nombres,cantidad_nombres);
	agregar_cliente(tipo_de_cliente,nombres,cantidad_nombres,numero);
	cout << "El cliente fue agregado correctamente" << endl;
}


void Menu::menu_de_opciones(char const* archivo){
	leer_archivo(archivo);
	int opcion;
	do{
		
		cout <<"*"<<" **********************************" <<"*"<< endl;
		cout <<"*"<<"           MENU DE OPCIONES        " <<"*"<< endl;
		cout <<"*"<<" Agregar un Nuevo Cliente       [1]" <<"*"<< endl;
		cout <<"*"<<" Dar de Baja un Cliente         [2]" <<"*"<< endl;
		cout <<"*"<<" Listar Clientes                [3]" <<"*"<< endl;
		cout <<"*"<<" Buscar un cliente              [4]" <<"*"<< endl;
		cout <<"*"<<" Salir                          [5]" <<"*"<< endl;
		cout <<"*"<<"                                   " <<"*"<< endl;
		cout <<"*"<<"  Elija una de las Opciones:       " <<"*"<< endl;
		cout <<"*"<<" **********************************" <<"*"<< endl;

		cin >> opcion;

		switch(opcion){
			case 1:
				agregar_nuevo_cliente();
			break;

			case 2:
				dar_de_baja();
			break;

			case 3:
				mostrar_arbol();
			break;

			case 4:
				buscar_cliente();
			break;

			default:
				cout << "saliendo->->->" << endl;
		}
	}while(opcion != 5);	
}