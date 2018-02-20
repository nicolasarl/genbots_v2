Descripción hardware:

**Detección de colores en el suelo usamos un sensor TCS3200
**Detección colores ambiente: empleamos 4 grupos de 2 fototransistores. El comportamiento de los mismos es el siguiente:
	- Se activa el bloque utilizando un decoder: cuadrante 1 codificado como 00, cuadrante 2 como 01, etc
	- De cada pareja uno posee un fitro rojo y el otro un filtro azul, así conseguimos diferenciar ambos colores
	- El valor cuando la detección es 0, es decir, oscuridad, está entorno a los 4.32 V mientras que con luz está en 0.07
	- Ello implica que la lógica está invertida y en el diseño del software se ha tenido en cuenta, además del escalado a 5V
**Motores: se emplea un integrado para su control. REF: L293NE. Datasheet adjunta.
**LED's: utilizamos LED's RGB con cátodo común. Para activarlos se emplean interruptores controlados.
