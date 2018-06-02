El proyecto consiste en la elaboraci�n del software integrado en los elementos de una colonia de robots con capacidad 
evolutiva. Se basa en la publicaci�n 'Evolutionary Conditions for the Emmergence of Communication in Robots' de Dr. Dario
Floreano et al. 

En el c�digo se desarrolla la parte de control de hardware de un robot, empleando un microcontrolador Arduino Nano.

La estructura b�sica del c�digo se desglosa en tres m�dulos: main, process y subprocess. El m�dulo main se encarga de la
navegaci�n a trav�s del c�digo, mientras que process contiene distintas funciones y la llamada a las funciones m�s espec�ficas
que se encuentran en el m�dulo subprocess. La estructura general por archivos se ha desarrollado para facilitar la comprensi�n
del c�digo. 

El funcionamiento de un ciclo consiste en leer las entradas, traducir dichas entradas en valores de las neuronas de entrada
a la red neuronal y posteriormente procesar los valores seg�n el c�digo gen�tico del individuo. Tras el procesamiento se 
obtienen los valores de las neuronas de salida que son procesados para obtener los valores de los actuadores.

Autor�a disponible en los contribuyentes del proyecto.

Este proyecto se ha desarrollado en el marco de un proyecto del Museo de la Ciencia y el Cosmos, San Crist�bal de La Laguna
Tenerife, Espa�a.