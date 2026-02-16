#ifndef HANOI_SOLVER_H
#define HANOI_SOLVER_H

#include "Tower.h"
#include <vector>
#include <string>

/**
 * @brief Move information structure
 */
struct Move {
    std::string from;
    std::string to;
    int diskSize;
    
    Move(const std::string& f, const std::string& t, int size) 
        : from(f), to(t), diskSize(size) {}
};

/**
 * @brief Interface for Hanoi Tower solving strategies
 * 
 * This interface follows the Strategy Pattern and Interface Segregation Principle.
 * Different solving algorithms can implement this interface.
 */
class HanoiSolver {
public:
    virtual ~HanoiSolver() = default;
    
    /**
     * @brief Solve the Towers of Hanoi puzzle
     * @param source The source tower
     * @param auxiliary The auxiliary tower
     * @param destination The destination tower
     * @param numDisks The number of disks to move
     * @return std::vector<Move> List of moves to solve the puzzle
     */
    virtual std::vector<Move> solve(Tower& source, Tower& auxiliary, Tower& destination, int numDisks) = 0;
    
    /**
     * @brief Get the name of the solving strategy
     * @return std::string The strategy name
     */
    virtual std::string getStrategyName() const = 0;
};

#endif // HANOI_SOLVER_H
