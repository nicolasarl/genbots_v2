Aclaraciones: El programa main no se ha podido testear de forma completa debido a que no se disponen de suficientes robots 
para recrear el experimento del Dr. Floreano et al. En su lugar, se realizaron pruebas por m�dulos.

Breve explicaci�n:

El proyecto se divide en procesos y subprocesos, de manera que se simplifique la modificaci�n, prueba y/o revisi�n
del mismo. Se emplea una estructura de encabezados .h con las declaraciones y archivos .cpp con la descripci�n

**Procesos: grupo de acciones generales que debe realizar el robot. En principio: lectura sensores, c�lculo valores de
	    las neuronas y ejecuci�n de las acciones de salida. En un futuro deber� incluirse la lectura de instrucciones
	    v�a wifi y la lectura y almacenamiento de los valores de las neuronas.
	    
**Subprocesos: grupo de acciones m�s reducido que simplifica la revisi�n del c�digo. Actualmente: lectura y procesamiento color
	    del suelo; lectura y procesamiento de todos los cuadrantes de luz ambiente.
**Variables: las constantes y variables temporales est�n declaradas e inicializadas en los archivos correspondientes a su entorno
	    de empleo(ejemplo: subproceso). Las variables globales se usan exclusivamente en el main y son vectores que almacenan
	    los datos de las neuronas y que ser�n los argumentos de los distintos procesos y subprocesos.
**Main: su funci�n es distribuir el flujo del programa llamando funciones. Adem�s se utiliza para inicializar los pines.


Aspectos a tener en cuenta para su adaptaci�n al microcontrolador ESP32:

Para utilizar el c�digo actual con ESP32 es necesario solventar dos problemas: 

-Librer�a Freqcount usada para la instrucci�n pulseIn asociada a la lectura del sensor TCS3200.
-Librer�a asociada al comando analogWrite (usada para PWM)

Ninguna de las librer�as arriba indicadas tienen su equivalencia para ESP32 y por tanto deber� hacerse un dise�o alternativo para 
poder usar el c�digo co nesos microcontroladores y as� poder utilizar WIFI. En el caso del comando pulseIn la soluci�n puede pasar
por leer el valor en bruto de la se�al y emplearla o traducirla a una rango preestablecido.
En el caso del PWM la soluci�n no es tan aparente, pues deber� dise�arse un control del ciclo de trabajo pwm que se ejecute 
en paralelo al resto de instrucciones.

En el caso de los pines, tanto arduino NANO como ESP32 poseen las misma cantidad de pines y adem�s el ESP32 tiene m�s salidas
PWM, por lo cu�l no habr� poblema en empelar el mismo hardware y patr�n de conexiones.

