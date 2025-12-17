## ¿Por qué hemos elegido este problema?

El problema del Día 3 de **Advent of Code 2025** nos ha parecido interesante por su posibilidad de aplicar programacion dinamica en la segunda parte del problema. La tarea consiste en encontrar  dentro de cada banco de baterías, con el objetivo de maximizar el "voltaje" generado la mejor secuencia de 12 dígitos en la segunda parte por lo que si almacenamos en memoria el valor resulta mas sencillo la busqueda del mismo.

## Técnicas y estructuras de datos utilizadas

En este problema hemos empleado principalmente dos técnicas:

1. **Programación Dinámica (PD)**:
   - Utilizamos memorización dentro de la función de voltage    para almacenar los resultados de subsecuencias ya calculadas. Este enfoque permite **evitar recalcular las mismas subsecuencias de dígitos** varias veces, lo que mejora la eficiencia del algoritmo.
   - **¿Por qué?**: La naturaleza del problema implicaba recalcular muchas veces el mismo resultado para las subsecuencias de dígitos. Al almacenar los resultados de las subsecuencias que ya hemos procesado, evitamos redundancias y aceleramos la ejecución.

2. **Estructura de Datos**:
   - Usamos un **`unordered_map`** para almacenar los resultados de las subsecuencias, con la **clave como una cadena** que representa los dígitos seleccionados y el **valor como el resultado de voltaje** calculado para esa subsecuencia.
   - **¿Por qué?**: El uso de un `unordered_map` permite un acceso rápido (en promedio O(1)) para verificar si una subsecuencia ya ha sido procesada y almacenar el resultado.

## Resolución del problema

### Parte 1:
La primera parte del problema nos pedía **encontrar los dos dígitos más grandes** en cada banco de baterías y calcular el voltaje de cada banco. Para hacerlo, hemos utilizado un enfoque **greedy**, seleccionando en cada iteración el dígito más grande disponible.

### Parte 2:
La segunda parte amplía la tarea al requerir **exactamente 12 dígitos** para cada banco de baterías, con el objetivo de formar el número más grande posible. Aquí fue donde aplicamos la **programación dinámica**, utilizando **memorización** para evitar recalcular los valores de subsecuencias de 12 dígitos que ya habíamos procesado. Esta mejora fue crucial, ya que evitó cálculos redundantes y optimizó el rendimiento.

### Dificultades encontradas:
Una de las dificultades principales fue gestionar correctamente las **subsecuencias de 12 dígitos** sin tener que probar todas las combinaciones posibles, lo que sería ineficiente. Para resolverlo, implementamos un enfoque **greedy** para seleccionar los dígitos más grandes en cada paso y los almacenamos en una tabla para reutilizarlos cuando fuera necesario.

Otra dificultad fue asegurarnos de que la **memorización** no sobrecargara la memoria, lo que podría ocurrir si guardábamos demasiados resultados intermedios. Utilizamos un **unordered_map** de manera eficiente para solo almacenar las subsecuencias relevantes y evitar el almacenamiento innecesario.

### Alternativas descartadas:
- Inicialmente, se consideró utilizar una **búsqueda exhaustiva** para encontrar todas las combinaciones posibles de 12 dígitos. Sin embargo, esto resultaba ineficiente (O(n^12) combinaciones), lo que llevó a desestimar esta opción a favor de un enfoque **greedy** combinado con **programación dinámica**.
- Otra alternativa fue el uso de **recursión pura** sin memorización. Esta opción también fue descartada porque se encontraba con el problema de recalcular los mismos subproblemas, lo que hubiera incrementado enormemente el tiempo de ejecución.

### Valoración personal:
Este ejercicio ha sido todo un reto para nosotros ya que a pesar que nos ha permitido aplicar conceptos de **programación dinámica** nos costo encontrar la manera de aplicarlo. Ya que en la primera parte

## Resultados obtenidos:

- **Solución de la Parte 1**: `17311`
- **Solución de la Parte 2**: `171419245422055`

**¡Con la obtención de ambas estrellas doradas!**
