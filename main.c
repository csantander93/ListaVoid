#include <stdio.h>
#include <stdlib.h>
#include "persona.h"
#include "lista.h"

int main()
{
    Lista listaPersonas = crearLista(sizeof(Persona));
    Persona p1 = crearPersona("Cristian", "Santander", 22222222);
    Persona p2 = crearPersona("Johanna", "Mendoza", 99999999);
    Persona p3 = crearPersona("Kevin", "Gato", 12345678);
    Persona p4 = crearPersona("Juansito", "Hola", 87654321);
    Persona p5 = crearPersona("Rafael", "Moran", 11111111);

    Persona pBorrada1;
    Persona pBorrada2;

    insertarInicio(listaPersonas, &p1);
    insertarInicio(listaPersonas, &p2);
    insertarInicio(listaPersonas, &p3);
    insertarFin(listaPersonas, &p4);
    insertarFin(listaPersonas, &p5);
    mostrarLista(listaPersonas);

    removerInicio(listaPersonas, &pBorrada1);
    removerFinal(listaPersonas, &pBorrada2);
    printf("Se eliminaron!!!!\n\n");
    mostrarPersona(pBorrada1);
    mostrarPersona(pBorrada2);
    printf("\nMostrando lista nuevamente luego del borrado....\n");
    mostrarLista(listaPersonas);

    printf("Se encontro el dni de %s en la posicion %d",getNombre(p1), busquedaPorDni(listaPersonas, 22222222));
    printf("\n\nLISTA ORDENADA\n");
    ordenamientoPorDNI(listaPersonas);
    mostrarLista(listaPersonas);

    return 0;
}
