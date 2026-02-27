#include <Arduino.h>
// A4: Telemetría ligera con media móvil
// ---------------- CONFIGURACIÓN ----------------
const int SENSOR_PIN = 34;   // Pin ADC del ESP32
const int N = 5;             // Media móvil (N = 5)

// Buffer circular
int buffer[N];
int idx = 0;
long sum = 0;

// Contador de secuencia (telemetría A4)
unsigned long seq = 0;
// ------------------------------------------------

void setup() {
  Serial.begin(115200);
  delay(1000);

  // Inicializar buffer
  for (int i = 0; i < N; i++) {
    buffer[i] = 0;
  }

  Serial.println("TX -> enviando datos");
}

void loop() {

  // ----------- LECTURA ADC -----------
  int raw = analogRead(SENSOR_PIN);

  // ----------- MEDIA MÓVIL -----------
  sum -= buffer[idx];
  buffer[idx] = raw;
  sum += buffer[idx];
  idx = (idx + 1) % N;
  int filt = sum / N;

  // ----------- TELEMETRÍA LIGERA (A4) -----------
  // Formato: seq,s
  
  
  Serial.print(seq);
  Serial.print(",");
  Serial.println(filt);
  seq++;

  // ----------- FRECUENCIA DE MUESTREO -----------
  delay(50); // 20 Hz
}


