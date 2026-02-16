#ifndef ITERATIVE_SOLVER_H
#define ITERATIVE_SOLVER_H

#include "HanoiSolver.h"

/**
 * @brief Iterative implementation of the Towers of Hanoi solver
 * 
 * This class implements an iterative solution using a stack-based approach.
 * Follows Single Responsibility Principle - only responsible for iterative solving.
 */
class IterativeSolver : public HanoiSolver {
private:
    /**
     * @brief Get the legal move for a disk between two towers
     * @param t1 First tower
     * @param t2 Second tower
     * @param moves Vector to store the move
     */
    void moveBetweenTowers(Tower& t1, Tower& t2, std::vector<Move>& moves);

public:
    IterativeSolver() = default;
    
    std::vector<Move> solve(Tower& source, Tower& auxiliary, Tower& destination, int numDisks) override;
    
    std::string getStrategyName() const override;
};

#endif // ITERATIVE_SOLVER_H
