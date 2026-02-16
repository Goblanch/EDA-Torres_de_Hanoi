#include "Tower.h"
#include <stdexcept>

Tower::Tower(const std::string& towerName) : name(towerName) {}

void Tower::push(const Disk& disk) {
    if (!isEmpty() && !disk.isSmallerThan(peek())) {
        throw std::runtime_error("Cannot place larger disk on smaller disk");
    }
    disks.push(disk);
}

Disk Tower::pop() {
    if (isEmpty()) {
        throw std::runtime_error("Cannot pop from empty tower");
    }
    Disk disk = disks.top();
    disks.pop();
    return disk;
}

const Disk& Tower::peek() const {
    if (isEmpty()) {
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

const std::string& Tower::getName() const {
    return name;
}
