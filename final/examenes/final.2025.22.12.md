## Examen Final AOC/Orga II

**fecha**: `22-12-25` 

A1. Indicar si la siguiente afirmación es verdadera o falsa: `"En forwarding los catos almacenados en el RF son eviados directamnete a la UF o ALU para acelerar las operaciones en le mismo ciclo de reloj"`. Justifique su respuesta explicando detalladamente el funcionamiento de la técnica de Forwarding en un pipeline. 

A2. ¿Cómo se resuelve el riesgo WAW en un procesador fuera de orden?. Considerar el siguiente código.

```
		ldr R1, [R4] ;Cache miss. Asumir latency de 25 ciclos de clock.
		add R8, R10, R12
		ldr R6, [R7+0x0]
		sub R1, R9, R10
```
Explique cómo quedan las entradas de cada bloque del modelo de Tomasulo respecto de `R1`, si  la instrucción `sub` se ejecuta antes de completado el `ld`. ¿Cómo logró Tomasulo que funcione?

A4. Explicar el concepto de excepciones imprecisas. Indique un ejemplo de código en el que queden expuestos los efectos. Explicar cómo se resuelve.

A5. Indicar cuál de las siguientes afirmaciones es la correcta, en referencia al Tag de un registro en la `RAT`, cuando para ese registro, además de  `V=0`:

	a. Corresponde a un valor arbitrario establecido en la decodificación de la instrucción.
	b. Es establecido en base a las dependencias de la instruccion.
	c. Es el índice dentro de la RS de la instrucción que utiliza al registro en cuestión como operando origen.
	d. Ninguna de las anteriores

Justificar su respuesta.

 
B1. Las memorias DRAM requieren un circuito de refresco. Explicar las razones de esta afirmación y explicar cómo funciona un amplificador de detección. <br> 

B2. ¿Por qué no es posible hacer que todas las memorias cache de un procesador sean full asociativas? Justificar. 

B3. Una estrategia utilizada en la estructura de caches se denomina "Split Cache". Explicar qué significa y qué ventajas tiene sobre una cache unificada. ¿Qué relación tienen estas ideas sobre una organización Harvard vs. Von Neumann? 

B4. La señal Read for Ownership es generada en un sistema cache SMP. Explicar qué la genera, en qué contexto, y dar un ejemplo de un caso práctico donde se utilice esta señal. 

B5. En una cache que usa protocolo `MESI` se hace una escritura. Indicar el estado en el que queda la linea, partiendo desde cada uno de los estados de MESI. Justificar cada transición. 

