#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "persona.h"

struct PersonaEstructura{

char nombre[20];
char apellido[20];
int dni;

};

Persona crearPersona(char n[20], char ap[20], int d){

Persona p = malloc(sizeof(struct PersonaEstructura));

strcpy(p->nombre, n);
strcpy(p->apellido, ap);
p->dni = d;

return p;

};
void mostrarPersona(Persona p){

printf("Nombre: %s  \nApellido: %s \nDocumento: %d\n", p->nombre, p->apellido, p->dni);

};

int getDNI(Persona p){

return p->dni;

};

char * getNombre(Persona p){

return p->apellido;

}
