# Día 8 — Elección y Resolución del Problema

##  ¿Por qué hemos elegido este problema?

El problema seleccionado  nos permite trabajar con la agrupación de puntos en el espacio tridimensional, aplicando conceptos fundamentales de **estructuras de datos, colas de prioridad y algoritmos de unión de conjuntos**.  
El objetivo principal es agrupar puntos en función de la distancia entre ellos y, una vez formados los conjuntos, calcular el producto de los tamaños de los tres grupos más grandes.


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

---

## Alternativas consideradas

Hemos visto otras formas de hacer al problema, entre ellas:

- Ordenar todas las distancias previamente en un vector en lugar de utilizar una cola de prioridad.
- Representar explícitamente el problema como un grafo completo y aplicar variaciones de algoritmos clásicos.

---

## Valoración personal

Este ejercicio con **DSU en grafos** nos ha gustado mucho porque ha sido muy dinámico de hacer en grupo. Entre probar cosas, comentar resultados y ajustar detalles, el tiempo se nos pasó rápido y el ejercicio se hizo bastante ameno.



---

## Compilación

---
