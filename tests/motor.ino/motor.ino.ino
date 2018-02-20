#include "pines.h"
#include "process.h"

void setup() {
  
  //Motores
  pinMode(SM1, OUTPUT);
  pinMode(SM1_2, OUTPUT);
  pinMode(PWM1, OUTPUT);
  pinMode(SM2, OUTPUT);
  pinMode(SM2_2, OUTPUT);
  pinMode(PWM2, OUTPUT);
  Serial.begin(9600);


}
float out[]= {0,0,0};
void loop() {

delay(5000);
out[0] = 0;
out[1] = 0;

  for (int i = 0; i <= 19; i++){

    out[0] = out[0] + 0.05;
    salida(out);
    Serial.print("Prueba numero: ");
    Serial.print(i);
    Serial.print("\t");
    Serial.println(out[0]);
    delay(10000);
  }
out[0] = 0;
out[1] = 0;
  for (int n = 20; n <= 39; n++){

    out[0] = out[0] + 0.05;
    out[1] = out[1] + 0.05;
    salida(out);
    Serial.print("Prueba dos motores numero: ");
    Serial.print(n);
    Serial.print("\t");
    Serial.println(out[0]);
    Serial.print("\t");
    Serial.println(out[1]);
    Serial.println();
    delay(10000);
  }

}
