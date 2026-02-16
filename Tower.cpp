#include "Tower.h"
#include <stdexcept>

Tower::Tower(const std::string& towerName) : name(towerName) {}

void Tower::push(const Disk& disk) {
    if (!disks.empty() && disk > disks.top()) {
        throw std::invalid_argument("Cannot place larger disk on smaller disk");
    }
    disks.push(disk);
}

Disk Tower::pop() {
    if (disks.empty()) {
        throw std::runtime_error("Cannot pop from empty tower");
    }
    Disk disk = disks.top();
    disks.pop();
    return disk;
}

const Disk& Tower::peek() const {
    if (disks.empty()) {
        throw std::runtime_error("Cannot peek empty tower");
    }
    return disks.top();
}

bool Tower::isEmpty() const {
    return disks.empty();
}

int Tower::size() const {
    return disks.size();
}

std::string Tower::getName() const {
    return name;
}
