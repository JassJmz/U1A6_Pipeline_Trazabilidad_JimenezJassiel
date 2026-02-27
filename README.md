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

## Ejecución rápida (reproducibilidad)

### Requisitos
- ESP32 conectado por USB a la PC
- VS Code + PlatformIO
- Node-RED (con Node-RED Dashboard)
- Baudrate serial: **115200**

### 1) Cargar firmware al ESP32
- Abrir el proyecto en VS Code (PlatformIO).
- Compilar y cargar el firmware:
  - **U1A4 (telemetría):** `code/U1A4_telemetria_main.cpp`
  - **U1A5 (dashboard/calibración):** `code/U1A5_calibracion_main.cpp`
- Abrir monitor serial a **115200**.

### 2) Ejecutar Node-RED
- Abrir Node-RED en el navegador.
- Importar el flow correspondiente:
  - **U1A4:** `code/node_red_U1A4_flow.json`
  - **U1A5:** `code/node_red_U1A5_dashboard_flow.json`
- Configurar el nodo **serial in** con el puerto correcto y **115200**.

### 3) Verificar funcionamiento
- En el monitor serial deben aparecer líneas CSV:
  - U1A4: `seq,s`
  - U1A5: `t_ms,s1,s2`
- En U1A5, el dashboard debe actualizar gráficas en tiempo casi real.
- Confirmar que existe `data/raw/U1A6_sample.csv` con **≥300 muestras**.
- Confirmar parámetros de calibración en `data/processed/calibration_params.json`.

### Evidencias
- Capturas en `docs/` (serial, dashboard y calibración).