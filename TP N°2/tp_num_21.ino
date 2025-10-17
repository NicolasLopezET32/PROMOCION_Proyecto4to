#define BOTON 3
#define LED_R 4
#define LDR   A0


void setup()
{
  pinMode(BOTON	, INPUT_PULLUP );
  pinMode(LED_R	, OUTPUT	   );
  pinMode(LDR	, INPUT 	   );
  Serial.begin(9600);
}

void loop()
{ 
  bool valorBoton = digitalRead(BOTON);
  int valorLuz = analogRead(LDR);
  int totalLuz = map(valorLuz, 0, 104,100, 500);
  Serial.print("Luz = ");
  Serial.println(totalLuz);
  
  
  Serial.print("Boton = ");
  Serial.println(valorBoton);
  
  if(valorBoton == 1){
    
    digitalWrite(LED_R, LOW);
    
  }else{
    
    digitalWrite(LED_R, HIGH);
    
  }
}