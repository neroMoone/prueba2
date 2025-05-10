#ifndef ATLETAS_H_INCLUDED
#define ATLETAS_H_INCLUDED



struct atletas{

char nombre[40];
int edad;
float marcaPersonal;


};


typedef struct atletas* PTRatletas;


PTRatletas cargarAtleta(char nombre[40],int edad,float marca);

void mostrarAtleta(PTRatletas atl);

void eliminarAtleta(PTRatletas atl);


#endif // ATLETAS_H_INCLUDED
