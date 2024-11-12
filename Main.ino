#include "Sensor.h"
#include "Perceptron.h"
#include "Led.h"
#include "Servo_motor.h"

//instancias de las clases
Sensor sen;
Perceptron per;
Led leds;
Servo_motor serr;
int pulso = 37;  //pin 2
int i = 0;

int entre = 0;

void setup() {
  serr.run();
  leds.setup_leds();
  sen.Pin_Mode();
  pinMode(pulso, INPUT);
}
void loop() {

  Serial.println("Pulsa para Iniciar El entrenamiento");
  leds.led_rojo(HIGH);
  while (digitalRead(pulso) == LOW)
    ;
  while (i < 20) {

    leds.led_rojo(HIGH);

    Serial.print("Datos del Primer Color GUARDADO en la Posicion x[");
    Serial.print(i);
    Serial.println("]");
    per.llenar(sen.get_Rojo(), sen.get_Verde(), sen.get_Azul(), 1, i);
    i++;
    leds.led_rojo(LOW);
  }
  serr.movimieto_a();
  leds.led_rojo(LOW);
  Serial.println("Esperando Segundo Color...");
  leds.led_rojo1(HIGH);
  delay(10000);


  while (i >= 20 && i < 40) {
    leds.led_rojo1(HIGH);
    Serial.print("Datos del Segundo Color GUARDADO en la Posicion x[");
    Serial.print(i);
    Serial.println("]");
    per.llenar(sen.get_Rojo(), sen.get_Verde(), sen.get_Azul(), -1, i);
    i++;
    leds.led_rojo1(LOW);
  }
  serr.movimieto_b();
  while (entre < 1) {

    per.Entrenar_perceptron();  //Aqui entreno al Perceptron
    entre++;
  }

  Serial.print("Pulsa para Clasificar...");

  while (digitalRead(pulso) == LOW)
    leds.led_verde(LOW);
  ;

  while (true) {

    per.Perceptron_Entrenado(per.GetpW1(), per.GetpW2(), per.GetpW3(), per.Getbias(), sen.get_Rojo(), sen.get_Verde(), sen.get_Azul());
    delay(2000);
  }
}