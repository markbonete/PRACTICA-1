# PRACTICA-1

## Codi sencer
 ```cpp
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
```

## Explicació del codi per parts
### Definicions i declaracions
```cpp
#define LED_BUILTIN 23
#define DELAY 100
const int pinAnalogo = 35;
```
- #define LED_BUILTIN 23: Defineix una constant LED_BUILTIN amb el valor 23. Aquesta és la pin on el LED està connectat.
- #define DELAY 100: Defineix una constant DELAY amb el valor 100 mil·lisegons. Aquest és el retard utilitzat en el bucle principal.
- const int pinAnalogo = 35: Declara una constant pinAnalogo amb el valor 35. Aquesta és la pin on es farà la lectura analògica.

### Funció `setup()`
```cpp
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
  Serial.println("HOLA MUNDO");
}
```
- pinMode(LED_BUILTIN, OUTPUT);: Configura el pin LED_BUILTIN (23) com a sortida.
- Serial.begin(115200);: Inicialitza la comunicació sèrie amb una velocitat de 115200 bauds.
- Serial.println("HOLA MUNDO");: Envia la cadena "HOLA MUNDO" al monitor sèrie per confirmar que el sistema ha començat correctament.

### Funció `loop()`
```cpp
void loop() {
  Serial.println("ledhigh");
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.println("ledlow");
  digitalWrite(LED_BUILTIN, LOW);
  delay(DELAY);

  int valor = analogRead(pinAnalogo);

  Serial.print("Valor leído: ");
  Serial.println(valor);
  delay(DELAY);
}
```
- Serial.println("ledhigh");: Envia la cadena "ledhigh" al monitor sèrie.
- digitalWrite(LED_BUILTIN, HIGH);: Envia un senyal alt (HIGH) al pin LED_BUILTIN (23), encenent el LED.
- Serial.println("ledlow");: Envia la cadena "ledlow" al monitor sèrie.
- digitalWrite(LED_BUILTIN, LOW);: Envia un senyal baix (LOW) al pin LED_BUILTIN (23), apagant el LED.
- delay(DELAY);: Pausa l'execució durant DELAY mil·lisegons (100 ms).
- int valor = analogRead(pinAnalogo);: Llegeix el valor analògic del pin pinAnalogo (35) i l'emmagatzema a la variable valor.
- Serial.print("Valor leído: ");: Envia la cadena "Valor leído: " al monitor sèrie.
- Serial.println(valor);: Envia el valor llegit al monitor sèrie.
- delay(DELAY);: Pausa l'execució durant DELAY mil·lisegons (100 ms).

### Flux d'execució
1. El programa inicialitza els pins i la comunicació sèrie en la funció setup().
2. El bucle loop() s'executa repetidament:
 - Encén el LED i imprimeix "ledhigh" al monitor sèrie.
 - Apaga el LED i imprimeix "ledlow" al monitor sèrie.
 - Llegeix el valor del sensor analògic i l'imprimeix al monitor sèrie.
 - Cada operació de lectura/escriptura està separada per un retard de 100 ms (DELAY).
Aquest codi bàsic fa que el LED s'encengui i s'apagui contínuament mentre llegeix valors d'un pin analògic i els envia al monitor sèrie.

### Diagrama de temps
|Temps (ms) | 0    | 100  | 200  | 300  | 400  | 500  | 600  |
|-----------|------|------|------|------|------|------|------|
|LED        | HIGH | LOW  | HIGH | LOW  | HIGH | LOW  | HIGH |
|Missatge S |ledhigh|ledlow|Valor Llegit|ledhigh|ledlow|Valor Llegit|
|Retard     |------|100ms |------|100ms |------|100ms |------|

### Efectes del delay vist en l'oscil·loscopi
1. Amb un delay de 500 ms (0,5 segons) podem veure que per cada canvi el senyal és quadrat i periòdic. 
2. Hem modificat el delay fent-ho un comentant la línea delay, per aconseguir un delay de 0ms. Tot i així, segueix existint temps d'espera entre els dos canvis, encara que aquest correspon al temps que es tarden en executar les ordres del codi mateix. Per tant, el loop triga molt més que les ordes de canvi de voltatges, per tant el LED es queda majoritàriament apagat.El canvi puntual que té el LED de l'estat apagat a encés es poc exacte i la senyal varia massa. 
3. S'ha canviat l'ordre d'encesa i apagat del LED mantenint el codi com en l'imatge anterior. La diferència ara respecte l'anterior és el LED majoritàriament es queda encés.
