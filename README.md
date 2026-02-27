# U1A6 — Pipeline y trazabilidad (ESP32 → Serial → Node-RED → Dashboard/CSV)

## Descripción
Repositorio de trazabilidad del pipeline CPS implementado en las actividades U1A4 (telemetría ligera) y U1A5 (dashboard + calibración).  
El sistema adquiere lecturas analógicas desde ESP32, las transmite a una PC por USB Serial, Node-RED las procesa para visualización casi en tiempo real y registra datos en CSV. Para U1A5 se calculan parámetros de calibración (min/max/umbral).

## Estructura del repositorio
- `code/`: firmware ESP32 (A4/A5) + flows de Node-RED (export JSON).
- `data/raw/`: CSV crudo con ≥300 muestras (`U1A6_sample.csv`).
- `data/processed/`: parámetros de calibración (`calibration_params.json`).
- `docs/`: capturas del monitor serial, dashboard y calibración.
- `bitacora.md`: bitácora de ingeniería (≥6 entradas).
- `metadata_pipeline.md`: metadatos técnicos del pipeline.
- `repro_checklist.md`: pasos para reproducir el sistema.
- `CHANGELOG.md`: versiones v0.1 y v0.2.

## Versiones
- **v0.1**: Telemetría ligera (U1A4) estable + recepción Node-RED + log CSV.
- **v0.2**: Dashboard y calibración (U1A5) + parámetros de calibración.

## Evidencias
Capturas en `docs/` y muestras en `data/raw/`.