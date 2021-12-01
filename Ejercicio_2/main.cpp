/*
	Integrantes:
	Victor Segura Pereira
	Emanuel Soto Leal
*/

#include<iostream>
#include<sstream>
#include <fstream>
using namespace std;

struct Estudiante {
	
	string id;
	string nombre;
	string numeroDeCuenta;
	int priori;
	
};

struct nodo {
	
	struct Estudiante estudiante;
	struct nodo *sgte;
	
};

struct cola {
	
	nodo *delante;
	nodo *atras;
	
};

struct nodo *crearNodo(struct Estudiante e) {
	
	struct nodo *nuevoNodo = new(struct nodo);
	nuevoNodo->estudiante = e;
	
	return nuevoNodo;
	
}

void encolar(struct cola &q, Estudiante e) {
	
	struct nodo *aux = crearNodo(e);
	aux->sgte = NULL;
	if (q.delante == NULL){
		q.delante = aux;
	}
	else{
		(q.atras)->sgte = aux;
	}
	q.atras = aux;
	
}

string muestraCola(struct cola q) {
	
	struct nodo *aux;
	aux = q.delante;
	stringstream x;
	
	while (aux != NULL) {
		
		x << "El id es: " << aux->estudiante.id << endl;
		x << "El nombre es: " << aux->estudiante.nombre << endl;
		x << "El numero de cuenta es: " << aux->estudiante.numeroDeCuenta << endl;
		x << "El tipo de beca es: ";
		if (aux->estudiante.priori == 1){
			x << "A\n";
		}else if(aux->estudiante.priori == 2){
			x << "B\n";
		}else if(aux->estudiante.priori == 3){
			x << "C\n";
		}
		
		x<<"\n------------------------------\n";
		
		aux = aux->sgte;
		
	}
	return x.str();
}

void ordenarPrioridad(struct cola &q) {
	
	struct nodo *aux1, *aux2;
	int p_aux;
	string nombre_aux, extension_aux;
	aux1 = q.delante;
	
	while (aux1->sgte != NULL) {
		
		aux2 = aux1->sgte;
		
		while (aux2 != NULL) {
			
			if (aux1->estudiante.priori > aux2->estudiante.priori) {
				
				p_aux = aux1->estudiante.priori;
				Estudiante est_aux = aux1->estudiante;
				aux1->estudiante.priori = aux2->estudiante.priori;
				aux1->estudiante = aux2->estudiante;
				aux2->estudiante.priori = p_aux;
				aux2->estudiante = est_aux;
				
			}
			
			aux2 = aux2->sgte;
			
		}
		
		aux1 = aux1->sgte;
		
	}
	
}

void insertar(struct cola &q, Estudiante e) {
	
	encolar(q, e);
	ordenarPrioridad(q);
	
}

void menu() {
	
	cout<<"Bienvenido al Sistema de Becas escolares!\n\n";
	cout << " 1. Anidir Estudiante a la cola\n";
	cout << " 2. Mostrar cola de estudiantes\n";
	cout << " 3. Salir\n\n";
	cout << "Seleccione una opcion:\n\n";
	
}

int main() {
	
	ofstream  archivo;
	struct cola q;
	q.delante = NULL;
	q.atras = NULL;
	Estudiante e;
	string id;
	string nombre;
	string cuenta;
	char prioridad;
	
	int op;
	
	do {
		
		menu();
		cin>>op;
		
		system("pause");
		system("cls");
		
		switch (op) {
		
		case 1:
		{
			
			cout<<"Ingrese los datos que se le solicitan a continuacion:\n";
			cin.ignore();
			cout <<"\nIngrese el id del Estudiante:\t";
			getline(cin, id);
			cout <<"\nIngrese el nombre del Estudiante:\t";
			getline(cin, nombre);
			cout <<"\nIngrese el numero de cuenta del Estudiante:\t";
			getline(cin, cuenta);
			a:
			cout <<"\nIngrese el tipo de beca del estudiante (A, B o C):\t";
			cin>> prioridad;
			
			if (prioridad == 'A') {
				e.priori = 1;
			} else if (prioridad == 'B') {
				e.priori = 2;
			} else if (prioridad == 'C'){
				e.priori = 3;
			} else {
				goto a;
			}
			
			e.id = id;
			e.nombre = nombre;
			e.numeroDeCuenta = cuenta;
			
			insertar(q,e);
			cout <<"\n\n Estudiante aniadido a la cola!\n\n";
			archivo.open(e.nombre + ".txt",ios::app);
			
			archivo<<e.id<< '-'
				<<e.nombre<< '-'
				<<e.numeroDeCuenta<< '-'
				<<e.priori<<endl;
			archivo.close();
			system("pause");
			system("cls");
			break;
		}
		case 2:
		{
			cout << "Mostrando estudiantes en el orden de las becas\n\n";
			
			if (q.delante != NULL){
				cout<<muestraCola(q)<<endl;
			}
			else{
				cout << "\n\n\t\tCola vacia...!" << endl;
			}
			system("pause");
			system("cls");
			
			break;
		}
		case 3:
		{
			cout << "\n\tSaliendo..!" << endl;
			system("pause");
			exit(0);
		}
		default:
		{
			cout << "\n\tOpcion invalida..!" << endl;
			system("pause");
			system("cls");
			break;
		}
		}
		
	} while (op != 3);
	
	return 0;
	
}
