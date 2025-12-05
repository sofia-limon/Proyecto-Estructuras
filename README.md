# Proyecto Estructuras

Este repositorio contiene la implementación de varios algoritmos clásicos de **teoría de grafos** y **conteo combinatorio**, organizados por temas en carpetas independientes.

El proyecto está pensado como material de apoyo para la materia de **Estructuras de Datos / Estructuras Computacionales**, e incluye tanto el código fuente en C++ como casos de prueba de entrada/salida.

---

## Estructura del proyecto

Cada carpeta corresponde a un módulo temático:

1. `0 - Representación de grafos`  
   - Representaciones: lista de adyacencia, matriz de adyacencia, matriz de incidencia, etc.

2. `1 - Busqueda en grafos`  
   - Búsquedas: **BFS**, **DFS** y variantes de backtracking sobre grafos.

3. `2 - Componentes conexos`  
   - Componentes conexas en grafos no dirigidos (BFS/DFS).  
   - Componentes fuertemente conexas (SCC) con **Kosaraju**, etc.  
   - Uso de **DSU / Union-Find**.

4. `3 - Camino mas corto`  
   - Caminos mínimos con **Dijkstra**, **DP** y (según el caso) otros algoritmos de shortest path.

5. `4 - Determinar grafo como Arbol`  
   - Verificación de si un grafo es árbol (conectividad, ausencia de ciclos, etc.) usando varios métodos (M1, M2, M3).

6. `5 - Arbol de expansion`  
   - Árbol de expansión mínima (MST) con **Kruskal** y **Prim**.

7. `6 - Grafos Bipartitos`  
   - Verificación de bipartitismo (coloración 2-colores) y some backtracking cuando aplica.

8. `7 - Emparejamiento en grafos`  
   - Algoritmos de emparejamiento (matching) básico: búsquedas incrementales, greedy, backtracking, etc.

9. `8 - Emparejamiento maximo`  
   - Algoritmos clásicos de emparejamiento máximo: **Edmonds**, **Hopcroft–Karp / Karp**, **Kuhn**, **Micali–Vazirani**, etc.

10. `9 - Conteo (Extra)`  
    - Herramientas de conteo combinatorio: **permutaciones**, **combinaciones**, **conjunto potencia**, utilidades matemáticas.

En cada carpeta encontrarás:

- `src/`  
  Código fuente en C++:
  - `main.cpp` (programa principal del módulo).
  - Archivos `.h` y `.cpp` con las implementaciones de los algoritmos.
  - En algunas carpetas, configuración de VS Code (`.vscode/settings.json`, `.vscode/tasks.json`).

- `tests/`  
  Casos de prueba de ejemplo:
  - Archivos `.in`: entrada de prueba.
  - Archivos `.out`: salida esperada para esa entrada.

---

## Requisitos generales

- **Sistema operativo:**  
  - Probado principalmente en **Windows 10/11** (MSYS2/MinGW), pero el código es estándar C++ y debería compilar en Linux.

- **Compilador C++20 o superior:**  
  - Recomendado: `g++` (MinGW-w64 o equivalente) con soporte para `-std=c++20`.

- **Opcional (pero recomendado):**
  - **Visual Studio Code** con la extensión de C/C++.
  - Uso de las tareas configuradas en `.vscode/tasks.json` cuando existan.

Todos los módulos usan únicamente la **librería estándar de C++**, por lo que **no hay dependencias externas**.

---

## Cómo compilar y ejecutar

### Opción 1: Desde VS Code (si ya está configurado)

1. Abre VS Code en la carpeta del módulo, por ejemplo:  
   `0 - Representación de grafos/src`
2. Usa la tarea de compilación (por ejemplo, `Build & Run`) definida en `.vscode/tasks.json`.
3. El ejecutable que se genera suele llamarse `main.exe` (en Windows).

### Opción 2: Desde la línea de comandos

Ejemplo (Windows, usando MSYS2 / MinGW):

```bash
cd "0 - Representación de grafos/src"
g++ -std=c++20 -g *.cpp -o main.exe
./main.exe
