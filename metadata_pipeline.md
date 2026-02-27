# Metadatos mínimos del pipeline

## Sensor / módulo y tipo de señal
- Señal: analógica por ADC (ESP32)
- Resolución típica ADC: 12 bits (0–4095)
- Canal(es): A4 usa 1 canal; A5 usa 2 canales (s1, s2)

## Frecuencia de muestreo (Hz)
- U1A4: 20 Hz (delay 50 ms)
- U1A5: 10 Hz (PERIOD_MS = 100 ms)

## Estructura del mensaje
- U1A4 (CSV): seq,s
- U1A5 (CSV): t_ms,s1,s2

## Canal de telemetría y estructura del mensaje
- Canal: USB Serial
- Baudrate: 115200

### Formato (U1A4)
- CSV: `seq,s`
- `seq`: contador de secuencia
- `s`: lectura filtrada por media móvil (N=5)

Ejemplo:
`12,1870`

### Formato (U1A5)
- CSV: `t_ms,s1,s2`
- `t_ms`: timestamp con `millis()`
- `s1,s2`: lecturas ADC

Ejemplo:
`24590,1780,1902`

## Plataforma
- Microcontrolador: ESP32 (Arduino framework)
- Desarrollo: VS Code + PlatformIO
- Dashboard/Telemetría PC: Node-RED + Node-RED Dashboard

## Dependencias (Node-RED)
- Nodos típicos usados:
  - `serial in`, `function`, `debug`, `file`
  - `ui_chart` (dashboard)