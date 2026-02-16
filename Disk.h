#ifndef DISK_H
#define DISK_H

/**
 * @brief Represents a disk in the Towers of Hanoi puzzle
 * 
 * Encapsulates the disk's size property following OOP principles
 */
class Disk {
private:
    int size;

public:
    /**
     * @brief Construct a new Disk object
     * @param diskSize The size of the disk (larger number = larger disk)
     */
    explicit Disk(int diskSize);
    
    /**
     * @brief Get the size of the disk
     * @return int The disk size
     */
    int getSize() const;
    
    /**
     * @brief Compare disk sizes
     * @param other The disk to compare with
     * @return true if this disk is smaller than the other
     */
    bool isSmallerThan(const Disk& other) const;
};

#endif // DISK_H
