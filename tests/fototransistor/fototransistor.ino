const int LDRAZUL = 18;
const int LDRROJO = 19;  
   
int valorAZUL = 0;
int valorROJO = 0;
float neuronaAZUL = 0;
float neuronaROJA = 0;

void setup() {
  Serial.begin(9600); 
  pinMode(LDRAZUL,INPUT);
  pinMode(LDRROJO,INPUT);  
 
}

void loop() {
  
 valorAZUL = analogRead(LDRAZUL);
 //Serial.print("El valor del LDR AZUL es: ");
 Serial.print(valorAZUL);
 Serial.print("\t");

 valorROJO = analogRead(LDRROJO);
 //Serial.print("El valor del LDR ROJO es: ");
 Serial.println(valorROJO);
 

 neuronaAZUL = (1.0/212.0)*valorAZUL-1.20755;
  neuronaAZUL = constrain(neuronaAZUL,0,1);
 Serial.print("El valor mandado a la neurona azul es: ");
 Serial.println(neuronaAZUL);

 neuronaROJA = 0.001038*valorROJO-0.0322;
  neuronaROJA = constrain(neuronaROJA,0,1);
 Serial.print("El valor mandado a la neurona roja es: ");
 Serial.println(neuronaROJA);
 

 
 delay(1000);
}
