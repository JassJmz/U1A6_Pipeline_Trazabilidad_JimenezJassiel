# Bitácora de Ingeniería — U1A4 y U1A5

---

## 2026-02-10 16:20

**Actividad:** Implementación inicial de telemetría ligera desde ESP32 hacia PC mediante USB Serial (U1A4).

**Decisión técnica:** Se definió una estructura de mensaje en formato CSV con los campos `t_ms,s1,s2` para simplificar el parseo en Node-RED y reducir sobrecarga frente a JSON.

**Resultado/Evidencia:** El monitor serial mostró transmisión continua de datos. Node-RED recibió correctamente los mensajes y los visualizó en el nodo debug.

**Siguiente acción:** Agregar registro automático a archivo CSV para evidenciar almacenamiento de muestras.

---

## 2026-02-11 17:05

**Actividad:** Implementación de registro de datos en archivo CSV desde Node-RED (U1A4).

**Decisión técnica:** Se utilizó el nodo `file` de Node-RED para guardar datos crudos en formato CSV asegurando trazabilidad de al menos 300 muestras.

**Resultado/Evidencia:** Se generó archivo con más de 300 filas en `data/raw/`. Se verificó que el orden temporal se mantiene mediante `t_ms`.

**Siguiente acción:** Validar estabilidad de transmisión y revisar latencia promedio.

---

## 2026-02-12 18:10

**Actividad:** Validación de estabilidad y estructura del mensaje de telemetría.

**Decisión técnica:** Se mantuvo baudrate en 115200 para asegurar transmisión estable sin pérdida de paquetes. Se verificó consistencia en separación por comas.

**Resultado/Evidencia:** No se detectaron pérdidas visibles en 300+ muestras. Dashboard actualiza sin retrasos perceptibles.

**Siguiente acción:** Integrar visualización gráfica en dashboard (U1A5).

---

## 2026-02-14 16:40

**Actividad:** Desarrollo de dashboard en Node-RED para visualización en tiempo casi real (U1A5).

**Decisión técnica:** Se utilizó `ui_chart` para graficar lecturas analógicas y `function` para normalizar datos si es necesario antes de mostrar.

**Resultado/Evidencia:** El dashboard mostró gráficas dinámicas actualizando cada ~0.5 s con lecturas en tiempo casi real.

**Siguiente acción:** Implementar proceso de calibración (min/max) para sensores.

---

## 2026-02-15 17:30

**Actividad:** Implementación de calibración de sensores (definición de min/max y umbral).

**Decisión técnica:** Se capturaron valores mínimos y máximos manualmente para cada canal y se calculó un umbral intermedio para distinguir condiciones blanco/negro.

**Resultado/Evidencia:** Se visualizaron valores min/max/umbral en el dashboard y se comprobó respuesta correcta al cambiar superficie bajo el sensor.

**Siguiente acción:** Guardar parámetros de calibración en archivo estructurado (`calibration_params.json`).

---

## 2026-02-16 18:00

**Actividad:** Validación extremo a extremo del pipeline CPS (sensor → ESP32 → Serial → Node-RED → Dashboard → CSV).

**Decisión técnica:** Se mantuvo estructura CSV por simplicidad y trazabilidad. Se confirmó almacenamiento de datos crudos y parámetros procesados en carpetas separadas (raw/processed).

**Resultado/Evidencia:** Se confirmó funcionamiento completo del sistema con:
- Recepción estable de datos
- Dashboard en ejecución
- CSV ≥300 muestras
- Parámetros de calibración definidos

**Siguiente acción:** Documentar metadatos del pipeline y checklist de reproducibilidad para entrega final (U1A6).