# Checklist de reproducibilidad (U1A6)

## Paso 1 — Preparar hardware
- Conectar el/los sensor(es) analógicos a los pines ADC usados por el firmware (A4 o A5).
- Conectar el ESP32 por USB a la PC.

## Paso 2 — Cargar firmware (PlatformIO)
- Abrir VS Code + PlatformIO.
- Compilar y cargar:
  - U1A4: `code/U1A4_telemetria_main.cpp` (si se usa A4)
  - U1A5: `code/U1A5_calibracion_main.cpp` (si se usa A5)
- Configurar `monitor_speed = 115200`.

## Paso 3 — Iniciar Node-RED e importar flow
- Abrir Node-RED.
- Importar el flow:
  - `code/node_red_U1A4_flow.json` o
  - `code/node_red_U1A5_dashboard_flow.json`
- Configurar el nodo `serial in` con el puerto correcto y 115200 baudios.

## Paso 4 — Verificación de ejecución
- En el monitor serial deben verse líneas CSV:
  - A4: `seq,s`
  - A5: `t_ms,s1,s2`
- En Node-RED:
  - Debug muestra objetos/valores parseados.
  - El dashboard muestra gráficas actualizando (A5).

## Paso 5 — Registro y evidencias
- Confirmar generación/uso de `data/raw/U1A6_sample.csv` con ≥300 filas.
- Confirmar `data/processed/calibration_params.json` (A5).

## Verificación rápida
1. Cambiar condición del sensor (blanco/negro o variación) y observar cambio en `s1/s2`.
2. Confirmar que el dashboard actualiza en tiempo casi real.
3. Revisar que el CSV tenga ≥300 muestras y orden temporal (`t_ms` creciente o `seq` incremental).