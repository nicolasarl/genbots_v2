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
/*Declaracion de variables temporales def*/
typedef struct{
  int R;
  int G;
  int B;
}color;
color rgb;//tcs

typedef struct{
  int R;
  int G;
  int B;
}zonas;
zonas temp;//fototransistores

/*Declaracion constantes*/

int MM; //define un rango alrededor del 0 equivalente al 5% del rango, en el cual también se considera que el motor debe pararse
int ML; //define el rango en torno al 0 para escoger los LED's
//const int INTENSIDAD_MIN = int((4.32*1023)/5);//maximo valor en la entrada analógica cambiado a binario


void tcs(float input_neuron[]){

//Encendemos el sensor

digitalWrite(s0, HIGH);
digitalWrite(s1, HIGH);
delayMicroseconds(50);
  //Lee el valor en frecuencia de el color que lee, además de cambiarlo a rango RGB

    //Leemos el rojo
    digitalWrite(s2, LOW);
    digitalWrite(s3,LOW);
    rgb.R = pulseIn(out,digitalRead(out)== HIGH ? LOW : HIGH);

    //Leemos el verde
    digitalWrite(s2, HIGH);
    digitalWrite(s3,HIGH);
    rgb.G = pulseIn(out,digitalRead(out)== HIGH ? LOW : HIGH);

    //Leemos el blue
    digitalWrite(s2, LOW);
    digitalWrite(s3,HIGH);
    rgb.B = pulseIn(out,digitalRead(out)== HIGH ? LOW : HIGH);

//compara el valor con el del veneno: ROJO

if ((rgb.R < rgb.B)&&(rgb.G > rgb.B)&& (rgb.R < 35)){

    input_neuron[0] = 0;//ponemos la neurona de comida a 0
    input_neuron[1] = 1;//ponemos la neurona de veneno a 1
  }

//compara el valor de la comida: AZUL

else if ((rgb.B < rgb.R)&&(rgb.G > rgb.B)&& (rgb.G < rgb.R)){

    input_neuron[0] = 1;//ponemos la neurona de comida a 1
    input_neuron[1] = 0;//ponemos la neurona de veneno a 0
  }
else{
  input_neuron[0] = 0;//ponemos la neurona de comida a 0 Control de versiones
  input_neuron[1] = 0;//ponemos la neurona de veneno a 0 Control de versiones
}

//Apagamos el sensor
//******************************************************************//
Serial.println("Valor neurona 0, parte del subprocess:");
Serial.println(input_neuron[0]);
Serial.println("Valor neurona 1, parte del subprocess:");
Serial.println(input_neuron[1]);
//******************************************************************//

digitalWrite(s0, LOW);
digitalWrite(s1, LOW);
}
void phototransistors(float input_neuron[]){
//Control de versiones 
  //Realizamos la lectura para el cuadrante 1
  digitalWrite(sel1, LOW);
  digitalWrite(sel2, LOW);
  delay(1);

  temp.B = analogRead(lect_b);
  input_neuron[3] = (1.0/212.0)*temp.B-1.20755;
  input_neuron[3] = constrain(input_neuron[3],0,1);
  temp.R = analogRead(lect_r);
  input_neuron[2] = 0.001038*temp.R-0.0322;
  input_neuron[2] = constrain(input_neuron[2],0,1);
  
  //Realizamos la lectura para el cuadrante 2
  digitalWrite(sel1, LOW);
  digitalWrite(sel2, HIGH);
  delay(1);

  temp.B = analogRead(lect_b);
  input_neuron[5] = (1.0/212.0)*temp.B-1.20755;
  input_neuron[5] = constrain(input_neuron[5],0,1);
  temp.R = analogRead(lect_r);
  input_neuron[4] = 0.001038*temp.R-0.0322;
  input_neuron[4] = constrain(input_neuron[4],0,1);

  //Realizamos la lectura para el cuadrante 3
  digitalWrite(sel1, HIGH);
  digitalWrite(sel2, LOW);
  delay(1);
  temp.B = analogRead(lect_b);
  input_neuron[7] = (1.0/212.0)*temp.B-1.20755;
  input_neuron[7] = constrain(input_neuron[7],0,1);
  temp.R = analogRead(lect_r);
  input_neuron[6] = 0.001038*temp.R-0.0322;
  input_neuron[6] = constrain(input_neuron[6],0,1);

  //Realizamos la lectura para el cuadrante 4
  digitalWrite(sel1, HIGH);
  digitalWrite(sel2, HIGH);
  delay(1);
  temp.B = analogRead(lect_b);
  Serial.println("Tempb 4: ");
  Serial.println(temp.B);  
  input_neuron[9] = (1.0/212.0)*temp.B-1.20755;
  input_neuron[9] = constrain(input_neuron[9],0,1);
  temp.R = analogRead(lect_r);
  input_neuron[8] = 0.001038*temp.R-0.0322;
  input_neuron[8] = constrain(input_neuron[8],0,1);
//******************************************************************//
  Serial.println("Valor neurona 2, roja:");
  Serial.println(input_neuron[2]);
  Serial.println("Valor neurona 4, roja:");
  Serial.println(input_neuron[4]);
  Serial.println("Valor neurona 6, roja:");
  Serial.println(input_neuron[6]);
  Serial.println("Valor neurona 8, roja:");
  Serial.println(input_neuron[8]);
  
  Serial.println("Valor neurona 3, azul:");
  Serial.println(input_neuron[3]);
  Serial.println("Valor neurona 5, azul:");
  Serial.println(input_neuron[5]);
  Serial.println("Valor neurona 7, azul:");
  Serial.println(input_neuron[7]);
  Serial.println("Valor neurona 9, azul:");
  Serial.println(input_neuron[9]);
//***************************************************************//  
}
#endif
