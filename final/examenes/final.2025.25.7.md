## Examen Final AOC/Orga II

**fecha**: `28-07-25` 


1 )  8 Cores con Cache L1 y L2 local, y L3 compartida. Línea en estado “M” en L1. Configuración `SMP`.
- a. ¿Qué implica este estado en términos de ownership y de coherencia?
- b. Snoop bus. ¿Qué líneas específicas del bus del sistema conecta al Controlador Cache?
- c. Detecta un Read Miss a una variable contenida de esa línea con estado “M”.
  - i. ¿Qué handshake activa?
  - ii. Estado del bus del core que cursaba el Read Miss como respuesta a dicho handshake.
  - iii. Acción que realiza el Controlador Cache que tiene la línea “M” de acuerdo con el protocolo `MESI`
  - iv. Estado en el que coloca la línea antes de finalizar
  - v. ¿Cuál de los cores proceden con el acceso al bus posteriormente?
- d. Limitaciones de `MESI` en este escenario multicore
- e. ¿Qué aporta `MESIF` para resolver dichas limitaciones?
- f. ¿Qué aporta `MOESI` para resolver dichas limitaciones?

2 ) Core con ejecución Fuera de Orden.
- a. Bloques que agrega Tomasulo para su implementación:
   - i. Estructura interna de cada uno
   - ii. Cantidad de entradas de cada uno
   - iii. ¿Cómo se implementa en el hardware el link productor consumidor de un dato?
   - iv. ¿Cómo se resuelve el riesgo `WAW`? Considerar el siguiente código y explique cómo quedan las entradas de cada bloque del modelo de Tomasulo respecto de R1, si la instrucción sub se ejecuta antes de completado el ld. ¿Cómo Tomasulo logró que funcione?

```
ld   R1, [R7]     ; Cache miss y page fault. Tardará muchos ciclos de clock  

add  R3, R1, R2  

and  R8, #F0  

orr  R11, #1  

sub  R1, #3000

```
