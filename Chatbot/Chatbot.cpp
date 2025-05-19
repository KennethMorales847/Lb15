#include <string>
#include <iostream>
using namespace std;

//Apuntadores a Funciones
using Estilo = string(*)(const string&);

string estiloFormal(string r) {
    return "Estimado usuario, " + r;
};

string estiloAmistoso(string r) {
    return "Hola! ^_____^ " + r;
};

//Manejo de Memoria Dinámica
struct Nodo {
    string clave;
    string respuesta;
    Nodo* siguiente;
};

//Crear nodo con new
Nodo* crearNodo(const string& clave, const string& resp) {
    Nodo* nuevo = new Nodo;
    nuevo->clave = clave;
    nuevo->respuesta = resp;
    nuevo->siguiente = nullptr;
    return nuevo;
}

//Insertar el nuevo nodo
void insertarFinal(Nodo*& cabeza, const string& clave, const string& resp) {
    Nodo* nodo = crearNodo(clave, resp);
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

//Buscar clave en la lista
Nodo* buscarClave(Nodo* cabeza, const string& clave) {
    for (Nodo* p = cabeza; p != nullptr; p = p->siguiente) {
        if (p->clave == clave) {
            return p;
        }
    }
    return nullptr;
}

//Mostrar lista
void mostrarLista(Nodo* cabeza) {
    cout << "Contenido de la lista:" << endl;
    for (Nodo* p = cabeza; p != nullptr; p = p->siguiente) {
        cout << "Clave: " << p->clave << endl;
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
    int num = 5;
    double dnum = 5.5;
    int* pNum = &num;
    double* pDouble = &dnum;
    cout << "Valor puntero entero: " << *pNum << endl <<
        "Tamaño de entero regular: " << sizeof(int) << endl <<
        "Tamaño del puntero: " << sizeof(pNum) << endl;

    cout << "Valor puntero decimal: " << *pDouble << endl <<
        "Tamaño de double regular: " << sizeof(double) << endl <<
        "Tamaño del puntero: " << sizeof(pDouble) << endl;

    //Arrays de Punteros
    const char* saludos[] = { 
        "Hola, como estas?",
        "Buenos dias!",
        "Que tal?",
        "Holi!"
    };

    for (int i = 0; i < 4; ++i) {
        cout << respuestas[i] << endl;
    }

    //Aritmetica de Punteros
    const char** p = respuestas;
    for (int i = 0; i < 4; ++i) {
        cout << endl << *(p + i) << endl;
    }

    //Sizeof
    cout << endl << "sizeof(int): " << sizeof(int) << endl;
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
