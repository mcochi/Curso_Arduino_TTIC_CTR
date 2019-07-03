/* Knight Rider 2
   --------------
   Reducing the amount of code using for(;;).
   (cleft) 2005 K3, Malmo University
   @author: David Cuartielles
   @hardware: David Cuartielles, Aaron Hallborg
   @modified by: aprendiendoarduino
*/

int pinArray[] = {2, 3, 4, 5, 6};
int count = 0;
int timer = 100;
String leido = "";
void setup() {
  Serial.begin(9600);
  Serial.println("Introduce un número de texto: ");
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  
  // we make all the declarations at once
  for (count = 0; count < 5; count++) {
    pinMode(pinArray[count], OUTPUT);
  }
}

void loop() {
  timer = leeserie();  //El valor leido por analog read es el temporizador
  for (count = 0; count < 5; count++) {
    timer = leeserie();
    digitalWrite(pinArray[count], HIGH);
    delay(timer);
    digitalWrite(pinArray[count], LOW);
    delay(timer);
  }
  for (count = 4; count >= 0; count--) {
    timer = leeserie();
    //Serial.println(timer);
    digitalWrite(pinArray[count], HIGH);
    delay(timer);
    digitalWrite(pinArray[count], LOW);
    delay(timer);
  }
}

int leeserie() {
    int timer = 1000;
    if (Serial.available() > 0) {
    leido = ""; //vacio lo leido
    do {
      char caracter_leido;
      delay(5);
      caracter_leido = Serial.read();
      leido += caracter_leido;
    }  while (Serial.available() > 0);
    timer = leido.toInt();
    Serial.println(leido);
    return timer;
    }
    else
    return timer;
}
