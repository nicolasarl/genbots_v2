#ifndef _PROCESS_CPP
#define _PROCESS_CPP
#include <Arduino.h>
#include <math.h>
#include "subprocess.h"
#include "pines.h"


typedef struct{
//numeros entre -128 y 127 Control de versiones def
  float gen1[10] = {150, 150, 150, 150, 150, -150, -150,-150, -150, -150};//valores genes para motor izq
  float gen2[10] = {150, 150, 150, 150, 150, -150, -150,-150, -150, -150};//valores genes para motor der
  float gen3[10] = {31, 99, 98, 124, 44, 96, 124, 52, 97, 2};//valores genes para LED's
}genes;
genes gen;
float temp1 = 0;//variable temporal utilizada para almacenar calculos intermedios
float temp2 = 0;//variable temporal utilizada para almacenar calculos intermedios

/*-----------------Funciones principales--------------------------------------*/

void lectura(float input_neuron []){
  tcs(input_neuron);
  phototransistors(input_neuron);
}

void calculo(float input_neuron [], float output_neuron[]){//Realiza el cálculo de las neuronas de salida

  for (int i = 0; i < 9; i++){//motor izq
//Serial.println("input neuron:");
//Serial.println(input_neuron[i]);
    temp1 += input_neuron[i]*gen.gen1[i];
    
  }
  
  //******************************************************************//
//   Serial.println("Valor de x para tanh motor izq.: p process");
//   Serial.println(temp1);
   //******************************************************************//

 output_neuron[0] = tanh(temp1/128);//Control de versiones 
 
   //******************************************************************//
//   Serial.println("Valor de la neurona 0 motor izq.: p process");
//   Serial.println(output_neuron[0]);
   //******************************************************************//

   temp1=0;//Control de versiones 
  for (int j = 0; j < 9; j++){//motor der
    temp1 += input_neuron[j]*gen.gen2[j];
    }

    //******************************************************************//
    Serial.println("Valor de x para tanh motor der.: p process");
    Serial.println(temp1/128);
    //******************************************************************//

    output_neuron[1] = tanh(temp1/128);//Control de versiones

    //******************************************************************//
    Serial.println("Valor de la neurona 1 motor der.: p process");
    Serial.println(output_neuron[1]); 
    //******************************************************************//

   temp1=0; //Control de versiones 
  for (int n = 0; n < 9; n++){//Led's
    temp1 += input_neuron[n]*gen.gen3[n];
    }
    
    //******************************************************************//
    Serial.println("Valor de x para tanh leds: p process");
    Serial.println(temp1/128);
    //******************************************************************//
    
    output_neuron[2] = tanh(temp1/128);//Control de versiones
   
    //******************************************************************//
    Serial.println("Valor de la neurona 2 led: p process");
    Serial.println(output_neuron[2]); 
    //******************************************************************//
  
    temp1=0;//Control de versiones 
}

void salida(float output_neuron[]){

    //Salida motor der

    if (output_neuron[0] < 0){

      if((output_neuron[0]*(-1)) < 0.3){//definimos un rango entre 0 y -0.3 en el que paramos las ruedas. Esto se hace para proteger los motores
        temp2 = 0;
      }
      else{
        temp2 = int(output_neuron[0]*255*(-1)/2) + 100;
      }
      analogWrite(pwm1, temp2);

      //******************************************************************//
      Serial.println("Velocidad motor derecho: p process");
      Serial.println(temp2);
      //******************************************************************//
      
      digitalWrite(sm1, LOW);//hacia detrÃ¡s
      digitalWrite(sm1_2, HIGH);
    }
    else{
      if(output_neuron[0] < 0.3){
        temp2 = 0;
      }
      else{//Se define un rango entre 0 y 0.3 donde se pone velocidad nula para proteger los motores
        temp2 = int(output_neuron[0]*255/2) + 100;
      }
      analogWrite(pwm1, temp2);
      
      //******************************************************************//
      Serial.println("Velocidad motor derecho: p process");
      Serial.println(temp2);
      //******************************************************************//
      
      digitalWrite(sm1, HIGH);//hacia delante
      digitalWrite(sm1_2, LOW);
    }
     //Salida motor izq

    if (output_neuron[1] < 0){
      if(output_neuron[1] > -0.3){//definimos un rango entre 0 y -0.3 en el que paramos las ruedas. Esto se hace para proteger los motores
        temp2 = 0;
      }
      else{
        temp2 = int(output_neuron[1]*255*(-1)/2) + 100;
      }
      analogWrite(pwm2, temp2);
      
      //******************************************************************//
      Serial.println("Velocidad motor izquierdo: p process");
      Serial.println(temp2);
      //******************************************************************//
      
      digitalWrite(sm2, LOW);//hacia detrÃ¡s
      digitalWrite(sm2_2, HIGH);
    }
    else{
      if(output_neuron[1] < 0.3){//Se define un rango entre 0 y 0.3 donde se pone velocidad nula para proteger los motores
        temp2 = 0;
      }
      else{
        temp2 = int(output_neuron[1]*255/2) + 100;
      }
      analogWrite(pwm2, temp2);
      
      //******************************************************************//
      Serial.println("Velocidad motor izquierdo: p process");
      Serial.println(temp2);
      //******************************************************************//
      
      digitalWrite(sm2, HIGH);//hacia delante
      digitalWrite(sm2_2, LOW);
    }
//LED's

//******************************************************************//
      Serial.println("Valor neurona 2/2: p process");
      Serial.println(output_neuron[2]);
//******************************************************************//

  if (output_neuron[2] < 0){//Control de versiones 
    digitalWrite(ledr, LOW);
    digitalWrite(ledb, LOW);
  }
  else if(output_neuron[2] == 0){//Azul cuando mayor que 0
    digitalWrite(ledr, HIGH);
    digitalWrite(ledb, LOW);
  }
  else{//Azul
    digitalWrite(ledr, HIGH);
    digitalWrite(ledb, LOW);
  }
}
#endif
