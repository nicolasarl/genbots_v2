#ifndef _PROCESS_CPP
#define _PROCESS_CPP
#include <Arduino.h>
#include <math.h>
#include "subprocess.h"
#include "pines.h"


typedef struct{

  int gen1[10]= {60, 19, 64, 16, 45, 62, 17, 34, 66, 76};//valores genes para motor izq
  int gen2[10] = {55, 47, 88, 71, 26, 18, 47, 82, 89, 14};//valores genes para motor der
  int gen3[10] = {24, 63, 22, 92, 78, 95, 59, 63, 94, 46};//valores genes para LED's
}genes;
genes gen;
int temp1 = 0;//variable temporal utilizada para almacenar calculos intermedios
int temp2 = 0;//variable temporal utilizada para almacenar calculos intermedios

/*-----------------Funciones principales--------------------------------------*/

void lectura(float input_neuron [ ]){

  phototransistors(input_neuron);
  
}

#endif
