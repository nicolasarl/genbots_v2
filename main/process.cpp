#ifndef _PROCESS_CPP
#define _PROCESS_CPP
#include <Arduino.h>
#include <math.h>
#include "subprocess.h"
#include "pines.h"


typedef struct{
//Estos vectores se generaron de forma aleatoria usando la siguiente web: 
//http://www.alazar.info/generador-de-numeros-aleatorios-sin-repeticion
  int gen1[10]= {17, 1, 59, 41, 43, 55, 26, 51, 80, 28};//valores genes para motor izq
  int gen2[10] = {96, 61, 98, 7, 57, 39, 97, 2, 70, 50};//valores genes para motor der
  int gen3[10] = {10, 90, 69, 71, 84, 79, 94, 53, 4, 54};//valores genes para LED's
}genes;
genes gen;
int temp1 = 0;//variable temporal utilizada para almacenar calculos intermedios
int temp2 = 0;//variable temporal utilizada para almacenar calculos intermedios

/*-----------------Funciones principales--------------------------------------*/

void lectura(float input_neuron [ ]){

  tcs(input_neuron);
  phototransistors(input_neuron);
  
}


void calculo(float input_neuron [], float output_neuron[]){//Realiza el cálculo de las neuronas de salida
 
for (int i = 0; i < 9; i++){//motor izq

  temp1 += input_neuron[i]*gen.gen1[i];
}
  output_neuron[0] = tanh(temp1/100);
for (int j = 0; j < 9; j++){//motor der

  temp1 += input_neuron[j]*gen.gen2[j];
}
  output_neuron[1] = tanh(temp1/100);
for (int n = 0; n < 9; n++){//Led's

  temp1 += input_neuron[n]*gen.gen3[n];
} 
  output_neuron[2] = tanh(temp1/100); 
}


void salida(float output_neuron[]){
  //Salida motor der

  if (output_neuron[0] < 0){
    
    if(output_neuron[0] > -0.3){//definimos un rango entre 0 y -0.3 en el que paramos las ruedas. Esto se hace para proteger los motores
      temp2 = 0;
    }
    else{
      temp2 = int(output_neuron[0]*255*(-1));
    }
    analogWrite(PWM1, temp2);
    digitalWrite(SM1, LOW);//hacia detrás
    digitalWrite(SM1_2, HIGH);
  }
  else{

    if(output_neuron[0] < 0.3){
      temp2 = 0;
    }
    else{//Se define un rango entre 0 y 0.3 donde se pone velocidad nula para proteger los motores
      temp2 = int(output_neuron[0]*255);
    }
    analogWrite(PWM1, temp2);
    digitalWrite(SM1, HIGH);//hacia delante
    digitalWrite(SM1_2, LOW);    
  }
   //Salida motor izq

  if (output_neuron[1] < 0){
    
    if(output_neuron[1] > -0.3){//definimos un rango entre 0 y -0.3 en el que paramos las ruedas. Esto se hace para proteger los motores
      temp2 = 0;
    }
    else{
      temp2 = int(output_neuron[1]*255*(-1));
    }
    analogWrite(PWM2, temp2);
    digitalWrite(SM2, LOW);//hacia detrás
    digitalWrite(SM2_2, HIGH);
  }
  else{
    if(output_neuron[1] < 0.3){//Se define un rango entre 0 y 0.3 donde se pone velocidad nula para proteger los motores
      temp2 = 0;
    }
    else{
      temp2 = int(output_neuron[1]*255);
    }
    analogWrite(PWM2, temp2);
    digitalWrite(SM2, HIGH);//hacia delante
    digitalWrite(SM2_2, LOW);    
  }

  //LED's

  if (output_neuron[3] < 0){//Se enciende LED's rojos
    digitalWrite(LEDR, HIGH);
    digitalWrite(LEDG, LOW);
    digitalWrite(LEDB, LOW);
  }
  else if(output_neuron == 0){//O bien se apagan todos los LED's o se le añade un tercer color, verde, para la comunicacion
    digitalWrite(LEDR, LOW);
    digitalWrite(LEDG, HIGH);
    digitalWrite(LEDB, LOW);   
  }
  else{//Se enciende LED's azules
    digitalWrite(LEDR, LOW);
    digitalWrite(LEDG, LOW);
    digitalWrite(LEDB, HIGH);    
  }

}
#endif
