#include "IterativeSolver.h"

void IterativeSolver::moveBetweenTowers(Tower& t1, Tower& t2, std::vector<Move>& moves) {
    // If both towers are empty, nothing to do
    if (t1.isEmpty() && t2.isEmpty()) {
        return;
    }
    
    // If one tower is empty, move from the other
    if (t1.isEmpty()) {
        Disk disk = t2.pop();
        int diskSize = disk.getSize();
        t1.push(disk);
        moves.push_back(Move(t2.getName(), t1.getName(), diskSize));
    } else if (t2.isEmpty()) {
        Disk disk = t1.pop();
        int diskSize = disk.getSize();
        t2.push(disk);
        moves.push_back(Move(t1.getName(), t2.getName(), diskSize));
    } else {
        // Both towers have disks - move the smaller disk on top of the larger
        if (t1.peek().isSmallerThan(t2.peek())) {
            Disk disk = t1.pop();
            int diskSize = disk.getSize();
            t2.push(disk);
            moves.push_back(Move(t1.getName(), t2.getName(), diskSize));
        } else {
            Disk disk = t2.pop();
            int diskSize = disk.getSize();
            t1.push(disk);
            moves.push_back(Move(t2.getName(), t1.getName(), diskSize));
        }
    }
}

std::vector<Move> IterativeSolver::solve(Tower& source, Tower& auxiliary, Tower& destination, int numDisks) {
    std::vector<Move> moves;
    
    // Total number of moves required
    int totalMoves = (1 << numDisks) - 1;
    
    // For odd number of disks, the sequence is: source-destination, source-auxiliary, auxiliary-destination
    // For even number of disks, the sequence is: source-auxiliary, source-destination, auxiliary-destination
    
    if (numDisks % 2 == 0) {
        // Even number of disks
        for (int i = 1; i <= totalMoves; i++) {
            if (i % 3 == 1) {
                moveBetweenTowers(source, auxiliary, moves);
            } else if (i % 3 == 2) {
                moveBetweenTowers(source, destination, moves);
            } else {
                moveBetweenTowers(auxiliary, destination, moves);
            }
        }
    } else {
        // Odd number of disks
        for (int i = 1; i <= totalMoves; i++) {
            if (i % 3 == 1) {
                moveBetweenTowers(source, destination, moves);
            } else if (i % 3 == 2) {
                moveBetweenTowers(source, auxiliary, moves);
            } else {
                moveBetweenTowers(auxiliary, destination, moves);
            }
        }
    }
    
    return moves;
}

std::string IterativeSolver::getStrategyName() const {
    return "Iterative Solution";
}
