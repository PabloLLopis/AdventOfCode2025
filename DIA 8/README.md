# Día 8 — Elección y Resolución del Problema

## Elección del problema

El problema seleccionado del **Advent of Code** nos permite trabajar con la **agrupación de puntos en el espacio tridimensional**, aplicando conceptos fundamentales de **estructuras de datos, colas de prioridad y algoritmos de unión de conjuntos**.  

El objetivo principal es agrupar puntos en función de la distancia entre ellos y, una vez formados los conjuntos, **calcular el producto de los tamaños de los tres grupos más grandes**.

Este ejercicio resulta especialmente adecuado para reforzar el razonamiento algorítmico y el uso eficiente de estructuras de datos clásicas.

---

## Estructuras de datos utilizadas

Para la resolución del problema se han utilizado las siguientes estructuras:

- `vector` para almacenar dinámicamente las coordenadas de los puntos en 3D.
- `struct` para representar cada punto mediante sus coordenadas `(x, y, z)`.
- **Cola de prioridad (min-heap)** para procesar las distancias entre puntos en orden creciente.
- **Disjoint Set Union (DSU / Union-Find)** para gestionar la unión de conjuntos y el tamaño de cada componente.
- `tuple` para representar cada conexión entre dos puntos junto con su distancia asociada.

Estas estructuras permiten una gestión eficiente tanto del cálculo de distancias como de la agrupación de los puntos.

---

## Cómo se ha abordado el problema

El desarrollo del problema se ha realizado siguiendo los siguientes pasos:

1. **Lectura de datos** desde un fichero de entrada que contiene las coordenadas de los puntos en formato `(x, y, z)`.
2. Almacenamiento de todos los puntos en una estructura dinámica.
3. Cálculo de la **distancia euclidiana al cuadrado** entre cada par de puntos.
4. Inserción de cada par de puntos y su distancia en una **cola de prioridad mínima**, asegurando que se procesen primero las conexiones más cortas.
5. Inicialización de una estructura **DSU** con tantos conjuntos como puntos.
6. Procesamiento de las conexiones:
   - si dos puntos pertenecen a conjuntos distintos, se unen,
   - se emplea compresión de caminos y unión por tamaño para mejorar la eficiencia.
7. Obtención de los tamaños de todos los conjuntos finales.
8. Ordenación de los tamaños en orden descendente y **cálculo del producto de los tres mayores**.

Este enfoque permite gestionar de forma eficiente la conectividad entre puntos y obtener el resultado final de manera clara y estructurada.

---

## Alternativas consideradas

Existen otras posibles aproximaciones al problema, entre ellas:

- Ordenar todas las distancias previamente en un vector en lugar de utilizar una cola de prioridad.
- Aplicar un algoritmo de agrupación basado en umbrales fijos de distancia.
- Representar explícitamente el problema como un grafo completo y aplicar variaciones de algoritmos clásicos.

No obstante, estas alternativas presentan mayor coste computacional o menor claridad conceptual para los objetivos de la práctica.

---

## Valoración personal

La solución implementada nos parece adecuada y bien alineada con la teoría vista en clase.  
Además, el uso combinado de estas técnicas facilita la comprensión de cómo resolver problemas de agrupación y conectividad de forma eficiente, reforzando el aprendizaje de diseño algorítmico.

---

## Resultado obtenido

- **Parte 1:** `96672`

---
