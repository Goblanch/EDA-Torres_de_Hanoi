CXX = g++
CXXFLAGS = -std=c++14 -Wall -Wextra -pedantic
TARGET = hanoi
OBJS = main.o Disk.o Tower.o RecursiveSolver.o IterativeSolver.o HanoiGame.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp HanoiGame.h RecursiveSolver.h IterativeSolver.h
	$(CXX) $(CXXFLAGS) -c main.cpp

Disk.o: Disk.cpp Disk.h
	$(CXX) $(CXXFLAGS) -c Disk.cpp

Tower.o: Tower.cpp Tower.h Disk.h
	$(CXX) $(CXXFLAGS) -c Tower.cpp

RecursiveSolver.o: RecursiveSolver.cpp RecursiveSolver.h HanoiSolver.h Tower.h Disk.h
	$(CXX) $(CXXFLAGS) -c RecursiveSolver.cpp

IterativeSolver.o: IterativeSolver.cpp IterativeSolver.h HanoiSolver.h Tower.h Disk.h
	$(CXX) $(CXXFLAGS) -c IterativeSolver.cpp

HanoiGame.o: HanoiGame.cpp HanoiGame.h Tower.h HanoiSolver.h Disk.h
	$(CXX) $(CXXFLAGS) -c HanoiGame.cpp

clean:
	rm -f $(OBJS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
