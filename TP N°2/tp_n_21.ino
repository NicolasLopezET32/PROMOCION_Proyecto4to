// C++ code
//

#define BOTON 	2
#define LDR		A2


void setup()
{
  pinMode(BOTON	, 	INPUT_PULLUP);
  pinMode(LDR	,	INPUT);
  
  Serial.begin(9600);
}

void loop()
{
  bool valorBot = digitalRead(BOTON);
  int  valorLuz = analogRead(LDR);
  int cantLuz = map(valorLuz,1,310,100,500);
  int luzMaxima = constrain(cantLuz,100,500);


  
  Serial.print("Boton= ");
  Serial.print(valorBot);
  Serial.print(" Luz= ");
  Serial.println(luzMaxima);
  
}