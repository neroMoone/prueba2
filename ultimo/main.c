#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Liga.h"
int main()
{
    PTRliga liga=cargarLiga("Liga Internacional de Competencias"," www.licompetencias.com", 1998);
    agregarCompe(liga,"Atletismo", "Maratón de Boston", "Estados Unidos");
    agregarCompe(liga,"Natación", "Copa Delfín", "Australia");
    agregarAtl(liga->comp[0],"Juan Pérez", 30, 7450.5);
    agregarAtl(liga->comp[0],"Anna Smith", 28, 7320.2);
    agregarAtl(liga->comp[0],"Carlos Ruiz", 34, 7650.3);
    agregarAtl(liga->comp[0],"Emma Taylor", 27, 7480.1);
    agregarAtl(liga->comp[0],"Martha Lee", 29, 7515.8);

    agregarAtl(liga->comp[1],"Liam Wilson", 23, 580.4);
    agregarAtl(liga->comp[1],"Sophia Brown", 22, 590.2);
    agregarAtl(liga->comp[1],"Lucas Adams", 25, 605.3);
    agregarAtl(liga->comp[1],"Emily Johnson", 24, 575.9);
    ordenarPorMarcas(liga->comp[1]);///ordeno copa delfin por marcas personales de forma ascendente;
    ordenarPorNombre(liga->comp[0]);///ordeno maraton de boston por orden alfabetico de nombres;

    elimPorMarcasTodaCompetencia(liga->comp[0],7500);
    elimPorMarcasTodaCompetencia(liga->comp[1],600);
    int posicionCompetencia=-1;
    int posicionAtleta=busquedaBinNomAtl(liga,"Carlos Ruiz",&posicionCompetencia);

    mostrarLiga(liga);
    mostrarBin(posicionAtleta,posicionCompetencia,liga);
    int tamArr=0;///para el mostrar
    PTRatletas * ArregloAtl=crearArregloAtl(liga,&tamArr);
    cargarVectorAtl(liga,ArregloAtl);
    mostrarVector(ArregloAtl,tamArr);


    return 0;
}
