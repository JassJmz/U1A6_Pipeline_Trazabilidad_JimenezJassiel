#include <Arduino.h>
//A5 - Calibración y verificación de sensores
static const int PIN_S1 = 4;   // GPIO1  (ADC)
static const int PIN_S2 = 5;   // GPIO2  (ADC)

static const uint32_t PERIOD_MS = 100;  // 10 Hz (cumple >=2 Hz)
uint32_t last_ms = 0;

void setup() {
  Serial.begin(115200);
  delay(200);

  // Opcional: ayuda a estabilidad en algunos casos
  analogReadResolution(12); // 0..4095

  Serial.println("t_ms,s1,s2"); // header opcional (si no lo quieres, quítalo)
}

void loop() {
  uint32_t now = millis();
  if (now - last_ms >= PERIOD_MS) {
    last_ms = now;

    int s1 = analogRead(PIN_S1);
    int s2 = analogRead(PIN_S2);

    // CSV compacto obligatorio: t_ms,s1,s2
    Serial.print(now);
    Serial.print(",");
    Serial.print(s1);
    Serial.print(",");
    Serial.println(s2);
  }
}