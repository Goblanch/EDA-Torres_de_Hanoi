# EDA-Torres_de_Hanoi
Implementación de Torres de Hanoi con 5 discos en C++ siguiendo los principios SOLID y de la POO.

## Descripción

Este proyecto implementa el problema clásico de las Torres de Hanoi con dos soluciones diferentes:
- **Solución Recursiva**: Implementación clásica usando recursión
- **Solución Iterativa**: Implementación usando un algoritmo iterativo

## Principios SOLID Aplicados

1. **Single Responsibility Principle (SRP)**: Cada clase tiene una única responsabilidad:
   - `Disk`: Representa un disco individual
   - `Tower`: Gestiona una torre con sus discos
   - `RecursiveSolver`: Implementa la solución recursiva
   - `IterativeSolver`: Implementa la solución iterativa

2. **Open/Closed Principle (OCP)**: El diseño está abierto a extensión (se pueden agregar nuevos tipos de solvers) pero cerrado a modificación.

3. **Liskov Substitution Principle (LSP)**: Los solvers (RecursiveSolver e IterativeSolver) son intercambiables a través de la interfaz HanoiSolver.

4. **Interface Segregation Principle (ISP)**: La interfaz HanoiSolver es específica y contiene solo los métodos necesarios.

5. **Dependency Inversion Principle (DIP)**: El código depende de abstracciones (HanoiSolver) en lugar de implementaciones concretas.

## Estructura del Proyecto

```
EDA-Torres_de_Hanoi/
├── Disk.h              # Definición de la clase Disk
├── Disk.cpp            # Implementación de la clase Disk
├── Tower.h             # Definición de la clase Tower
├── Tower.cpp           # Implementación de la clase Tower
├── HanoiSolver.h       # Interface para estrategias de solución
├── RecursiveSolver.h   # Definición del solver recursivo
├── RecursiveSolver.cpp # Implementación del solver recursivo
├── IterativeSolver.h   # Definición del solver iterativo
├── IterativeSolver.cpp # Implementación del solver iterativo
├── main.cpp            # Programa principal
├── Makefile            # Archivo de construcción
└── README.md           # Este archivo
```

## Compilación

Para compilar el proyecto, ejecuta:

```bash
make
```

Para limpiar los archivos de compilación:

```bash
make clean
```

## Ejecución

Después de compilar, ejecuta el programa:

```bash
./hanoi
```

O directamente:

```bash
make run
```

## Salida del Programa

El programa muestra:
1. Solución recursiva con todos los movimientos
2. Solución iterativa con todos los movimientos
3. Verificación de que ambas soluciones son correctas
4. Resumen de los principios SOLID aplicados

Cada solución muestra exactamente 31 movimientos (2^5 - 1) para resolver el puzzle con 5 discos.

## Requisitos

- Compilador C++ compatible con C++11 o superior (g++, clang++)
- Make

## Características

- ✅ Implementación en C++
- ✅ Solución recursiva
- ✅ Solución iterativa
- ✅ 5 discos
- ✅ Principios SOLID
- ✅ Programación Orientada a Objetos
- ✅ Código documentado
- ✅ Salida formateada y legible
