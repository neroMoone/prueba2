#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Liga.h"


PTRliga cargarLiga(char nombre[40],char web[40],int anioCreacion){
PTRliga lig= (PTRliga)malloc(sizeof(struct liga));
lig->tamComp=0;
lig->comp= (PTRcompetencia*)malloc(sizeof(struct competencia));
lig->comp[0]=NULL;
strcpy(lig->nombre,nombre);
strcpy(lig->web,web);
lig->anioCreacion=anioCreacion;

return lig;
};


void mostrarLiga(PTRliga lig){
if(lig !=NULL){
printf("\n-------------------------Liga--------------------------\n");
printf("\n  Nombre %s \n",lig->nombre);
printf("\n  Web %s \n",lig->web);
printf("\n  Anio de creacion %d \n",lig->anioCreacion);

for(int i=0;i<lig->tamComp;i++){

    if(lig->comp[i]!=NULL){
        mostrarComp(lig->comp[i]);
    }

}

printf("\n----------------------Fin MostrarLiga----------------------\n");
printf("\n-----------------------------------------------------------\n");

   }


};

void agregarCompe (PTRliga lig, char tipoDeDeporte[40],char nombre[40],char paisSede[40]){
int pos=-1;
for(int i=0;i<lig->tamComp;i++){
    if(lig->comp==NULL){
        pos=i;
        break;
    }
}
if(pos==-1){
    PTRcompetencia *temp= realloc(lig->comp,(lig->tamComp+1)*sizeof(struct competencia));
    if (temp!=NULL){
        pos=lig->tamComp;
        lig->tamComp++;
        lig->comp=temp;
    }else{
    printf("\nERROR CON CREACION DE COMPETENCIA\n");
    }
}
lig->comp[pos]=cargarComp(tipoDeDeporte,nombre,paisSede);


};
void eliminarLiga(PTRliga lig) {
    if (lig != NULL) {
        for (int i = 0; i < lig->tamComp; i++) {
            if (lig->comp[i] != NULL) {
                eliminarCompetencia(lig->comp[i]);
                lig->comp[i]=NULL;
            }
        }
        free(lig);       // Libera la estructura de liga.
    }
}

int busquedaBinNomAtl(PTRliga lig,char buscado[40],int* posCom){
int encontrado=-1;
for(int i=0;i<lig->tamComp;i++){
    if(lig->comp[i]!=NULL){

    int izquierda=0;
    int derecha=lig->comp[i]->tamAtl-1;
        while(izquierda<=derecha&&encontrado==-1){
        int medio=(izquierda+(derecha-izquierda)/2);

        if(lig->comp[i]->atl[medio]!=NULL){
            int cmp=(strcmp(buscado,lig->comp[i]->atl[medio]->nombre));
            if (cmp==0){
                encontrado=medio;
                *posCom = i;
            }else if(cmp>0){
                izquierda=medio+1;

            }else{
            derecha=medio-1;
            }
        }else{
        derecha=medio-1;

        }

        }

    }


}




return encontrado;
};
void mostrarBin(int posAtl,int posComp,PTRliga lig){

if(posAtl!=-1&& posComp!=-1){
    printf("\n SE ENCONTRO EN LA COMPETENCIA %d EL ATLETA NUMERO %d \n",posComp,posAtl);

    mostrarAtleta(lig->comp[posComp]->atl[posAtl]);
}else{
printf("\nNO FUE ENCONTRADo\n");
}
}

PTRatletas * crearArregloAtl (PTRliga lig, int* tamanio){
for(int i=0;i<lig->tamComp;i++){
    if (lig->comp[i]!=NULL){
        for(int j=0;j<lig->comp[i]->tamAtl;j++){
            if(lig->comp[i]->atl[i]!=NULL){
                (*tamanio)++;
            }
        }
    }
}
PTRatletas*  V = (PTRatletas*)malloc ((*tamanio)*sizeof (struct atletas));



return V;
}

void cargarVectorAtl (PTRliga lig, PTRatletas * V){
int k=0;
for(int i=0;i<lig->tamComp;i++){
    if (lig->comp[i]!=NULL){
        for(int j=0;j<lig->comp[i]->tamAtl;j++){
            if(lig->comp[i]->atl[j]!=NULL){
                V[k++] = lig->comp[i]->atl[j];

            }
        }
    }
}



};


void mostrarVector (PTRatletas* V,int tam){

for(int i=0;i<tam;i++){
    if(V[i]!=NULL){
        mostrarAtleta(V[i]);
    }
}
};










