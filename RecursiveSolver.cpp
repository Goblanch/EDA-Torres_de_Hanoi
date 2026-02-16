#include "RecursiveSolver.h"
#include <iostream>

RecursiveSolver::RecursiveSolver() : moveCount(0) {}

void RecursiveSolver::solve(Tower& source, Tower& auxiliary, Tower& destination, int numDisks) {
    moveCount = 0;
    std::cout << "\n=== Solución Recursiva ===" << std::endl;
    std::cout << "Resolviendo Torres de Hanoi con " << numDisks << " discos...\n" << std::endl;
    moveDisks(source, auxiliary, destination, numDisks);
    std::cout << "\nTotal de movimientos: " << moveCount << std::endl;
}

void RecursiveSolver::moveDisks(Tower& source, Tower& auxiliary, Tower& destination, int n) {
    if (n == 1) {
        moveDisk(source, destination);
        return;
    }
    
    moveDisks(source, destination, auxiliary, n - 1);
    moveDisk(source, destination);
    moveDisks(auxiliary, source, destination, n - 1);
}

void RecursiveSolver::moveDisk(Tower& from, Tower& to) {
    Disk disk = from.pop();
    to.push(disk);
    moveCount++;
    std::cout << "Movimiento " << moveCount << ": "
              << "Disco " << disk.getSize() << " de "
              << from.getName() << " a " << to.getName() << std::endl;
}

std::string RecursiveSolver::getName() const {
    return "Recursive Solver";
}

int RecursiveSolver::getMoveCount() const {
    return moveCount;
}
