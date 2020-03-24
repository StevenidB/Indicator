
int ledPin3  = 3;
int ledPin5  = 5;
int ledPin6  = 6;
int ledPin9  = 9;
int ledPin10 = 10;


void setup() {
  
}

void loop() {
  
  for (int fadeValue = 0 ; fadeValue <= 1000; fadeValue += 100) { 
    analogWrite(ledPin3, fadeValue);
    analogWrite(ledPin5, fadeValue);
    analogWrite(ledPin6, fadeValue);
    analogWrite(ledPin9, fadeValue);
    analogWrite(ledPin10, fadeValue);
    delay(10);
  }


  for (int fadeValue = 1000 ; fadeValue >= 0; fadeValue -= 100) {
   analogWrite(ledPin3, fadeValue);
   analogWrite(ledPin5, fadeValue);
   analogWrite(ledPin6, fadeValue);
   analogWrite(ledPin9, fadeValue);
   analogWrite(ledPin10, fadeValue);
   delay(10);
  }
}
