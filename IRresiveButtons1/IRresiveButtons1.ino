/*
 * Тестовая программа для проверки пульта дистанционного управления
 * Коды клавиш:
    OK = FF02FD
    ARROW_UP = FF629D
    ARRIW_LEFT = FF22DD
    ARROW_RIGHT = FFC23D
    ARROW_DOWN = FFA857
    DIGIT_1 = FF6897
    DIGIT_2 = FF9867
    DIGIT_3 = FFB04F
    DIGIT_4 = FF30CF
    DIGIT_5 = FF18E7
    DIGIT_6 = FF7A85
    DIGIT_7 = FF10EF
    DIGIT_8 = FF38C7
    DIGIT_9 = FF5AA5
    DIGIT_0 = FF4AB5
    DIGIT_STAR = FF42BD
    DIGIT_OCTOTORP = FF52AD
 */

#include <IRremote.h>
//===================================================================
// КОНСТАНТЫ
//===================================================================
#define RECV_PIN 2

#define OK 0xFF02FD
#define ARROW_UP 0xFF629D
#define ARROW_LEFT 0xFF22DD
#define ARROW_RIGHT 0xFFC23D
#define ARROW_DOWN 0xFFA857
#define DIGIT_1 0xFF6897
#define DIGIT_2 0xFF9867
#define DIGIT_3 0xFFB04F
#define DIGIT_4 0xFF30CF
#define DIGIT_5 0xFF18E7
#define DIGIT_6 0xFF7A85
#define DIGIT_7 0xFF10EF
#define DIGIT_8 0xFF38C7
#define DIGIT_9 0xFF5AA5
#define DIGIT_0 0xFF4AB5
#define DIGIT_STAR 0xFF42BD
#define DIGIT_OCTOTORP 0xFF52AD

//===================================================================
// ГЛОБАЛЬНЫЕ ПЕРЕМЕННЫЕ
//===================================================================

IRrecv irrecv(RECV_PIN);

decode_results results;

//===================================================================
// НАЧАЛЬНАЯ УСТАНОВКА
//===================================================================
void setup()
{
  Serial.begin(9600);
  // In case the interrupt driver crashes on setup, give a clue
  // to the user what's going on.
  Serial.println("Wait enabling IRin...");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("> IRin enabled");
}

void loop() 
{
  if(irrecv.decode(&results)) 
  {
    long x = results.value;
    switch(x)
    {
        case OK:
            Serial.println("OK");
        break;
        case ARROW_UP:
            Serial.println("ARROW_UP");
        break;
        case ARROW_LEFT:
            Serial.println("ARROW_LEFT");
        break;
        case ARROW_RIGHT:
            Serial.println("ARROW_RIGHT");
        break;
        case ARROW_DOWN:
            Serial.println("ARROW_DOWN");
        break;
        case DIGIT_1:
            Serial.println("DIGIT_1");
        break;
        case DIGIT_2:
            Serial.println("DIGIT_2");
        break;
        case DIGIT_3:
            Serial.println("DIGIT_3");
        break;
        case DIGIT_4:
            Serial.println("DIGIT_4");
        break;
         case DIGIT_5:
            Serial.println("DIGIT_5");
        break;
        case DIGIT_6:
            Serial.println("DIGIT_6");
        break;
        case DIGIT_7:
            Serial.println("DIGIT_7");
        break;
        case DIGIT_8:
            Serial.println("DIGIT_8");
        break;
        case DIGIT_9:
            Serial.println("DIGIT_9");
        break;
        case DIGIT_0:
            Serial.println("DIGIT_0");
        break;
        case DIGIT_STAR:
            Serial.println("DIGIT_STAR");
        break;
        case DIGIT_OCTOTORP:
            Serial.println("DIGIT_OCTOTORP");
        break;
        default:
            Serial.println(x, HEX);
        break;
    }
    // Receive the next value
    irrecv.resume(); 
  }
  
  delay(100);
  
}//End of void loop()
