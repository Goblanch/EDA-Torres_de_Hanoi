#include "Disk.h"
#include "Tower.h"
#include "HanoiSolver.h"
#include "RecursiveSolver.h"
#include "IterativeSolver.h"
#include <iostream>
#include <memory>
#include <iomanip>

/**
 * @brief Initialize towers with disks
 * @param source The source tower to initialize
 * @param numDisks Number of disks to add
 */
void initializeTowers(Tower& source, int numDisks) {
    // Add disks from largest to smallest (largest at bottom)
    for (int i = numDisks; i >= 1; i--) {
        source.push(Disk(i));
    }
}

/**
 * @brief Display the moves for solving the puzzle
 * @param moves Vector of moves
 * @param strategyName Name of the strategy used
 */
void displayMoves(const std::vector<Move>& moves, const std::string& strategyName) {
    std::cout << "\n" << std::string(60, '=') << std::endl;
    std::cout << strategyName << std::endl;
    std::cout << std::string(60, '=') << std::endl;
    std::cout << "Total moves: " << moves.size() << std::endl;
    std::cout << std::string(60, '-') << std::endl;
    
    for (size_t i = 0; i < moves.size(); i++) {
        std::cout << "Move " << std::setw(2) << (i + 1) << ": ";
        std::cout << "Disk " << moves[i].diskSize << " from " 
                  << std::setw(12) << moves[i].from 
                  << " to " << std::setw(12) << moves[i].to << std::endl;
    }
    std::cout << std::string(60, '=') << std::endl;
}

/**
 * @brief Demonstrate a solving strategy
 * @param solver The solver strategy to use
 * @param numDisks Number of disks
 */
void demonstrateSolution(HanoiSolver& solver, int numDisks) {
    Tower source("Source");
    Tower auxiliary("Auxiliary");
    Tower destination("Destination");
    
    initializeTowers(source, numDisks);
    
    std::vector<Move> moves = solver.solve(source, auxiliary, destination, numDisks);
    
    displayMoves(moves, solver.getStrategyName());
    
    // Verify the solution
    std::cout << "\nVerification:" << std::endl;
    std::cout << "  Source tower has " << source.size() << " disks" << std::endl;
    std::cout << "  Auxiliary tower has " << auxiliary.size() << " disks" << std::endl;
    std::cout << "  Destination tower has " << destination.size() << " disks" << std::endl;
    
    if (destination.size() == numDisks) {
        std::cout << "  ✓ Solution is CORRECT!" << std::endl;
    } else {
        std::cout << "  ✗ Solution is INCORRECT!" << std::endl;
    }
}

int main() {
    const int NUM_DISKS = 5;
    
    std::cout << "\n";
    std::cout << "╔════════════════════════════════════════════════════════════╗\n";
    std::cout << "║          TORRES DE HANOI - IMPLEMENTACIÓN EN C++          ║\n";
    std::cout << "║                  Siguiendo principios SOLID               ║\n";
    std::cout << "╚════════════════════════════════════════════════════════════╝\n";
    std::cout << "\nNúmero de discos: " << NUM_DISKS << std::endl;
    std::cout << "Número teórico de movimientos: " << ((1 << NUM_DISKS) - 1) << std::endl;
    
    // Demonstrate recursive solution
    RecursiveSolver recursiveSolver;
    demonstrateSolution(recursiveSolver, NUM_DISKS);
    
    std::cout << "\n";
    
    // Demonstrate iterative solution
    IterativeSolver iterativeSolver;
    demonstrateSolution(iterativeSolver, NUM_DISKS);
    
    std::cout << "\n";
    std::cout << "Principios SOLID aplicados:\n";
    std::cout << "  • Single Responsibility: Cada clase tiene una única responsabilidad\n";
    std::cout << "  • Open/Closed: Las clases están abiertas a extensión (nuevos solvers)\n";
    std::cout << "  • Liskov Substitution: Los solvers son intercambiables\n";
    std::cout << "  • Interface Segregation: Interface HanoiSolver es específica\n";
    std::cout << "  • Dependency Inversion: Se depende de abstracciones (HanoiSolver)\n";
    std::cout << "\n";
    
    return 0;
}
