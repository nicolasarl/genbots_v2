El proyecto consiste en la elaboración del software integrado en los elementos de una colonia de robots con capacidad 
evolutiva. Se basa en la publicación 'Evolutionary Conditions for the Emmergence of Communication in Robots' de Dr. Dario
Floreano et al. 

En el código se desarrolla la parte de control de hardware de un robot, empleando un microcontrolador Arduino Nano.

La estructura básica del código se desglosa en tres módulos: main, process y subprocess. El módulo main se encarga de la
navegación a través del código, mientras que process contiene distintas funciones y la llamada a las funciones más específicas
que se encuentran en el módulo subprocess. La estructura general por archivos se ha desarrollado para facilitar la comprensión
del código. 

El funcionamiento de un ciclo consiste en leer las entradas, traducir dichas entradas en valores de las neuronas de entrada
a la red neuronal y posteriormente procesar los valores según el código genético del individuo. Tras el procesamiento se 
obtienen los valores de las neuronas de salida que son procesados para obtener los valores de los actuadores.

Autoría disponible en los contribuyentes del proyecto.

Este proyecto se ha desarrollado en el marco de un proyecto del Museo de la Ciencia y el Cosmos, San Cristóbal de La Laguna
Tenerife, España.