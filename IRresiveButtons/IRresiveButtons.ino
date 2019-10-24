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

int RECV_PIN = 2;

IRrecv irrecv(RECV_PIN);

decode_results results;

void setup()
{
  Serial.begin(9600);
  // In case the interrupt driver crashes on setup, give a clue
  // to the user what's going on.
  Serial.println("Enabling IRin");
  irrecv.enableIRIn(); // Start the receiver
  Serial.println("Enabled IRin");
}

void loop() {
  if(irrecv.decode(&results)) 
  {
    long x = results.value;
    //Serial.println(results.value, HEX);
    Serial.println(x, HEX);
    irrecv.resume(); // Receive the next value
  }
  delay(100);
}
