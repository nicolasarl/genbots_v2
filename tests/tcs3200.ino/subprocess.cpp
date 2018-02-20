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

/*Declaracion constantes*/

int MM; //define un rango alrededor del 0 equivalente al 5% del rango, en el cual también se considera que el motor debe pararse
int ML; //define el rango en torno al 0 para escoger los LED's

typedef struct{
  int R;
  int G;
  int B;
}zonas;

zonas temp;//Variable temporal tipo struct usada para almacenar los valores en bruto de cada cuadrante

const int INTENSIDAD_MIN = int((4.32*1023)/5);//maximo valor en la entrada analógica cambiado a binario
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
   

    //ESTAS LINEAS SON EXTRAS PARA VER LOS RESULTADOS, NO VAN EN EL CODIGO FINAL
    Serial.print(rgb.R);
    Serial.print("\t");
    Serial.print(rgb.G);
    Serial.print("\t");
    Serial.println(rgb.B);

//compara el valor con el del veneno 
 
if ((rgb.R < rgb.B)&&(rgb.G > rgb.B)&& (rgb.R < 35)){
 
    input_neuron[0] = 0;//ponemos la neurona de comida a 0 
    input_neuron[1] = 1;//ponemos la neurona de veneno a 1 
    //Serial.println(input_neuron[1]);
  }  
 
//compara el valor de la comida, solo entra si no está en la zona de veneno 
 
  if ((rgb.B < rgb.R)&&(rgb.G > rgb.B)&& (rgb.G < rgb.R)){ 
 
    input_neuron[0] = 1;//ponemos la neurona de comida a 1 
    input_neuron[1] = 0;//ponemos la neurona de veneno a 0 
  }
/*Serial.print("\t"); 
Serial.print(input_neuron[0]);
Serial.print("\t");
Serial.println(input_neuron[1]);*/


//Apagamos el sensor

digitalWrite(s0, LOW);
digitalWrite(s1, LOW); 
}

#endif
