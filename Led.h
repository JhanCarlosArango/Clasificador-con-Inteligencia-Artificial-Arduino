#ifndef Led_h
#define Led_h
class Led {
private:

  int ledrojo = 31;
  int ledrojo1 = 35;
  int ledverde1 = 33;

public:

  void setup_leds() {
    //led rojos
    pinMode(ledrojo, OUTPUT);
    digitalWrite(ledrojo, LOW);

    pinMode(ledrojo1, OUTPUT);
    digitalWrite(ledrojo1, LOW);

    pinMode(ledverde1, OUTPUT);
    digitalWrite(ledverde1, LOW);
  }


  void led_rojo(bool Estado) {

    digitalWrite(ledrojo, Estado);
    delay(100);
  }

  void led_verde(bool Estado) {
    digitalWrite(ledverde1, Estado);
    delay(100);
  }
  void led_rojo1(bool Estado) {
    digitalWrite(ledrojo1, Estado);
    delay(100);
  }
};
#endif