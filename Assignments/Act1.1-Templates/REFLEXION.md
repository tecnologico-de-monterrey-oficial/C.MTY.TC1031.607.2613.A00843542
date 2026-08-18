1. ¿Qué ventaja concreta notaste al usar templates en tu clase Lista, comparado con haberla hecho solo para un tipo de dato?

La ventaja que noté es que no tuve que hacer una clase diferente para cada tipo de dato.
 Con el template pude usar exactamente la misma clase para crear una lista de enteros con List<int> y después una 
 de strings con List<string>. Por ejemplo, en mi main probé los mismos métodos con números como 15, 10 y 12, y después
  con palabras como "Laptop", "Bottle" y "Phone", sin tener que cambiar la clase.

  2. ¿Qué parte de la actividad te costó más trabajo entender o depurar? ¿Qué hiciste para resolverlo?

Lo que más me costó entender fue insertAt y removeAt, especialmente cómo recorrer los elementos sin perder los
 valores que ya estaban guardados. En insertAt entendí que primero tenía que hacer espacio y recorrer los elementos
  hacia la derecha antes de colocar el nuevo valor. En removeAt fue al revés: tuve que recorrer los elementos hacia la izquierda 
  y después eliminar el último. Para resolverlo fui siguiendo ejemplos con listas pequeñas y viendo qué pasaba en cada posición hasta 
  entender cómo funcionaban los ciclos.

  3. Si tuvieras que explicarle a un compañero qué es un template en C++ usando tus propias palabras, sin tecnicismos, ¿qué le dirías?

Yo diría que un template sirve para hacer un código que pueda trabajar con diferentes tipos de datos sin tener que volver a escribirlo. 
Es como dejar un espacio para decidir después qué tipo de dato quieres usar. Por ejemplo, en esta actividad hice una sola clase List, pero
 pude usarla tanto para números como para strings solamente cambiando lo que pongo entre < >.