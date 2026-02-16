#include "HanoiGame.h"
#include <iostream>

HanoiGame::HanoiGame(int disks, std::unique_ptr<HanoiSolver> hanoiSolver)
    : numDisks(disks), 
      source("Origen"), 
      auxiliary("Auxiliar"), 
      destination("Destino"),
      solver(std::move(hanoiSolver)) {}

void HanoiGame::initializeTowers() {
    for (int i = numDisks; i >= 1; i--) {
        source.push(Disk(i));
    }
}

void HanoiGame::play() {
    std::cout << "Iniciando juego con " << numDisks << " discos" << std::endl;
    std::cout << "Usando estrategia: " << solver->getName() << std::endl;
    
    solver->solve(source, auxiliary, destination, numDisks);
    
    if (isComplete()) {
        std::cout << "\n¡Juego completado exitosamente!" << std::endl;
    } else {
        std::cout << "\nError: El juego no se completó correctamente" << std::endl;
    }
}

bool HanoiGame::isComplete() const {
    return source.isEmpty() && auxiliary.isEmpty() && destination.size() == numDisks;
}
