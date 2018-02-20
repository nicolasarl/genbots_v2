Aclaraciones: El programa main no se ha podido testear de forma completa debido a que no se disponen de suficientes robots 
para recrear el experimento del Dr. Floreano et al. En su lugar, se realizaron pruebas por módulos.

Breve explicación:

El proyecto se divide en procesos y subprocesos, de manera que se simplifique la modificación, prueba y/o revisión
del mismo. Se emplea una estructura de encabezados .h con las declaraciones y archivos .cpp con la descripción

**Procesos: grupo de acciones generales que debe realizar el robot. En principio: lectura sensores, cálculo valores de
	    las neuronas y ejecución de las acciones de salida. En un futuro deberá incluirse la lectura de instrucciones
	    vía wifi y la lectura y almacenamiento de los valores de las neuronas.
	    
**Subprocesos: grupo de acciones más reducido que simplifica la revisión del código. Actualmente: lectura y procesamiento color
	    del suelo; lectura y procesamiento de todos los cuadrantes de luz ambiente.
**Variables: las constantes y variables temporales están declaradas e inicializadas en los archivos correspondientes a su entorno
	    de empleo(ejemplo: subproceso). Las variables globales se usan exclusivamente en el main y son vectores que almacenan
	    los datos de las neuronas y que serán los argumentos de los distintos procesos y subprocesos.
**Main: su función es distribuir el flujo del programa llamando funciones. Además se utiliza para inicializar los pines.


Aspectos a tener en cuenta para su adaptación al microcontrolador ESP32:

Para utilizar el código actual con ESP32 es necesario solventar dos problemas: 

-Librería Freqcount usada para la instrucción pulseIn asociada a la lectura del sensor TCS3200.
-Librería asociada al comando analogWrite (usada para PWM)

Ninguna de las librerías arriba indicadas tienen su equivalencia para ESP32 y por tanto deberá hacerse un diseño alternativo para 
poder usar el código co nesos microcontroladores y así poder utilizar WIFI. En el caso del comando pulseIn la solución puede pasar
por leer el valor en bruto de la señal y emplearla o traducirla a una rango preestablecido.
En el caso del PWM la solución no es tan aparente, pues deberá diseñarse un control del ciclo de trabajo pwm que se ejecute 
en paralelo al resto de instrucciones.

En el caso de los pines, tanto arduino NANO como ESP32 poseen las misma cantidad de pines y además el ESP32 tiene más salidas
PWM, por lo cuál no habrá poblema en empelar el mismo hardware y patrón de conexiones.

