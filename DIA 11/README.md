## Día 11 — Elección y Resolución del Problema

### ¿Por qué hemos elegido este problema?

El problema del **Día 11 de Advent of Code 2025** nos ha parecido especialmente interesante por la posibilidad de trabajar con **grafos dirigidos**, combinados con **tablas hash** y **programación dinámica**.  
El objetivo consiste en analizar un conjunto de dispositivos conectados entre sí y determinar cuántos **caminos distintos** existen desde el dispositivo inicial (`you`) hasta el dispositivo final (`out`), siguiendo únicamente las conexiones dirigidas.

Este planteamiento resulta adecuado para modelar situaciones reales de flujo de información y permite aplicar varias estructuras de datos de forma conjunta.

---

### Técnicas y estructuras de datos utilizadas

En este ejercicio hemos empleado las siguientes técnicas:

#### Grafos dirigidos
- Cada dispositivo se modela como un **nodo**.
- Cada conexión entre dispositivos se representa como una **arista dirigida**.
- El grafo se almacena mediante una **lista de adyacencia**, lo que facilita recorrer los vecinos de cada nodo.

#### Tabla hash
- Se implementa una **tabla hash propia** para mapear los nombres de los dispositivos (`string`) a identificadores numéricos (`int`).
- Esto permite trabajar internamente con índices y mejorar la eficiencia del acceso a los nodos del grafo.
- Se utiliza encadenamiento y rehashing cuando se supera el factor de carga.

#### Programación Dinámica (memoización)
- Para contar los caminos se utiliza **programación dinámica**.
- Se almacenan los resultados parciales del número de caminos desde cada nodo hasta `out`.
- De esta forma se evita recalcular los mismos subproblemas varias veces.

---

### Resolución del problema

La resolución se centra en construir el grafo dirigido a partir del fichero de entrada, donde cada línea indica un dispositivo y sus salidas.  
Una vez construido el grafo, se realiza un conteo de caminos desde `you` hasta `out` utilizando una función recursiva con memoización.

Este enfoque permite recorrer todas las rutas posibles sin repetir cálculos innecesarios, manteniendo un tiempo de ejecución razonable incluso con grafos grandes.

---

### Dificultades encontradas

Una de las principales dificultades fue gestionar correctamente el conteo de caminos sin caer en cálculos repetidos.  
Una solución basada únicamente en DFS sin memoización resultaba muy ineficiente, ya que el mismo nodo podía visitarse muchas veces desde distintos caminos.

Otra dificultad ha sido el tratamiento de grafos grandes, lo que hizo necesario usar una tabla hash para convertir los nombres de los nodos en identificadores numéricos y simplificar el manejo interno del grafo.

---

### Alternativas 

- **Búsqueda exhaustiva sin memoización**: descartada por su alto coste computacional.
- **Uso exclusivo de strings sin hash**: hace el código más lento y complejo.

Finalmente, la combinación de grafo + tabla hash + programación dinámica resultó ser la opción más adecuada.

---

### Valoración personal

Este ejercicio nos ha resultado muy interesante ya que hemos tenido que implementar 3 diferentes estructuras en un mismo problema, esto mismo nos ha llevado a tener diferentes opiniones y posibilidades respecto al ejercicio. 
Tras ello, ver como se ha implementado todo y el resultado final, estamos muy satisfechos.

---

### Resultados obtenidos

- **Número total de caminos desde `you` hasta `out`**: **470**



