#include <iostream>

struct NodoLista {
    int dato;
    NodoLista* next;

    NodoLista(int val) : dato(val), next(NULL) {}
};

void imprimirLista(NodoLista* c) {
    NodoLista* actual = c;
    if (actual == NULL) {
        std::cout << "La lista está vacía." << std::endl;
        return;
    }
    do {
        std::cout << actual->dato << " , ";
        actual = actual->next;
    } while (actual != c); // Salir después de recorrer toda la lista una vez
    std::cout << std::endl;
}

void insertarDato(NodoLista*& c, int nuevoDato) {
    NodoLista* nuevoNodo = new NodoLista(nuevoDato);
    if (c == NULL) {
        nuevoNodo->next = nuevoNodo; // Si la lista está vacía, el nuevo nodo apunta a sí mismo.
    } else {
        nuevoNodo->next = c->next; // El nuevo nodo apunta al siguiente del primer nodo.
        c->next = nuevoNodo; // El último nodo ahora apunta al nuevo nodo.
    }
    c = nuevoNodo; // El nuevo nodo se convierte en el último nodo.
}

void actualizarDato(NodoLista* c, int datoAnterior, int nuevoDato) {
    NodoLista* actual = c;
    do {
        if (actual->dato == datoAnterior) {
            actual->dato = nuevoDato;
            return;
        }
        actual = actual->next;
    } while (actual != c); // Salir después de recorrer toda la lista una vez
    std::cout << "EL DATO NO SE ENCUENTRA EN LA LISTA." << std::endl;
}

void eliminarDato(NodoLista*& c, int datoAEliminar) {
    NodoLista* actual = c;
    NodoLista* previo = NULL;

    do {
        if (actual->dato == datoAEliminar) {
            if (actual == c) {
                c = actual->next; // Si el nodo a eliminar es el primero, actualiza el puntero de inicio.
            }
            if (previo != NULL) {
                previo->next = actual->next; // Actualiza el puntero del nodo anterior.
            }
            delete actual;
            return;
        }
        previo = actual;
        actual = actual->next;
    } while (actual != c); // Salir después de recorrer toda la lista una vez
    std::cout << "EL DATO NO SE ENCUENTRA EN LA LISTA." << std::endl;
}

int main() {
    NodoLista* c = NULL;

    for (int i = 1; i <= 10; ++i) {
        insertarDato(c, i);
    }

    imprimirLista(c);

    int opcion;
    do {
        std::cout << "Opciones:" << std::endl;
        std::cout << "1. INSERTAR DATO" << std::endl;
        std::cout << "2. MOSTRAR LISTA" << std::endl;
        std::cout << "3. ACTUALIZAR DATO" << std::endl;
        std::cout << "4. ELIMINAR DATO" << std::endl;
        std::cout << "0. SALIR" << std::endl;
        std::cout << "INGRESE UNA OPCION: ";
        std::cin >> opcion;

        switch (opcion) {
            case 1:
                int nuevoDato; // Declarar nuevoDato aquí
                std::cout << "Ingrese el nuevo dato: ";
                std::cin >> nuevoDato;
                insertarDato(c, nuevoDato);
                break;
            case 2:
                imprimirLista(c);
                break;
            case 3:
                int datoAnterior;
                std::cout << "Ingrese el dato a actualizar: ";
                std::cin >> datoAnterior;
                std::cout << "Ingrese el nuevo valor: ";
                std::cin >> nuevoDato;
                actualizarDato(c, datoAnterior, nuevoDato);
                break;
            case 4:
                int datoAEliminar;
                std::cout << "Ingrese el dato a eliminar: ";
                std::cin >> datoAEliminar;
                eliminarDato(c, datoAEliminar);
                break;
            case 0:
                break;
            default:
                std::cout << "Opción no válida. Intente nuevamente." << std::endl;
        }
    } while (opcion != 0);

    // No es necesario liberar la memoria en este caso, ya que no se utiliza un bucle while para eliminar todos los nodos, debido a que la lista es circular.

    return 0;
}
