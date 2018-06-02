/*Inclusión de cabeceras*/
#include "pines.h"
#include "variables.h"
#include "process.h"
#include "subprocess.h"
/*Inclusión de variables globales*/

float i_neuron[10];
float o_neuron[3];
int tiempo_acumulado = 0;

void setup() {
  /*Asignación los pines necesarios*/
  Serial.begin(9600);
  //Sensor TCS3200
  pinMode(s0,OUTPUT);
  pinMode(s1,OUTPUT);
  pinMode(s2,OUTPUT);
  pinMode(s3,OUTPUT);
  pinMode(out,INPUT);
  //Motores
  pinMode(sm1, OUTPUT);
  pinMode(sm1_2, OUTPUT);
  pinMode(pwm1, OUTPUT);
  pinMode(sm2, OUTPUT);
  pinMode(sm2_2, OUTPUT);
  pinMode(pwm2, OUTPUT);
  //LED's
  pinMode(ledr,OUTPUT);
  pinMode(ledb,OUTPUT);
  //Fototransistores
  pinMode(sel1, OUTPUT);
  pinMode(sel2, OUTPUT);
  pinMode(lect_r, INPUT);
  pinMode(lect_b, INPUT);
}

void loop() {

/*digitalWrite(sel1,LOW);
digitalWrite(sel2,LOW);
Serial.println(analogRead(lect_r));
Serial.println(analogRead(lect_b));*/

//Programa general def
  lectura(i_neuron);
  calculo(i_neuron, o_neuron);
  salida(o_neuron);


  if ((millis()-tiempo_acumulado) < 100){// Control de versiones cambiado a 100
    delay(100-(millis()-tiempo_acumulado));
  }
  tiempo_acumulado = millis();

}
