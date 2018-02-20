/*Inclusión de cabeceras*/
#include "pines.h"
#include "variables.h"
#include "process.h"
#include "subprocess.h"
/*Inclusión de variables globales*/

float i_neuron[10];
float o_neuron[3];

void setup() {

  Serial.begin(9600);
  //Sensor TCS3200
  pinMode(s0,OUTPUT);
  pinMode(s1,OUTPUT);
  pinMode(s2,OUTPUT);
  pinMode(s3,OUTPUT);
  pinMode(OUT,INPUT);

  digitalWrite(s0, HIGH);
  digitalWrite(s1, HIGH);
}

void loop() {

    lectura(i_neuron);
    //ESTAS LINEAS SON EXTRAS PARA VER LOS RESULTADOS, NO VAN EN EL CODIGO FINAL
    Serial.print("Neurona comida: ");
    Serial.print(i_neuron[0]);
    Serial.print("\t");
    Serial.print("Neurona veneno: ");
    Serial.println(i_neuron[1]);
    delay(2000);
}

/*NOTA:
 * Tienen que medir el valor de la zona de comida y de la zona de veneno y meterlo en las variables que están para eso
 * en subprocess.cpp, que se llaman zonas comida y zonas veneno. Así puede compararlo y sacar un valor para las dos neuronas
 * de entrada y ver si esa parte funciona. De paso también comprobamos que los datos se almacenan y se van pasando entre funciones, 
 * algo bastante importante
 */
