#ifndef ITERATIVE_SOLVER_H
#define ITERATIVE_SOLVER_H

#include "HanoiSolver.h"

class IterativeSolver : public HanoiSolver {
private:
    int moveCount;
    void moveDisk(Tower& from, Tower& to);
    void moveBetweenTowers(Tower& tower1, Tower& tower2);

public:
    IterativeSolver();
    void solve(Tower& source, Tower& auxiliary, Tower& destination, int numDisks) override;
    std::string getName() const override;
    int getMoveCount() const;
};

#endif // ITERATIVE_SOLVER_H
