#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

enum Booleans {ERROR = -1, FALSE, TRUE};

struct NodoE;
typedef struct NodoE * Nodo;

struct ListaE;
typedef struct ListaE * Lista;

Nodo crearNodo(Lista lista, void * dato, Nodo prox);
Lista crearLista(int tamDelDato);

void * obtenerDato(Lista lista, int pos);

int insertarInicio(Lista lista, void * dato);
int insertarFin(Lista lista, void * dato);

int removerInicio(Lista lista, void * respaldo);
int removerFinal(Lista lista, void * respaldo);

void mostrarLista(Lista lista);

int busquedaPorDni(Lista lista, int dni);

#endif // LISTA_H_INCLUDED
