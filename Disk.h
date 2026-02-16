#ifndef DISK_H
#define DISK_H

class Disk {
private:
    int size;

public:
    explicit Disk(int diskSize);
    int getSize() const;
    bool operator<(const Disk& other) const;
    bool operator>(const Disk& other) const;
};

#endif // DISK_H
