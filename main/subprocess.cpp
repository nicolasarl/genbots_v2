#ifndef _SUBPROCESS_CPP
#define _SUBPROCESS_CPP

#include <Arduino.h>
#include "pines.h"
#include "variables.h"
#include "subprocess.h"
/*
*NOTA: PARTES DE ESTE CODIGO SE HAN EXTRAIDO DEL SIGUIENTE ENLACE PARA AHORRAR TIEMPO VOLVIENDO A CREAR UN PROGRAMA CON UNA FUNCIONALIDAD 
**PREDEFINIDA COMO ES EL USO DEL SENSOR: https://hetpro-store.com/TUTORIALES/sensor-de-color-tcs3200-con-arduino/
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



void tcs(float input_neuron[]){

//Encendemos el sensor

digitalWrite(s0, HIGH);
digitalWrite(s1, HIGH);
delayMicroseconds(50);
  //Lee el valor en frecuencia de el color que lee, además de cambiarlo a rango RGB 
 
    //Leemos el rojo 
    digitalWrite(s2, LOW); 
    digitalWrite(s3,LOW); 
    rgb.R = pulseIn(OUT,digitalRead(OUT)== HIGH ? LOW : HIGH);     
    
    //Leemos el verde 
    digitalWrite(s2, HIGH); 
    digitalWrite(s3,HIGH); 
    rgb.G = pulseIn(OUT,digitalRead(OUT)== HIGH ? LOW : HIGH);     
    
    //Leemos el blue 
    digitalWrite(s2, LOW); 
    digitalWrite(s3,HIGH); 
    rgb.B = pulseIn(OUT,digitalRead(OUT)== HIGH ? LOW : HIGH);     

//compara el valor con el del veneno: ROJO
 
if ((rgb.R < rgb.B)&&(rgb.G > rgb.B)&& (rgb.R < 35)){
 
    input_neuron[0] = 0;//ponemos la neurona de comida a 0 
    input_neuron[1] = 1;//ponemos la neurona de veneno a 1 
  }  
 
//compara el valor de la comida: AZUL 
 
  if ((rgb.B < rgb.R)&&(rgb.G > rgb.B)&& (rgb.G < rgb.R)){ 
 
    input_neuron[0] = 1;//ponemos la neurona de comida a 1 
    input_neuron[1] = 0;//ponemos la neurona de veneno a 0 
  } 


//Apagamos el sensor

digitalWrite(s0, LOW);
digitalWrite(s1, LOW); 
}
void phototransistors(float input_neuron[]){

  //Realizamos la lectura para el cuadrante 1
  digitalWrite(sel1, LOW);
  digitalWrite(sel2, LOW);
  delayMicroseconds(50);
  temp.R = analogRead(LECT_R);
  temp.B = analogRead(LECT_B);

  input_neuron[2] = 0.001038*temp.R-0.0322;
  input_neuron[2] = constrain(input_neuron[2],0,1);//neurona cuadrante 1, valor rojo
  input_neuron[3] = (1.0/212.0)*temp.B-1.20755;
  input_neuron[3] = constrain(input_neuron[3],0,1);//neurona cuadrante 1, valor azul
  
  //Realizamos la lectura para el cuadrante 2
  digitalWrite(sel1, LOW);
  digitalWrite(sel2, HIGH);
  delayMicroseconds(50);
  temp.R = analogRead(LECT_R);
  temp.B = analogRead(LECT_B);

  input_neuron[4] = 0.001038*temp.R-0.0322;
  input_neuron[4] = constrain(input_neuron[4],0,1);//neurona cuadrante 2, valor rojo
  input_neuron[5] = (1.0/212.0)*temp.B-1.20755;
  input_neuron[5] = constrain(input_neuron[5],0,1);//neurona cuadrante 2, valor azul
  
  //Realizamos la lectura para el cuadrante 3
  digitalWrite(sel1, HIGH);
  digitalWrite(sel2, LOW);
  delayMicroseconds(50);
  temp.R = analogRead(LECT_R);
  temp.B = analogRead(LECT_B);

  input_neuron[6] = 0.001038*temp.R-0.0322;
  input_neuron[6] = constrain(input_neuron[6],0,1);//neurona cuadrante 3, valor rojo
  input_neuron[7] = (1.0/212.0)*temp.B-1.20755;
  input_neuron[7] = constrain(input_neuron[7],0,1);//neurona cuadrante 3, valor azul
  
  //Realizamos la lectura para el cuadrante 4
  digitalWrite(sel1, HIGH);
  digitalWrite(sel2, HIGH);
  delayMicroseconds(50);
  temp.R = analogRead(LECT_R);
  temp.B = analogRead(LECT_B);

  input_neuron[8] = 0.001038*temp.R-0.0322;
  input_neuron[8] = constrain(input_neuron[8],0,1);//neurona cuadrante 4, valor rojo
  input_neuron[9] = (1.0/212.0)*temp.B-1.20755;
  input_neuron[9] = constrain(input_neuron[9],0,1);//neurona cuadrante 4, valor azul
}
#endif
