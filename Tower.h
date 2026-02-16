#ifndef TOWER_H
#define TOWER_H

#include <stack>
#include <string>
#include "Disk.h"

class Tower {
private:
    std::stack<Disk> disks;
    std::string name;

public:
    explicit Tower(const std::string& towerName);
    void push(const Disk& disk);
    Disk pop();
    const Disk& peek() const;
    bool isEmpty() const;
    int size() const;
    std::string getName() const;
};

#endif // TOWER_H
