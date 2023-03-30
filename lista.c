#include <stdio.h>
#include <stdlib.h>
#include "persona.h"
#include "lista.h"

struct NodoE{

void * dato;
Nodo prox;

};

struct ListaE{

Nodo inicio;
int tam;
int tamDelDato;

};

Nodo crearNodo(Lista lista, void * dato, Nodo prox){

Nodo temp = malloc(sizeof(struct NodoE));

temp->dato = malloc(lista->tamDelDato);
memcpy(temp->dato, dato, lista->tamDelDato);
temp->prox = prox;

return temp;

};
Lista crearLista(int tamDelDato){

Lista lista = malloc(sizeof(struct ListaE));
lista->inicio = NULL;
lista->tam = 0;
lista->tamDelDato = tamDelDato;

return lista;

};

void * obtenerDato(Lista lista, int pos){

Nodo aux = lista->inicio;

for(int i=0; i<pos; i++){
    aux = aux->prox;
}

return aux->dato;

};

int insertarInicio(Lista lista, void * dato){

Nodo aux = crearNodo(lista, dato, lista->inicio);
lista->inicio = aux;
lista->tam++;

return TRUE;

};

int insertarFin(Lista lista, void * dato){

Nodo aux;
if(lista->tam == 0){
    aux = crearNodo(lista, dato, lista->inicio);
    lista->inicio = aux;
    lista->tam++;
    return TRUE;
}
aux = lista->inicio;
    for(int i=0; i<lista->tam-1;i++){
        aux = aux->prox;
    }
Nodo nuevoNodo = crearNodo(lista, dato, aux->prox);
aux->prox = nuevoNodo;

lista->tam++;

return TRUE;

};

int removerInicio(Lista lista, void * respaldo){

Nodo aux = lista->inicio;
if(respaldo != NULL){
    memcpy(respaldo, aux->dato, lista->tamDelDato);
}
lista->inicio = aux->prox;
free(aux);
aux = NULL;
lista->tam--;

return TRUE;

};

int removerFinal(Lista lista, void * respaldo){

Nodo anterior, actual;

anterior = NULL;
actual = lista->inicio;

for(int i=0; i<lista->tam-1; i++){
    anterior = actual;
    actual = actual->prox;
}

anterior->prox = actual->prox;

if(respaldo != NULL){
    memcpy(respaldo, actual->dato, lista->tamDelDato);
}

free(actual);
actual = NULL;
lista->tam--;

return TRUE;
};

void mostrarLista(Lista lista){
    printf("\n");
    for(int i=0; i<lista->tam; i++){
        mostrarPersona(*(Persona*) obtenerDato(lista, i));
        printf("\n");
    }
};

int busquedaPorDni(Lista lista, int dni){

int pos=-1;
int i=0;
while(i<lista->tam && pos == -1){
    if(dni == getDNI(*(Persona*) obtenerDato(lista, i))){
       pos = i;
    }
    i++;
}

return pos;

};

void ordenamientoPorDNI(Lista lista){

Persona pAux;
Nodo actual;

for(int i=0; i<lista->tam; i++){
    actual = lista->inicio;
    for(int j=0; j<lista->tam-1;j++){
        if(getDNI(*(Persona*) actual->dato) > getDNI(*(Persona*) actual->prox->dato )){
                pAux = actual->dato;
                actual->dato = actual->prox->dato;
                actual->prox->dato = pAux;
        }
        actual = actual->prox;
    }
}
}
