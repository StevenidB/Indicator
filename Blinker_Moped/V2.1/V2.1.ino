// PLC program style


int IN_ri = A4; //Eingang Blinker rechts
int IN_le = A5; //Eingang Blinker links   
int IN_br = A6; //Eingang Bremse

int led_ri = 10; //PWM für Driver nr3
int led_le = 6;  //PWM für Driver nr2
int led_br = 9;  //PWM für Driver nr1



void setup()
{
   pinMode(LED_BUILTIN, OUTPUT);  
}


int state1;
int state2;
int StateCnt1 = 0;
int StateCnt2 = 0;


void loop() 
{

  //Statemachine 1
  switch (state1)
  {
  case 0:
    // Alle LEDs OFF
    state1 = 10;
    break;
    
  case 10:
    if (StateCnt1 >= 1000)
    {
      StateCnt1 = 0;
      //Rote LED ON
      //digitalWrite(LED_BUILTIN, HIGH);
      state1 = 20;
    }
    StateCnt1 = StateCnt1 + 1;
    break;
    
  case 20:
    if (StateCnt1 >= 500)
    {
      StateCnt1 = 0;
      //Rote LED OFF
      //digitalWrite(LED_BUILTIN, LOW);
      state1 = 0;
    }
    StateCnt1++;
    break;

  default:
    state1 = 0;
    break;
  }
  



  //Statemachine 2
  switch (state2)
  {
  case 0:
    // Alle LEDs OFF
    state2 = 10;
    break;
    
  case 10:
    if (StateCnt2 >= 500)
    {
      StateCnt2 = 0;
      //Rote LED ON
      digitalWrite(LED_BUILTIN, HIGH);
      state2 = 20;
    }
    StateCnt2 = StateCnt2 + 1;
    break;
    
  case 20:
    if (StateCnt2 >= 10)
    {
      StateCnt2 = 0;
      //Rote LED OFF
      digitalWrite(LED_BUILTIN, LOW);
      state2 = 0;
    }
    StateCnt2++;
    break;

  default:
    state2 = 0;
    break;
  }


  delay (1);
 
  
}
   
