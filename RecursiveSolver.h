#ifndef RECURSIVE_SOLVER_H
#define RECURSIVE_SOLVER_H

#include "HanoiSolver.h"

/**
 * @brief Recursive implementation of the Towers of Hanoi solver
 * 
 * This class implements the classic recursive solution to the problem.
 * Follows Single Responsibility Principle - only responsible for recursive solving.
 */
class RecursiveSolver : public HanoiSolver {
private:
    std::vector<Move> moves;
    
    /**
     * @brief Helper method for recursive solving
     * @param n Number of disks to move
     * @param source Source tower
     * @param auxiliary Auxiliary tower
     * @param destination Destination tower
     */
    void solveRecursive(int n, Tower& source, Tower& auxiliary, Tower& destination);

public:
    RecursiveSolver() = default;
    
    std::vector<Move> solve(Tower& source, Tower& auxiliary, Tower& destination, int numDisks) override;
    
    std::string getStrategyName() const override;
};

#endif // RECURSIVE_SOLVER_H
