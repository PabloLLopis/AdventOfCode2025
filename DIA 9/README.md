#  Día 9 — Elección y Resolución del Problema 

##  Elección del problema

El problema seleccionado del **Advent of Code** nos permite trabajar con el análisis de combinaciones de coordenadas dentro de una rejilla, aplicando conceptos fundamentales de **estructuras de datos, ordenación y análisis de complejidad**.  
El objetivo es calcular el **área máxima de un rectángulo** definido por dos baldosas rojas, utilizando sus coordenadas como esquinas opuestas.

Este ejercicio resulta especialmente adecuado para reforzar el razonamiento algorítmico y la optimización progresiva de soluciones.

---

##  Estructuras de datos utilizadas

Para la resolución del problema se han utilizado las siguientes estructuras:

- `vector` para almacenar dinámicamente las baldosas rojas.
- `struct` para representar coordenadas y baldosas de forma clara y tipada.
- **Tabla hash implementada manualmente** mediante un vector de listas, con el objetivo de:
  - evitar duplicados,
  - permitir comprobaciones de presencia en tiempo constante promedio.
- Estructuras auxiliares para representar **rangos prohibidos** dentro de la rejilla.

Además, se ha implementado un **algoritmo de ordenación propio (quicksort iterativo)**, evitando el uso de librerías estándar como `<algorithm>`.

---

##  Cómo se ha abordado el problema

El desarrollo se ha realizado en dos niveles de complejidad:

1. **Lectura de datos** desde un fichero de entrada con coordenadas `(x, y)`.
2. Almacenamiento de las baldosas rojas en una estructura dinámica.
3. Eliminación de duplicados mediante una tabla hash propia.
4. Ordenación de las baldosas para detectar huecos entre coordenadas consecutivas.
5. Identificación de **rangos prohibidos** que invalidan ciertos rectángulos.
6. Evaluación de todos los pares posibles de baldosas:
   - comprobando previamente si el rectángulo es válido,
   - calculando el área solo cuando cumple las restricciones.
7. Obtención del área máxima entre todas las combinaciones válidas.

Este enfoque permite mantener la corrección del resultado al mismo tiempo que se reduce el número de cálculos innecesarios.

---

##  Alternativas consideradas

Existen otras posibles soluciones al problema, entre ellas:

- Un enfoque completamente **bruto**, probando todos los pares sin validación previa.
- Uso de estructuras más avanzadas como árboles de intervalos.
- Representación de la rejilla completa mediante matrices.

Sin embargo, estas alternativas presentan mayor coste computacional o menor interés académico para los objetivos de la práctica.

---

##  Valoración personal

La solución implementada nos parece adecuada y bien alineada con la teoría vista en clase.  
Permite aplicar de forma práctica conceptos como:

- estructuras dinámicas,
- ordenación personalizada,
- tablas hash,
- análisis de complejidad,
- filtrado de casos inválidos.

Además, el paso de una solución simple a otra más elaborada facilita la comprensión de cómo **mejorar progresivamente un algoritmo**, reforzando el aprendizaje de diseño y optimización de soluciones.

---


