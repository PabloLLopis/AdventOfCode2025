#  Día 5 — Elección y Resolución del Problema 

##  ¿Por qué hemos elegido este problema?

El problema seleccionado resulta especialmente adecuado para trabajar con **estructuras de datos basadas en árboles**, un contenido fundamental abordado en la parte teórica de la asignatura.  

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

---

##  Alternativas consideradas

Existen otras posibles aproximaciones al problema, entre ellas:

- **Búsqueda secuencial**, comprobando manualmente los solapamientos entre intervalos.
- **Uso de un vector**, ordenando previamente los intervalos y realizando una fusión posterior.

---

##  Valoración personal

Este ejercicio con **árbol binario** nos ha resultado interesante, ya que tras diversas charlas sobre cómo plantearlo fuimos afinando la idea hasta dar con una solución clara, haciendo que el desarrollo fuera más dinámico y satisfactorio.


---

## Compilación

Para compilar el programa necesitamos:
g++ part1_day5.cpp -o part1_day5.cpp
./part1_day5
(necesita el input.txt)
(para la parte 2 cambiar el numero 1 por el 2)
