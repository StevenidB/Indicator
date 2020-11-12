// PLC program style

//-----------------------------------------------------
//int IN_ri = A4;  //Eingang         -> Rechter Blinker
//int IN_le = A5;  //Eingang         -> Linker  Blinker  
int IN_br = A3;  //Eingang         ->         Bremse


int led_le = 5;  //PWM für Driver -> Linker  Blinker
int led_ri = 6;  //PWM für Driver -> Rechter Blinker
int led_bl = 9;  //PWM für Driver -> Blaue Untergrundbeleuchtung
int led_br = 10; //PWM für Driver -> Bremslichter

int contact;
int state0;
int state1;
int state2;
int Statecnt0 = 0;
int StateCnt1 = 0;
int StateCnt2 = 0;
//-----------------------------------------------------

//-----------------------------------------------------
void setup()
{  
   pinMode(led_le, OUTPUT);
   digitalWrite(led_le, LOW);

   pinMode(led_ri, OUTPUT);
   digitalWrite(led_br, LOW);

   pinMode(led_bl, OUTPUT);
   digitalWrite(led_bl, LOW);
   
   pinMode(led_br, OUTPUT);
   digitalWrite(led_br, LOW);

   digitalWrite(IN_br, LOW);
   
//-----------------
//ANschalten Lichtshow:
//------>Blaue Lichter
   for (int i=1; i <= 3; i++)
     {
     digitalWrite(led_bl, HIGH);
     delay(300);
     digitalWrite(led_bl, LOW);
     delay(300);
     }
     
//------>Linker Blinker
   int x = 1;
   for (int i = 0; i > -1; i = i + x)
     {
     analogWrite(led_ri, i);
     delay(10);
       if (i == 255) 
         {
         x = -1; 
         delay(100);
           for (int i=1; i <= 2; i++)
             {
             digitalWrite(led_ri, LOW);
             delay(100);
             digitalWrite(led_ri, HIGH);
             delay(100);
             }
         }
     }
     
//------>Rechter Blinker
   x = 1;
   for (int i = 0; i > -1; i = i + x)
     {
     analogWrite(led_le, i);
     delay(10);
       if (i == 255) 
         {
         x = -1; 
         delay(100);
           for (int i=1; i <= 2; i++)
             {
             digitalWrite(led_le, LOW);
             delay(100);
             digitalWrite(led_le, HIGH);
             delay(100);
             }
         }
     }
     
//------>Bremslichter
   for (int i=1; i <= 4; i++)
     {
     digitalWrite(led_br, HIGH);
     delay(100);
     digitalWrite(led_br, LOW);
     delay(100);
     }
     delay(200);
   for (int i=1; i <= 2; i++)
     {
     digitalWrite(led_br, HIGH);
     delay(300);
     digitalWrite(led_br, LOW);
     delay(300);
     }

}

//-----------------------------------------------------

//-----------------------------------------------------
void loop() 
{
  
//------>Statemachine 0
   switch (state0)
   {
   int x = 1;
   contact=digitalRead(A6);
   
//--     
  case 0: 
    state0 = 10;
  break;      
    
//--     
  case 10: 
   if(contact == HIGH)
     {
      state0 = 20;   
     }
   else
     {
      state0 = 30;
     }
  break;      

//-- 
  case 20:
    digitalWrite(led_ri, HIGH);
    state0 = 10;
  break;  

//-- 
  case 30:
    digitalWrite(led_ri, LOW);
    state0 = 10;
  break;

       
   }


    
//---------------------->Statemachine 1
  switch (state1)
  {

//--     
  case 0:
    // Alle LEDs OFF
    state1 = 10;
    break;
    
//--  
  case 10:
    if (StateCnt1 >= 1000)
    {
      StateCnt1 = 0;
      //Blaue LED ON
      digitalWrite(led_bl, HIGH);
      state1 = 20;
    }
    StateCnt1 = StateCnt1 + 1;
  break;

//--    
  case 20:
    if (StateCnt1 >= 500)
    {
      StateCnt1 = 0;
      //Blaue LED OFF
      digitalWrite(led_bl, LOW);
      state1 = 0;
    }
    StateCnt1++;
    break;

  default:
    state1 = 0;
    break;
  }
  
//---------------------->Statemachine 2
  switch (state2)
  {
    
//--     
  case 0:
    // Alle LEDs OFF
    state2 = 10;
    break;

//--    
  case 10:
    if (StateCnt2 >= 500)
    {
      StateCnt2 = 0;
      //Rote LED ON
      digitalWrite(led_br, HIGH);
      state2 = 20;
    }
    StateCnt2 = StateCnt2 + 1;
    break;

//-- 
  case 20:
    if (StateCnt2 >= 500)
    {
      StateCnt2 = 0;
      //Rote LED OFF
      digitalWrite(led_br, LOW);
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
