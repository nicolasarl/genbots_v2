Descripci�n hardware:

**Detecci�n de colores en el suelo usamos un sensor TCS3200
**Detecci�n colores ambiente: empleamos 4 grupos de 2 fototransistores. El comportamiento de los mismos es el siguiente:
	- Se activa el bloque utilizando un decoder: cuadrante 1 codificado como 00, cuadrante 2 como 01, etc
	- De cada pareja uno posee un fitro rojo y el otro un filtro azul, as� conseguimos diferenciar ambos colores
	- El valor cuando la detecci�n es 0, es decir, oscuridad, est� entorno a los 4.32 V mientras que con luz est� en 0.07
	- Ello implica que la l�gica est� invertida y en el dise�o del software se ha tenido en cuenta, adem�s del escalado a 5V
**Motores: se emplea un integrado para su control. REF: L293NE. Datasheet adjunta.
**LED's: utilizamos LED's RGB con c�todo com�n. Para activarlos se emplean interruptores controlados.
