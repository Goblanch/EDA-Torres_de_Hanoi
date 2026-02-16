#include "IterativeSolver.h"
#include <iostream>
#include <cmath>

IterativeSolver::IterativeSolver() : moveCount(0) {}

void IterativeSolver::solve(Tower& source, Tower& auxiliary, Tower& destination, int numDisks) {
    moveCount = 0;
    std::cout << "\n=== Solución Iterativa ===" << std::endl;
    std::cout << "Resolviendo Torres de Hanoi con " << numDisks << " discos...\n" << std::endl;
    
    int totalMoves = static_cast<int>(std::pow(2, numDisks)) - 1;
    
    Tower* tower1;
    Tower* tower2;
    Tower* tower3;
    
    if (numDisks % 2 == 0) {
        tower1 = &source;
        tower2 = &auxiliary;
        tower3 = &destination;
    } else {
        tower1 = &source;
        tower2 = &destination;
        tower3 = &auxiliary;
    }
    
    for (int i = 1; i <= totalMoves; i++) {
        if (i % 3 == 1) {
            moveBetweenTowers(*tower1, *tower2);
        } else if (i % 3 == 2) {
            moveBetweenTowers(*tower1, *tower3);
        } else {
            moveBetweenTowers(*tower2, *tower3);
        }
    }
    
    std::cout << "\nTotal de movimientos: " << moveCount << std::endl;
}

void IterativeSolver::moveBetweenTowers(Tower& tower1, Tower& tower2) {
    if (tower1.isEmpty() && tower2.isEmpty()) {
        return;
    } else if (tower1.isEmpty()) {
        moveDisk(tower2, tower1);
    } else if (tower2.isEmpty()) {
        moveDisk(tower1, tower2);
    } else if (tower1.peek() < tower2.peek()) {
        moveDisk(tower1, tower2);
    } else {
        moveDisk(tower2, tower1);
    }
}

void IterativeSolver::moveDisk(Tower& from, Tower& to) {
    Disk disk = from.pop();
    to.push(disk);
    moveCount++;
    std::cout << "Movimiento " << moveCount << ": "
              << "Disco " << disk.getSize() << " de "
              << from.getName() << " a " << to.getName() << std::endl;
}

std::string IterativeSolver::getName() const {
    return "Iterative Solver";
}

int IterativeSolver::getMoveCount() const {
    return moveCount;
}
