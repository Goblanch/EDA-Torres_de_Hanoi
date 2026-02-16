#include "RecursiveSolver.h"

void RecursiveSolver::solveRecursive(int n, Tower& source, Tower& auxiliary, Tower& destination) {
    if (n == 1) {
        Disk disk = source.pop();
        int diskSize = disk.getSize();
        destination.push(disk);
        moves.push_back(Move(source.getName(), destination.getName(), diskSize));
        return;
    }
    
    // Move n-1 disks from source to auxiliary using destination
    solveRecursive(n - 1, source, destination, auxiliary);
    
    // Move the largest disk from source to destination
    Disk disk = source.pop();
    int diskSize = disk.getSize();
    destination.push(disk);
    moves.push_back(Move(source.getName(), destination.getName(), diskSize));
    
    // Move n-1 disks from auxiliary to destination using source
    solveRecursive(n - 1, auxiliary, source, destination);
}

std::vector<Move> RecursiveSolver::solve(Tower& source, Tower& auxiliary, Tower& destination, int numDisks) {
    moves.clear();
    solveRecursive(numDisks, source, auxiliary, destination);
    return moves;
}

std::string RecursiveSolver::getStrategyName() const {
    return "Recursive Solution";
}
