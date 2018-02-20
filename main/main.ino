/*Inclusión de cabeceras*/
#include "pines.h"
#include "variables.h"
#include "process.h"
#include "subprocess.h"
/*Inclusión de variables globales*/

float i_neuron[10];
float o_neuron[3];
void setup() {
  /*Asignación los pines necesarios*/

  //Sensor TCS3200
  pinMode(s0,OUTPUT);
  pinMode(s1,OUTPUT);
  pinMode(s2,OUTPUT);
  pinMode(s3,OUTPUT);
  pinMode(OUT,INPUT);
  //Motores
  pinMode(SM1, OUTPUT);
  pinMode(SM1_2, OUTPUT);
  pinMode(PWM1, OUTPUT);
  pinMode(SM2, OUTPUT);
  pinMode(SM2_2, OUTPUT);
  pinMode(PWM2, OUTPUT);
  //LED's
  pinMode(LEDR,OUTPUT);
  pinMode(LEDG,OUTPUT);
  pinMode(LEDB,OUTPUT);
  //Fototransistores
  pinMode(sel1, OUTPUT);
  pinMode(sel2, OUTPUT);
  pinMode(LECT_R, INPUT);
  pinMode(LECT_B, INPUT);
}

void loop() {

  lectura(i_neuron);
  calculo(i_neuron, o_neuron);
  salida(o_neuron);

}
