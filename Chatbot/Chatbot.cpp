#include <string>
#include <iostream>
using namespace std;

//Apuntadores a Funciones
using Estilo = string(*)(const string&);

string estiloFormal(const string& r) {
    return "Estimado usuario, " + r;
};

string estiloAmistoso(const string& r) {
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

    //Arrays de Punteros y Aritmetica de Punteros
    const char* saludos[] = { 
        "Hola, como estas?",
        "Buenos dias!",
        "Que tal?",
        "Holi!"
    };

    cout << "Lista de saludos usando aritmetica de punteros:" << endl;
    const char** p = saludos;
    for (int i = 0; i < 4; ++i) {
        cout << endl << *(p + i) << endl;
    }

    //Agregando respuestas a la lista

    Nodo* lista = nullptr;
    insertarFinal(lista, "hola", "Como puedo ayudarte?");
    insertarFinal(lista, "adios", "Nos vemos luego!");
    insertarFinal(lista, "gracias", "De nada!");

    //Elegir estilo de respuesta por puntero a función
    int opc;

    Estilo responder;
    cout << endl << "Elige el estilo de respuesta que prefieras:" << endl <<
        "1. Formal" << endl <<
        "2. Amistoso" << endl;
    cin >> opc;
    
    if (opc == 1) {
        responder = estiloFormal;
    }
    else {
        responder = estiloAmistoso;
    }

    //Bucle principal

    cout << endl << "Escribe una palabra clave o salir para terminar" << endl;
    string entrada;

    while (true) {
        cout << "Tu: "; cin >> entrada;

        if (entrada == "salir") {
            break;
        }

        Nodo* nodo = buscarClave(lista, entrada);
        if (nodo) {
            cout << responder(nodo->respuesta) << endl;
        }
        else {
            cout << responder("Lo siento, no entiendo esa clave.") << endl;
        }
    }

    liberarMemoria(lista);
    if (lista == nullptr) {
        cout << "Se libero la memoria" << endl;
    }

    return 0;
}
