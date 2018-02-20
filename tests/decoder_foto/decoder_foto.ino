/*Inclusión de cabeceras*/
#include "pines.h"
#include "variables.h"
#include "process.h"
#include "subprocess.h"


/*Inclusión de variables globales*/

float i_neuron[10];

void setup() {

  Serial.begin(9600);
  //Fototransistores
  pinMode(sel1, OUTPUT);
  pinMode(sel2, OUTPUT);
  pinMode(LECT_R, INPUT);
  pinMode(LECT_B, INPUT);

}

void loop() {

  lectura(i_neuron);
/*
  Serial.print("Valor neurona R: ");
  Serial.print(i_neuron[2]);
  Serial.print("\nValor neurona B: ");
  Serial.print(i_neuron[3]);
  Serial.println();
*/
}
