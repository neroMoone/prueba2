#ifndef COMPETENCIA_H_INCLUDED
#define COMPETENCIA_H_INCLUDED
#include "Atletas.h"



struct competencia{

char tipoDeDeporte[40];
char nombre[40];
char paisSede[40];
int tamAtl;
PTRatletas * atl;


};

typedef struct competencia* PTRcompetencia;


PTRcompetencia cargarComp(char tipoDeDeporte[40],char nombre[40],char paisSede[40]);

void mostrarComp(PTRcompetencia comp);

void agregarAtl(PTRcompetencia com,char nombre[40],int edad,float marca);

void ordenarPorMarcas(PTRcompetencia com);

void ordenarPorNombre(PTRcompetencia com);

void eliminarCompetencia(PTRcompetencia com);


void elimPorMarcasTodaCompetencia(PTRcompetencia com,float marca);








#endif // COMPETENCIA_H_INCLUDED
