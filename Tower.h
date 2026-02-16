#ifndef TOWER_H
#define TOWER_H

#include "Disk.h"
#include <stack>
#include <string>

/**
 * @brief Represents a tower (rod) in the Towers of Hanoi puzzle
 * 
 * Manages a stack of disks and enforces the rule that smaller disks
 * must be placed on top of larger disks
 */
class Tower {
private:
    std::stack<Disk> disks;
    std::string name;

public:
    /**
     * @brief Construct a new Tower object
     * @param towerName The name/identifier of the tower
     */
    explicit Tower(const std::string& towerName);
    
    /**
     * @brief Add a disk to the top of this tower
     * @param disk The disk to add
     */
    void push(const Disk& disk);
    
    /**
     * @brief Remove and return the top disk from this tower
     * @return Disk The disk that was removed
     */
    Disk pop();
    
    /**
     * @brief Get the top disk without removing it
     * @return const Disk& Reference to the top disk
     */
    const Disk& peek() const;
    
    /**
     * @brief Check if the tower is empty
     * @return true if the tower has no disks
     */
    bool isEmpty() const;
    
    /**
     * @brief Get the number of disks on this tower
     * @return int The number of disks
     */
    int size() const;
    
    /**
     * @brief Get the name of this tower
     * @return const std::string& The tower name
     */
    const std::string& getName() const;
};

#endif // TOWER_H
