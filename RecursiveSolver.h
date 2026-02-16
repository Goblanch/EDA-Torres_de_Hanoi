#ifndef RECURSIVE_SOLVER_H
#define RECURSIVE_SOLVER_H

#include "HanoiSolver.h"

class RecursiveSolver : public HanoiSolver {
private:
    int moveCount;
    void moveDisks(Tower& source, Tower& auxiliary, Tower& destination, int n);
    void moveDisk(Tower& from, Tower& to);

public:
    RecursiveSolver();
    void solve(Tower& source, Tower& auxiliary, Tower& destination, int numDisks) override;
    std::string getName() const override;
    int getMoveCount() const;
};

#endif // RECURSIVE_SOLVER_H
