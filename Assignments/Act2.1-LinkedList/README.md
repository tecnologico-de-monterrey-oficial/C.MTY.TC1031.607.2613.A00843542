# Act2.1 - Linked List

## Uso de IA

Para esta actividad utilicé ChatGPT como apoyo para entender la implementación de algunas funciones de la Linked List y para revisar errores durante las pruebas.

### Prompts utilizados

- ¿Cómo puedo implementar las funciones de una Linked List utilizando templates y nodos?
- ¿Cómo puedo agregar, eliminar, buscar y actualizar elementos de una Linked List?
- ¿Cómo puedo sobrecargar los operadores [] y = para mi Linked List?
- Revisa mi código de LinkedList.h y dime qué tengo que corregir para que cumpla con la interfaz de la actividad.
- Ayúdame a crear un menú para probar las operaciones de mi Linked List.
- ¿Cómo puedo probar cada una de las funciones para verificar que funcionan correctamente?

## Reflexión

### ¿Qué parte del código te propuso la IA que aceptaste tal cual y por qué era correcta?

Una parte que acepté fue la forma de recorrer la lista utilizando un nodo auxiliar. Me hizo sentido porque era similar a lo que habíamos visto en clase y al probar las funciones pude comprobar que llegaba correctamente a los diferentes nodos de la lista.

### ¿Qué parte modificaste y cómo verificaste que tu cambio era mejor?

Modifiqué algunos nombres y funciones para que coincidieran con la interfaz de la actividad. Por ejemplo, cambié las funciones para agregar elementos por `addFirst` y `addLast`. También revisé el funcionamiento de `deleteAt` para que regresara un valor booleano como indicaban las instrucciones. Verifiqué los cambios compilando el programa y haciendo pruebas con cada opción del menú.

### ¿Dónde se equivocó la IA y cómo lo detectaste?

Al inicio, algunas funciones propuestas no coincidían completamente con la interfaz proporcionada. Por ejemplo, se utilizaron los nombres `push_front` y `push_back` en lugar de `addFirst` y `addLast`. Me di cuenta al volver a comparar el código con las especificaciones de la actividad. También tuve que revisar la forma en que debía funcionar `insert` para que correspondiera con lo solicitado.

### ¿Qué harías diferente si no tuvieras Copilot/ChatGPT?

Sin estas herramientas hubiera utilizado principalmente los ejemplos vistos en clase y las notas sobre nodos, templates y apuntadores. Probablemente habría desarrollado y probado cada función por separado antes de juntarlas en el programa completo. También utilizaría los errores del compilador para ir identificando qué partes tendría que corregir.