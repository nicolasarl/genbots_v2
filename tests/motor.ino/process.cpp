#include <Arduino.h>
#include "pines.h"

int temp2 = 0;

void salida(float output_neuron[]){
  //Salida motor der

  if (output_neuron[0] < 0){
    
    temp2 = int(output_neuron[0]*255*(-1));
    analogWrite(PWM1, temp2);
    digitalWrite(SM1, LOW);//hacia detrás
    digitalWrite(SM1_2, HIGH);
  }
  else{
    temp2 = int(output_neuron[0]*255);
    analogWrite(PWM1, temp2);
    digitalWrite(SM1, HIGH);//hacia delante
    digitalWrite(SM1_2, LOW);    
  }
   //Salida motor izq

  if (output_neuron[1] < 0){
    
    temp2 = int(output_neuron[1]*255*(-1));
    analogWrite(PWM2, temp2);
    digitalWrite(SM2, LOW);//hacia detrás
    digitalWrite(SM2_2, HIGH);
  }
  else{
    temp2 = int(output_neuron[1]*255);
    analogWrite(PWM2, temp2);
    digitalWrite(SM2, HIGH);//hacia delante
    digitalWrite(SM2_2, LOW);    
  }
}
