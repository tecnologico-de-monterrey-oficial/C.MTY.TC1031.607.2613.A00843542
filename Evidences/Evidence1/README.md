# Evidencia 1 - Actividad Integradora

Este programa trabaja con registros de logs y permite ordenarlos por fecha y hora utilizando diferentes algoritmos de ordenamiento. Después permite realizar búsquedas por rango de fechas utilizando búsqueda binaria.

## Archivos

- `data/log607-1.txt`: archivo con registros desordenados.
- `data/log607-2.txt`: archivo con registros casi ordenados.
- `Log.h`: estructura para guardar los registros.
- `Sorts.h`: contiene los algoritmos de ordenamiento.
- `Search.h`: contiene la búsqueda binaria por rango.
- `main.cpp`: programa principal.
- `output607.txt`: guarda los registros ordenados.
- `range607.txt`: guarda los registros encontrados en el rango.
- `docs/`: contiene las evidencias de pruebas y la reflexión.

## Compilar y ejecutar

Desde la carpeta Evidence1:

```bash
g++ -std=c++20 main.cpp -o main
./main
```

## Formato de fecha

Para realizar una búsqueda se utiliza el siguiente formato:

Mes Dia Anio HH:MM:SS

Ejemplo:

Sep 08 2024 00:00:00

## Algoritmos disponibles

1. Swap Sort
2. Bubble Sort
3. Selection Sort
4. Insertion Sort
5. Merge Sort
6. Quick Sort
7. Shell Sort

## Uso de inteligencia artificial

Utilicé inteligencia artificial como apoyo para resolver dudas específicas y revisar partes de mi código. Las sugerencias utilizadas fueron revisadas y probadas antes de agregarlas al programa. En `docs/ReflexEvidencia1.pdf` explico con más detalle cómo utilicé IA durante la actividad.

## Video

Liga al video de demostración: https://drive.google.com/file/d/1zXo-kdNFljNRMn_Ax03wASjbwPEIhONE/view?usp=sharing 