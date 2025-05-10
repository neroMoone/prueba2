#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Atletas.h"


PTRatletas cargarAtleta(char nombre[40],int edad,float marca){
PTRatletas atl = (PTRatletas)malloc(sizeof(struct atletas));

strcpy(atl->nombre,nombre);
atl->edad=edad;
atl->marcaPersonal=marca;




return atl;
};

void mostrarAtleta(PTRatletas atl){
if(atl !=NULL){
printf("\n--------Atleta-----------\n");
printf("\n  NOMBRE %s \n",atl->nombre);
printf("\n  EDAD %d \n",atl->edad);
printf("\n  MARCA PeRsonaL %.2f \n",atl->marcaPersonal);


   }



};


void eliminarAtleta(PTRatletas atl){
///no liberar solo eliminar
free(atl);
}


