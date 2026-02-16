# EDA-Torres_de_Hanoi
Implementación de torres de Hanoi con 5 discos.

## Descripción
Este programa implementa el clásico problema de las Torres de Hanoi con 5 discos utilizando dos enfoques diferentes:
- **Solución Recursiva**: Implementación clásica basada en recursión
- **Solución Iterativa**: Implementación iterativa usando un algoritmo basado en patrones

## Principios de Diseño
El programa sigue los principios SOLID y de Programación Orientada a Objetos:

### SOLID
1. **Single Responsibility Principle (SRP)**: Cada clase tiene una única responsabilidad
   - `Disk`: Representa un disco
   - `Tower`: Representa una torre/rod
   - `HanoiSolver`: Interfaz para resolvers
   - `RecursiveSolver`: Implementa solución recursiva
   - `IterativeSolver`: Implementa solución iterativa
   - `HanoiGame`: Gestiona el juego

2. **Open/Closed Principle (OCP)**: Las clases están abiertas para extensión pero cerradas para modificación
   - Se puede agregar nuevos solvers implementando la interfaz `HanoiSolver`

3. **Liskov Substitution Principle (LSP)**: Los solvers son intercambiables
   - `RecursiveSolver` y `IterativeSolver` pueden sustituirse sin afectar el comportamiento

4. **Interface Segregation Principle (ISP)**: Interfaces pequeñas y específicas
   - `HanoiSolver` solo define lo necesario para resolver el problema

5. **Dependency Inversion Principle (DIP)**: Dependencia en abstracciones
   - `HanoiGame` depende de la abstracción `HanoiSolver`, no de implementaciones concretas

### Programación Orientada a Objetos
- **Encapsulación**: Datos y métodos encapsulados en clases
- **Abstracción**: Interfaz `HanoiSolver` abstrae el algoritmo de solución
- **Polimorfismo**: Diferentes solvers pueden usarse de manera intercambiable
- **Composición**: `HanoiGame` compone torres y usa un solver mediante inyección de dependencias

## Estructura del Proyecto
```
.
├── Disk.h / Disk.cpp           # Clase Disk
├── Tower.h / Tower.cpp         # Clase Tower
├── HanoiSolver.h               # Interfaz HanoiSolver
├── RecursiveSolver.h/.cpp      # Implementación recursiva
├── IterativeSolver.h/.cpp      # Implementación iterativa
├── HanoiGame.h / HanoiGame.cpp # Clase HanoiGame
├── main.cpp                    # Programa principal
├── Makefile                    # Archivo de construcción
└── README.md                   # Este archivo
```

## Compilación
Para compilar el programa:
```bash
make
```

Para limpiar los archivos compilados:
```bash
make clean
```

## Ejecución
Para ejecutar el programa:
```bash
make run
```

O directamente:
```bash
./hanoi
```

## Salida Esperada
El programa ejecuta ambas soluciones (recursiva e iterativa) y muestra:
- Los 31 movimientos necesarios para resolver el problema
- Confirmación de que ambas soluciones completan correctamente

## Requisitos
- Compilador C++ con soporte para C++14 o superior
- Make (para usar el Makefile)
