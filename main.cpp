#include <iostream>
#include <memory>
#include "HanoiGame.h"
#include "RecursiveSolver.h"
#include "IterativeSolver.h"

int main() {
    const int NUM_DISKS = 5;
    
    std::cout << "========================================" << std::endl;
    std::cout << "  TORRES DE HANOI - " << NUM_DISKS << " Discos" << std::endl;
    std::cout << "========================================" << std::endl;
    
    // Solución Recursiva
    std::cout << "\n--- Ejecutando Solución Recursiva ---" << std::endl;
    HanoiGame recursiveGame(NUM_DISKS, std::make_unique<RecursiveSolver>());
    recursiveGame.initializeTowers();
    recursiveGame.play();
    
    std::cout << "\n\n";
    
    // Solución Iterativa
    std::cout << "--- Ejecutando Solución Iterativa ---" << std::endl;
    HanoiGame iterativeGame(NUM_DISKS, std::make_unique<IterativeSolver>());
    iterativeGame.initializeTowers();
    iterativeGame.play();
    
    std::cout << "\n========================================" << std::endl;
    std::cout << "  Programa finalizado" << std::endl;
    std::cout << "========================================" << std::endl;
    
    return 0;
}
