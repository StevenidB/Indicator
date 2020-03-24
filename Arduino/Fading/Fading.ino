
int ledPin3  = 3;
int ledPin5  = 5;
int ledPin6  = 6;
int ledPin9  = 9;
int ledPin10 = 10;


void setup() {
  
}

void loop() {
  
  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 10) { 
    analogWrite(ledPin3, fadeValue);
    analogWrite(ledPin5, fadeValue);
    analogWrite(ledPin6, fadeValue);
    analogWrite(ledPin9, fadeValue);
    analogWrite(ledPin10, fadeValue);
    delay(30);
  }


  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 10) {
   analogWrite(ledPin3, fadeValue);
   analogWrite(ledPin5, fadeValue);
   analogWrite(ledPin6, fadeValue);
   analogWrite(ledPin9, fadeValue);
   analogWrite(ledPin10, fadeValue);
   delay(30);
  }
}
