#include <string>
#include <iostream>
using namespace std;

//Apuntadores a Funciones

string estiloFormal(string r) {
    return "Estimado usuario, " + r;
};

string estiloAmistoso(string r) {
    return "Hey! " + r;
};

//Manejo de Memoria Dinámica
struct Nodo {
    string texto;
    Nodo* siguiente;
};

//Crear nodo con new
Nodo* crearNodo(const string& texto) {
    Nodo* nuevo = new Nodo;
    nuevo->texto = texto;
    nuevo->siguiente = nullptr;
    return nuevo;
}

//Insertar el nuevo nodo
void insertarFinal(Nodo*& cabeza, const string& texto) {
    Nodo* nodo = crearNodo(texto);
    if (cabeza == nullptr) {
        cabeza = nodo;
    }
    else {
        Nodo* p = cabeza;
        while (p->siguiente != nullptr) {
            p = p->siguiente;
        }

        p->siguiente = nodo;
    }
}

//Mostrar lista
void mostrarLista(Nodo* cabeza) {
    cout << "Contenido de la lista:" << endl;
    for (Nodo* p = cabeza; p != nullptr; p = p->siguiente) {
        cout << "* " << p->texto << endl;
    }

}

//Liberar memoria
void liberarMemoria(Nodo*& cabeza) {
    Nodo* p = cabeza;
    while (p != nullptr) {
        Nodo* siguiente = p->siguiente;
        delete p;
        p = siguiente;
    }
    cabeza = nullptr;
}

int main()
{
    //Declaracion e Inicializacion de Punteros
    int numero = 5;
    int* ptr = &numero;
    cout << "Valor apuntado: " << *ptr << endl;

    //Arrays de Punteros
    const char* respuestas[] = {"Hola, en que puedo ayudarte?","Estoy aprendiendo a responder.","Escribe tu pregunta de otra forma.","Consulta aceptada."
    };
    for (int i = 0; i < 4; ++i) {
        cout << respuestas[i] << endl;
    }

    //Aritmetica de Punteros
    const char** p = respuestas;
    for (int i = 0; i < 4; ++i) {
        cout << endl << * (p + i) << endl;
    }

    //Sizeof
    cout << endl <<"sizeof(int): " << sizeof(int) << endl;
    cout << "sizeof(ptr): " << sizeof(ptr) << endl;
    cout << "sizeof(char): " << sizeof(char) << endl;
    cout << "sizeof(double): " << sizeof(double) << endl;
    cout << "sizeof(float): " << sizeof(float) << endl;

    //Relación entre Arreglos y Punteros
    int datos[] = { 1, 2, 3 };
    int* pd = datos;
    cout << endl;
    cout << "pd[1]: " << pd[1] << endl; // es igual a datos[1]
    cout << "*(pd + 2): " << *(pd + 2) << endl;
    cout << "pd[2] + 2: " << pd[2] + 2 << endl;
    cout << "pd[1] + 3: " << pd[1] + 3 << endl;
    cout << endl;

   //Apuntadores a Funciones
    
    string(*responder)(string);
    responder = estiloAmistoso;
    cout << responder("bienvenido al sistema.") << endl;
    responder = estiloFormal;
    cout << responder("bienvenido al sistema.") << endl;
    cout << endl;

    // Memoria Dinámica y Lista Enlazada
    Nodo* lista = nullptr;
   
    insertarFinal(lista, "Andrea");
    insertarFinal(lista, "Paula");
    insertarFinal(lista, "Sarahi");

    mostrarLista(lista);

    liberarMemoria(lista);
    if (lista == nullptr) {
        cout << "Se libero la memoria" << endl;
    }
    
    mostrarLista(lista);

    return 0;
}
