#ifndef _SUBPROCESS_CPP
#define _SUBPROCESS_CPP

#include <Arduino.h>
#include "pines.h"
#include "variables.h"
#include "subprocess.h"
/*
*NOTA: PARTES DE ESTE CODIGO SE HAN EXTRAIDO DEL SOGUIENTE ENLACE PARA AHORRAR TIEMPO VOLVIENDO A CREAR UN PROGRAMA CON UNA FUNCIONALIDAD 
**PREDEFINIDA COMO ES EL uSO DEL SENSOR: https://hetpro-store.com/TUTORIALES/sensor-de-color-tcs3200-con-arduino/
*/
/*Declaracion de variables temporales*/
typedef struct{
  int R;
  int G;
  int B;
}color;
color rgb;

typedef struct{
  int R;
  int G;
  int B;
}zonas;

zonas temp;
/*Declaracion constantes*/

int MM; //define un rango alrededor del 0 equivalente al 5% del rango, en el cual también se considera que el motor debe pararse
int ML; //define el rango en torno al 0 para escoger los LED's
const int INTENSIDAD_MIN = int((4.32*1023)/5);//maximo valor en la entrada analógica cambiado a binario

void phototransistors(float input_neuron[]){

  //Realizamos la lectura para el cuadrante 1
  digitalWrite(sel1, LOW);
  digitalWrite(sel2, LOW);
  delayMicroseconds(50);
  //Esta linea sobra, es para probar el decoder:
  delay(1000);
  temp.R = analogRead(LECT_R);
  temp.B = analogRead(LECT_B);

  input_neuron[2] = 1-(temp.R/INTENSIDAD_MIN);//Calculamos el valor de la neurona. OJO: el fototransistor tiene lógica negada, mayor voltaje menor intensidad
  input_neuron[3] = 1-(temp.B/INTENSIDAD_MIN);
  
  //Realizamos la lectura para el cuadrante 2
  digitalWrite(sel1, LOW);
  digitalWrite(sel2, HIGH);
  delayMicroseconds(50);
  delay(1000);
  temp.R = analogRead(LECT_R);
  temp.B = analogRead(LECT_B);

  input_neuron[4] = 1-(temp.R/INTENSIDAD_MIN);//Calculamos el valor de la neurona. OJO: el fototransistor tiene lógica negada, mayor voltaje menor intensidad
  input_neuron[5] = 1-(temp.B/INTENSIDAD_MIN);
  
  //Realizamos la lectura para el cuadrante 3
  digitalWrite(sel1, HIGH);
  digitalWrite(sel2, LOW);
  delayMicroseconds(50);
  delay(1000);
  temp.R = analogRead(LECT_R);
  temp.B = analogRead(LECT_B);

  input_neuron[6] = 1-(temp.R/INTENSIDAD_MIN);//Calculamos el valor de la neurona. OJO: el fototransistor tiene lógica negada, mayor voltaje menor intensidad
  input_neuron[7] = 1-(temp.B/INTENSIDAD_MIN);
  
  //Realizamos la lectura para el cuadrante 4
  digitalWrite(sel1, HIGH);
  digitalWrite(sel2, HIGH);
  delayMicroseconds(50);
  delay(1000);
  temp.R = analogRead(LECT_R);
  temp.B = analogRead(LECT_B);

  input_neuron[8] = 1-(temp.R/INTENSIDAD_MIN);//Calculamos el valor de la neurona. OJO: el fototransistor tiene lógica negada, mayor voltaje menor intensidad
  input_neuron[9] = 1-(temp.B/INTENSIDAD_MIN);
}
#endif
