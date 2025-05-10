#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Competencia.h"



PTRcompetencia cargarComp(char tipoDeDeporte[40],char nombre[40],char paisSede[40]){
PTRcompetencia com= (PTRcompetencia)malloc(sizeof(struct competencia));
com->tamAtl=0;
com->atl= (PTRatletas*)malloc(sizeof(struct atletas));
com->atl[0]=NULL;
strcpy(com->nombre,nombre);
strcpy(com->tipoDeDeporte,tipoDeDeporte);
strcpy(com->paisSede,paisSede);


return com;
};

void mostrarComp(PTRcompetencia comp){
if(comp !=NULL){
printf("\n-------------------Competencia--------------------\n");
printf("\n  Tipo de deporte %s \n",comp->tipoDeDeporte);
printf("\n  Nombre %s \n",comp->nombre);
printf("\n  Pais Sede %s \n",comp->paisSede);

for(int i=0;i<comp->tamAtl;i++){

    if(comp->atl[i]!=NULL){
        mostrarAtleta(comp->atl[i]);
    }

}
   }



};





void agregarAtl(PTRcompetencia com,char nombre[40],int edad,float marca){
int pos=-1;
for(int i=0;i<com->tamAtl;i++){
    if(com->atl==NULL){
        pos=i;
        break;
    }
}
if(pos==-1){
    PTRatletas *temp= realloc(com->atl,(com->tamAtl+1)*sizeof(struct atletas));
    if (temp!=NULL){
        pos=com->tamAtl;
        com->tamAtl++;
        com->atl=temp;
    }else{
    printf("\nERROR CON CREACION DE ATLETAS\n");
    }
}
com->atl[pos]=cargarAtleta(nombre,edad,marca);


};

void ordenarPorMarcas(PTRcompetencia com){
int i,j,min;
int tam=com->tamAtl;
PTRatletas temp;

for(i=0;i<tam;i++){
if(com->atl[i]!=NULL){
     min=i;
             for(j=i+1;j<tam;j++){

        if(com->atl[j]!=NULL){
            if(com->atl[min]->marcaPersonal>com->atl[j]->marcaPersonal){
                min=j;
            }
        }
    }
    temp=com->atl[min];
    com->atl[min]=com->atl[i];
    com->atl[i]=temp;
}




}




};

void ordenarPorNombre(PTRcompetencia com){
int i,j,min;
int tam=com->tamAtl;
PTRatletas temp;

for(i=0;i<tam;i++){
if(com->atl[i]!=NULL){
     min=i;
             for(j=i+1;j<tam;j++){

        if(com->atl[j]!=NULL){
            if(strcmp(com->atl[min]->nombre,com->atl[j]->nombre)>0){
                min=j;
            }
        }
    }
    temp=com->atl[min];
    com->atl[min]=com->atl[i];
    com->atl[i]=temp;
}




}

};
void eliminarCompetencia(PTRcompetencia com) {
    if (com != NULL) {
        for (int i = 0; i < com->tamAtl; i++) {
            if (com->atl[i] != NULL) {
                eliminarAtleta(com->atl[i]);
                com->atl[i]=NULL;
            }
        }
        free(com);      // Libera la estructura de competencia.
    }
}


void elimPorMarcasTodaCompetencia(PTRcompetencia com, float marca) {
    for (int i = 0; i < com->tamAtl; i++) {
        if (com->atl[i] != NULL && com->atl[i]->marcaPersonal > marca) {

            eliminarAtleta(com->atl[i]);
            com->atl[i]=NULL;
        }
    }
}


