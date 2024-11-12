#include "HardwareSerial.h"
#include "Servo_motor.h"
#include "Led.h"

Servo_motor ser;

Led ledes;
class Perceptron {

private:
  float zuma = 0;
  int activacion;
  int x1[40];
  int x2[40];
  int x3[40];
  int resultado_esperado[40];
  int Dimension_array = 40;
  int activar_led = 10;

  float w1;
  float w2;
  float w3;
  float theta;

public:

  void llenar(double R, double G, double B, int valor_esperado, int i) {

    x1[i] = R;
    x2[i] = G;
    x3[i] = B;
    resultado_esperado[i] = valor_esperado;
  }


  void Perceptron_Entrenado(float wf1, float wf2, float wf3, float Biasf, float Rojo, float Green, float Blue) {  //se llama este método cuando se entrene el perceptron


    zuma = ((Rojo * wf1) + (Green * wf2) + (Blue * wf3)) - Biasf;

    if (zuma > 0) {

      ser.movimieto_a();  // movimiento del servo
      Serial.print(1);

    } else {

      ser.movimieto_b();  // movimiento del servo
      Serial.print(-1);
    }
  }

  void Entrenar_perceptron() {

    //ser.run();
    ledes.setup_leds();
    // int x1[] = { 274, 280, 289, 293, 279, 279, 290, 290, 277, 291, 291, 289, 289, 279, 274, 274, 280 };
    // int x2[] = { 400, 400, 409, 401, 402, 409, 405, 400, 407, 406, 403, 408, 408, 409, 404, 404, 401 }; // Datos de prueba
    // int x3[] = { 364, 340, 349, 353, 370, 369, 350, 340, 367, 341, 341, 358, 359, 359, 364, 344, 340 };
    // int resultado_esperado[] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };


    w1 = (float)random(-1000, 2000) / 1000;
    w2 = (float)random(-1000, 2000) / 1000;
    w3 = (float)random(-1000, 2000) / 1000;
    theta = (float)random(1000, 2000) / 1000;
    float factor_aprendizaje = 0.25;

    float Xo = -1;
    float error = 0;
    float ErrorPorEpoca;  // se va utilizar para el promedio de error
    float acue = 1;
    int epoca = 1;
    float suma = 0;
    float z = 0;

    Serial.println("DATOS INICIALES:");
    Serial.print("Peso 1 -->  ");
    Serial.println(w1);
    Serial.print("Peso 2 -->  ");
    Serial.println(w2);
    Serial.print("Peso 3 --> ");
    Serial.println(w3);
    Serial.print("Bias --> ");
    Serial.println(theta);

    while (acue != 0) {
      // Serial.print("Epoca: ");
      // Serial.println(epoca);
      int it = 0;
      // int n = sizeof(x1);
      // m = sizeof(x1);
      acue = 0;
      while (it < Dimension_array) {

        suma = ((x1[it] * w1) + (x2[it] * w2) + (x3[it] * w3)) - theta;

        //Funcion de activacion

        if (suma > 0) {
          z = 1;
        } else {
          z = -1;
        }

        if (epoca == activar_led) {
          ledes.led_verde(HIGH);
          activar_led = activar_led + 10;
        }
        if (z != resultado_esperado[it]) {

          error += resultado_esperado[it] - (z);
          acue += 1;
          theta = theta + (factor_aprendizaje * ((resultado_esperado[it] - z) * Xo));
          w1 = w1 + (factor_aprendizaje * ((resultado_esperado[it] - z) * x1[it]));
          w2 = w2 + (factor_aprendizaje * ((resultado_esperado[it] - z) * x2[it]));
          w3 = w3 + (factor_aprendizaje * ((resultado_esperado[it] - z) * x3[it]));
        }
        Serial.print("----- Epoca : ");
        Serial.print(epoca);
        Serial.println("-----");
        Serial.print("Peso 1 : ");
        Serial.println(w1);
        Serial.print("Peso 2 : ");
        Serial.println(w2);
        Serial.print("Peso 3 : ");
        Serial.println(w3);
        Serial.print("Bias : ");
        Serial.println(theta);
        it += 1;
        error = 0;
        epoca += 1;
        ledes.led_verde(LOW);
      }
    }


    // if (m > 500) {
    //   Serial.print("[!] Demasiadas epocas realizadas!\n");
    //   Serial.print("[!] Intente nuevamente con otros pesos sinapticos.\n");
    //   exit(0);
    // }

    /////////// MOSTRAR RESULTADOS FINALES
    Serial.println("FINALIZANDO ENTRENAMIENTO");
    Serial.println("--------------- DATOS FINALES --------------------------------");
    Serial.println("PERCEPTRON SIMPLE [ENTRENADO]");
    Serial.print("Peso Sinaptico 1 --> ");
    Serial.println(w1);

    Serial.print("Peso Sinaptico 2 --> ");
    Serial.println(w2);

    Serial.print("Peso Sinaptico 3 --> ");
    Serial.println(w3);

    Serial.print("Bias --> ");
    Serial.println(theta);

    for (int i = 0; i < Dimension_array; i++) {
      Serial.print(" Entradas: [");
      Serial.print(x1[i]);
      Serial.print(" - ");
      Serial.print(x2[i]);
      Serial.print(" - ");
      Serial.print(x3[i]);
      Serial.print("]");
      Serial.print(" Salida: [");
      Serial.print(resultado_esperado[i]);
      Serial.println("]");
    }
    Serial.print("sumatoria = ");
    Serial.print(suma);
    Serial.println("");
  }

  float GetpW1() {
    return w1;
  }
  float GetpW2() {
    return w2;
  }
  float GetpW3() {
    return w3;
  }
  float Getbias() {
    return theta;
  }
};