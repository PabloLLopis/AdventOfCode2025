#  Día 5 — Elección y Resolución del Problema (Advent of Code)

##  Elección del problema

El problema seleccionado del **Advent of Code (AoC)** resulta especialmente adecuado para trabajar con **estructuras de datos basadas en árboles**, un contenido fundamental abordado en la parte teórica de la asignatura.  
Su planteamiento permite aplicar conceptos abstractos a una solución concreta y funcional, reforzando el aprendizaje mediante la práctica.

---

##  Estructura de datos utilizada

La solución se ha implementado utilizando un **árbol binario de búsqueda (BST)** especializado en la gestión de **intervalos**.  
Esta estructura permite:

- Insertar intervalos de forma ordenada  
- Realizar búsquedas eficientes  
- Facilitar la fusión y gestión de rangos solapados  

El uso de un árbol dinámico aporta eficiencia y claridad al tratamiento de los datos.

---

##  Cómo se ha abordado el problema

El enfoque seguido ha sido el siguiente:

1. Modelar cada intervalo como un nodo del árbol.
2. Insertar los intervalos respetando la propiedad del árbol binario de búsqueda.
3. Gestionar los solapamientos durante la inserción o mediante recorridos controlados del árbol.
4. Obtener el resultado final a partir de un recorrido ordenado (in-order), garantizando la coherencia de los intervalos.

Este planteamiento permite una solución modular, escalable y alineada con los principios de las estructuras dinámicas.

---

##  Alternativas consideradas

Existen otras posibles aproximaciones al problema, entre ellas:

- **Búsqueda secuencial**, comprobando manualmente los solapamientos entre intervalos.
- **Uso de un vector**, ordenando previamente los intervalos y realizando una fusión posterior.

Si bien estas soluciones pueden ser válidas, presentan menor interés académico desde el punto de vista del uso de estructuras avanzadas y, en algunos casos, peor rendimiento.

---

##  Valoración personal

La solución basada en un **árbol binario de búsqueda** nos parece una respuesta adecuada y bien fundamentada.  
Permite aplicar de forma directa la teoría aprendida en clase a un caso práctico, mejorando la comprensión de:

- Estructuras dinámicas  
- Recursividad  
- Organización eficiente de datos  

En definitiva, consideramos que esta implementación no solo resuelve el problema planteado, sino que también refuerza de manera significativa el aprendizaje de los conceptos clave de la asignatura.

---

