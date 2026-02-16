#include "Disk.h"

Disk::Disk(int diskSize) : size(diskSize) {}

int Disk::getSize() const {
    return size;
}

bool Disk::operator<(const Disk& other) const {
    return size < other.size;
}

bool Disk::operator>(const Disk& other) const {
    return size > other.size;
}
