

int IN_ri = A4; //Eingang Blinker rechts
int IN_le = A5; //Eingang Blinker links   
int IN_br = A6; //Eingang Bremse

int led_ri = 10; //PWM für Driver nr3
int led_le = 6;  //PWM für Driver nr2
int led_br = 9;  //PWM für Driver nr1



void setup(){
   pinMode(IN_ri, INPUT); //
   pinMode(IN_le, INPUT); //Input für Datenverarbeitung
   pinMode(IN_br, INPUT); //
  
   pinMode(led_ri, OUTPUT);
   pinMode(led_le, OUTPUT);
   pinMode(led_br, OUTPUT);  
}





void loop() {
  

 if (IN_le, LOW){
    digitalWrite(led_ri, HIGH);
    delay(2000);
    digitalWrite(led_ri, LOW);
    delay(2000);
 }
  



   
   if (IN_le, LOW) digitalWrite(led_le, HIGH);
   if (IN_br, LOW) digitalWrite(led_br, HIGH);
   
}
