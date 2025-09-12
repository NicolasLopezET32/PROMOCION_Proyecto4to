/*

En la función loop(), el sistema deberá alternar entre 4 estados, uno por segundo, y repetir el ciclo continuamente:

Estado        LED RGB         Buzzer        Mensaje por Serial (solo si DEBUG)
-------------------------------------------------------------------------------
Normal  	  Verde  	      Apagado  		"Estado: NORMAL"
INFORMACIÓN   Azul + Verde    Apagado       "Estado: INFORMACIÓN"
ADVERTENCIA   Rojo + Verde    Encendido     (si ENABLE_BUZZER)  "Estado: ADVERTENCIA"
EMERGENCIA    Rojo            Encendido     (si ENABLE_BUZZER)  "Estado: EMERGENCIA"
*/

#define LED_R    2
#define LED_B    3
#define LED_G    4
#define BUZZ     5
#define BOTON	 6

// #define DEBUG
 #define ENABLE_BUZZER
 #define USE_COLOR_COMBOS
// #define SECURITY_MODE


void setup()
{
  // INPUT / OUTPUT
  	pinMode( BUZZ   , OUTPUT ); //buzz
  	pinMode( LED_G  , OUTPUT ); // G
  	pinMode( LED_B  , OUTPUT ); // B
  	pinMode( LED_R  , OUTPUT ); // R
  	pinMode( BOTON  , INPUT ) ; // BOTON
  
  	Serial.begin(9600);// exclusivo para Debugg
}

void loop()
{
  
  #ifdef USE_COLOR_COMBOS
  	digitalWrite(LED_G, HIGH);
  	#ifdef DEBUG
  		Serial.println("Estado: Normal");
    #endif
  	delay(1000);
  
  	digitalWrite(LED_B, HIGH);
 		#ifdef DEBUG
  		Serial.println("Estado: Informacion");
    	#endif
  	delay(1000);
  
  	digitalWrite(LED_B, LOW);
  	digitalWrite(LED_R, HIGH);
  	#ifdef ENABLE_BUZZER
  		digitalWrite(BUZZ, HIGH);
  		#ifdef DEBUG
  			Serial.println("Estado: Advertencia");
   		#endif
  		digitalWrite(BUZZ, LOW);
 	#endif
	delay(1000);
  
  	digitalWrite(LED_G, LOW);
  	#ifdef ENABLE_BUZZER
  		digitalWrite(BUZZ, HIGH);
  		#ifdef DEBUG
  			Serial.println("Estado: EMERGENCIA");
   		#endif
  		digitalWrite(BUZZ, LOW);
 	#endif
  	delay(1000);
  
  	digitalWrite(LED_R, LOW);
  	delay(500);
  #endif
  
  
  
  
  #ifdef DEBUG
  	Serial.println("Estado: Normal");
  #endif
  delay(1000);
 
  #ifdef DEBUG
  	Serial.println("Estado: Informacion");
  #endif
  delay(1000);
  
  #ifdef ENABLE_BUZZER
  	digitalWrite(BUZZ, HIGH);
  	#ifdef DEBUG
  		Serial.println("Estado: Advertencia");
   	#endif
  	digitalWrite(BUZZ, LOW);

  #endif
  delay(1000);
  
  #ifdef ENABLE_BUZZER
  	digitalWrite(BUZZ, HIGH);
  	#ifdef DEBUG
  		Serial.println("Estado: EMERGENCIA");
   	#endif
  	digitalWrite(BUZZ, LOW);
  #endif
  delay(1000);
  
}




