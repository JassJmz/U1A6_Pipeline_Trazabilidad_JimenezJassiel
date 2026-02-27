# CHANGELOG

## v0.1 — U1A4 Telemetría ligera
- Firmware ESP32 con lectura ADC y filtrado por media móvil.
- Envío por USB Serial en formato CSV (secuencia + lectura filtrada).
- Flow Node-RED para recepción y registro en CSV.
- Evidencia de recepción y almacenamiento de muestras.

## v0.2 — U1A5 Dashboard + calibración
- Firmware ESP32 con telemetría `t_ms,s1,s2` a 10 Hz.
- Dashboard Node-RED con gráficas en tiempo casi real.
- Proceso de calibración: captura min/max y cálculo de umbral.
- Exportación/registro de parámetros en `calibration_params.json`.