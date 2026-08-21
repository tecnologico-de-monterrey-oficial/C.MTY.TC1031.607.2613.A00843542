1. ¿En qué casos notaste que la versión recursiva fue más lenta o usó más memoria que la iterativa? ¿A qué se debió?
Lo noté más en Fibonacci, porque la función recursiva se llama a sí misma muchas veces y hasta llega a repetir cálculos que ya había hecho. Por eso termina haciendo más trabajo que la iterativa y también ocupa más memoria por todas las llamadas que va haciendo.

2. Para la suma 1..n, sumFormula resuelve en un solo paso lo que a sumIterative y sumRecursive les toma n pasos. ¿Qué te dice esto sobre buscar una fórmula antes de escribir código?
Me hizo ver que antes de empezar a hacer ciclos o funciones más complicadas, vale la pena revisar si existe una fórmula que haga lo mismo de una forma más fácil. En este caso la fórmula llega al resultado directamente, mientras que las otras tienen que ir sumando número por número.

3. Si bacteriasRecursive tuviera que calcular n = 100,000 días, ¿qué problema esperarías encontrar y cómo lo resolverías?
Creo que podría llegar a dar un error porque tendría que llamarse a sí misma demasiadas veces y estaría usando mucha memoria. Para un número tan grande de días sería mejor usar la función iterativa con un for, porque hace el cálculo sin tener que guardar todas esas llamadas.