#ifndef LIGA_H_INCLUDED
#define LIGA_H_INCLUDED
#include "Competencia.h"

struct liga{
char nombre[40];
char web[40];
int anioCreacion;
int tamComp;
PTRcompetencia * comp;


};

typedef struct liga* PTRliga;

PTRliga cargarLiga(char nombre[40],char web[40],int anioCreacion);


void mostrarLiga(PTRliga lig);

void agregarCompe (PTRliga lig, char tipoDeDeporte[40],char nombre[40],char paisSede[40]);

void eliminarLiga(PTRliga lig);

int busquedaBinNomAtl(PTRliga lig,char buscado[40],int* posCom);

void mostrarBin(int posAtl,int posComp,PTRliga lig);

PTRatletas * crearArregloAtl (PTRliga lig, int* tamanio);

void cargarVectorAtl (PTRliga lig, PTRatletas * V);

void mostrarVector (PTRatletas* V,int tam);




#endif // LIGA_H_INCLUDED
