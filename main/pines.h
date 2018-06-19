#ifndef _PINES_H
#define _PINES_H
/*Pins declaration def*/
//NOTA: el pin 15 esta liberado
//TCS3200 Color Sensor
const int s0 = 11;//Verde
const int s1 = 12;//Amarillo
const int s2 = 10;//Naranja
const int s3 = 9;//Morado
const int out = 14;//Azul
//DC Motors

//IZQ: VERDE
const int sm1 = 7;
const int sm1_2 = 8;
const int pwm1 = 6;//columna h protoboard
//DER: VIOLETA o AZUL
const int sm2 = 3;
const int sm2_2 = 4;
const int pwm2 = 5;//columna c protoboard

//LED's OUTPUT
const int ledr = 13;//morado sube segundo piso
const int ledb = 16;//azul sube segundo piso
//Phototransistors
const int sel1 = 2; //se reasigna por falta de pines: blanco sube segundo piso
const int sel2 = 17;//gris sube segundo piso
const int lect_r = 18;//marron sube segundo piso
const int lect_b = 19;//amarillo sube segundo piso

#endif
