EXECUTABLE=sudoku
CXX=g++
CPPFLAGS=-std=c++11
SOURCES=SudokuSolver.cpp
OBJECTS=$(SOURCES:.cpp=.o)


all: $(SOURCES) $(HEADERS) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(OBJECTS) $(CPPFLAGS) -o $@

clean:
	rm -rf *.o *~ $(EXECUTABLE)