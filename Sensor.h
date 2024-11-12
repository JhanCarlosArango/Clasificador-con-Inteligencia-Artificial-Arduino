#include "HardwareSerial.h"
class Sensor {

#define S0 4         // S0 a pin 4
#define S1 5         // S1 a pin 5
#define S2 6         // S2 a pin 6
#define S3 7         // S3 a pin 7
#define salidaTCS 8  // salidaTCS a pin 8

private:

  int rojo;
  int verde;
  int azul;

public:
  void Pin_Mode() {

    pinMode(S0, OUTPUT);        // pin 4 como salida
    pinMode(S1, OUTPUT);        // pin 5 como salida
    pinMode(S2, OUTPUT);        // pin 6 como salida
    pinMode(S3, OUTPUT);        // pin 7 como salida
    pinMode(salidaTCS, INPUT);  // pin 8 como salida

    digitalWrite(S0, HIGH);
    digitalWrite(S1, LOW);

    Serial.begin(9600);
  }

  double get_Rojo() {
    while (true) {
      digitalWrite(S2, LOW);
      digitalWrite(S3, LOW);
      rojo = pulseIn(salidaTCS, LOW);
      delay(200);

      return rojo;
    }
  }
  double get_Verde() {
    while (true) {
      digitalWrite(S2, HIGH);
      digitalWrite(S3, HIGH);
      verde = pulseIn(salidaTCS, LOW);
      delay(200);

      return verde;
    }
  }

  double get_Azul() {
    while (true) {
      digitalWrite(S2, LOW);
      digitalWrite(S3, HIGH);
      azul = pulseIn(salidaTCS, LOW);
      delay(200);

      return azul;
    }
  }


  void toString() {

    //Serial.print("Red:");
    Serial.print(rojo);

    Serial.print("\t");



    //Serial.print("Green:");
    Serial.print(verde);

    Serial.print("\t");


    //Serial.print("Blue:");
    Serial.println(azul);
  }
};