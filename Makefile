CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -O2
TARGET = hanoi
SOURCES = main.cpp Disk.cpp Tower.cpp RecursiveSolver.cpp IterativeSolver.cpp
OBJECTS = $(SOURCES:.cpp=.o)
HEADERS = Disk.h Tower.h HanoiSolver.h RecursiveSolver.h IterativeSolver.h

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS) $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run
