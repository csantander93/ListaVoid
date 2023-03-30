#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

struct PersonaEstructura;
typedef struct PersonaEstructura * Persona;

Persona crearPersona(char nombre[20], char apellido[20], int dni);
void mostrarPersona(Persona p);

int getDNI(Persona p);
char * getNombre(Persona p);


#endif // PERSONA_H_INCLUDED
