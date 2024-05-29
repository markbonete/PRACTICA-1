  #include <Arduino.h>

  // put function declarations here:
  #define LED_BUILTIN 23
  #define DELAY 100

  const int pinAnalogo = 35;

  void setup() {
    // put your setup code here, to run once:
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(115200);
    //delay(DELAY);
    Serial.println("HOLA MUNDO");
    
  }

  void loop() {
    // put your main code here, to run repeatedly:
    Serial.println("ledhigh");
    digitalWrite(LED_BUILTIN, HIGH);
    //delay(DELAY);
    Serial.println("ledlow");
    digitalWrite(LED_BUILTIN, LOW);
    delay(DELAY);

    int valor = analogRead(pinAnalogo);
  
    // Mostramos el valor leído en el monitor serie
    Serial.print("Valor leído: ");
    Serial.println(valor);
    delay(DELAY);
    }