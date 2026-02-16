#include "Disk.h"

Disk::Disk(int diskSize) : size(diskSize) {}

int Disk::getSize() const {
    return size;
}

bool Disk::isSmallerThan(const Disk& other) const {
    return size < other.size;
}
