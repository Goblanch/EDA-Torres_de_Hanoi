#ifndef HANOI_GAME_H
#define HANOI_GAME_H

#include <memory>
#include "Tower.h"
#include "HanoiSolver.h"

class HanoiGame {
private:
    int numDisks;
    Tower source;
    Tower auxiliary;
    Tower destination;
    std::unique_ptr<HanoiSolver> solver;

public:
    HanoiGame(int disks, std::unique_ptr<HanoiSolver> hanoiSolver);
    void initializeTowers();
    void play();
    bool isComplete() const;
};

#endif // HANOI_GAME_H
