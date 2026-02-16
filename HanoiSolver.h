#ifndef HANOI_SOLVER_H
#define HANOI_SOLVER_H

#include "Tower.h"

class HanoiSolver {
public:
    virtual ~HanoiSolver() = default;
    virtual void solve(Tower& source, Tower& auxiliary, Tower& destination, int numDisks) = 0;
    virtual std::string getName() const = 0;
};

#endif // HANOI_SOLVER_H
