#  Día 5 — Resolución del Problema mediante Grafos (Advent of Code)

##  Elección del problema

El problema seleccionado del **Advent of Code (AoC)** permite trabajar con **grafos y recorridos recursivos**, conceptos clave dentro del estudio de estructuras de datos y algoritmos.  
En particular, el ejercicio se centra en el **cálculo del número de caminos posibles entre dos nodos**, lo que lo convierte en un caso ideal para aplicar técnicas de **búsqueda en profundidad (DFS)**.

---

##  Estructura de datos utilizada

La solución se basa en un **grafo dirigido**, implementado mediante:

- `unordered_map<string, vector<string>>` para representar la **lista de adyacencia**
- `unordered_map<string, bool>` para el **control de nodos visitados**

Este enfoque permite una representación flexible y eficiente de las conexiones entre dispositivos, facilitando el recorrido del grafo.

---

##  Cómo se ha abordado el problema

El planteamiento seguido es el siguiente:

1. **Lectura del fichero `reactor.txt`**, donde cada línea define un dispositivo y sus conexiones.
2. Construcción del grafo mediante una **tabla hash** que asocia cada nodo con sus vecinos.
3. Implementación de una función **recursiva** (`contarCaminos`) que:
   - Parte del nodo `"you"`
   - Explora todos los caminos posibles hasta el nodo `"out"`
   - Evita ciclos mediante una estructura de nodos visitados
4. Uso de **backtracking**, marcando y desmarcando nodos para permitir la exploración de caminos alternativos.
5. Acumulación del número total de caminos válidos encontrados.

Este enfoque garantiza que se exploren **todas las combinaciones posibles sin repetir nodos en un mismo camino**.

---

##  Alternativas consideradas

Existen otras posibles aproximaciones al problema, entre ellas:

- Implementar el recorrido de forma **iterativa** usando una pila explícita.
- Utilizar **búsqueda en anchura (BFS)**, aunque resulta menos natural para el conteo exhaustivo de caminos.
- Representar el grafo mediante una **matriz de adyacencia**, lo cual sería menos eficiente en grafos dispersos.

No obstante, la solución basada en DFS recursivo resulta la más clara y alineada con los objetivos académicos del ejercicio.

---

##  Valoración personal

La solución basada en **grafos y recursividad** nos parece especialmente adecuada, ya que:

- Aplica de forma directa conceptos teóricos vistos en clase.
- Refuerza el uso de **estructuras dinámicas** como tablas hash y vectores.
- Permite comprender mejor el funcionamiento del **backtracking** y la gestión del estado en algoritmos recursivos.

En conclusión, esta implementación no solo resuelve correctamente el problema, sino que también constituye un excelente ejercicio práctico para afianzar el razonamiento algorítmico y el manejo de grafos en C++.

---



