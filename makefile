# Compiler and flags
CXX = g++
CXXFLAGS = -g -Wall -pedantic

# Target executable name
TARGET = solver

# Source files
SRCS = solver.cpp

# Default target to build the executable
all: $(TARGET)

# Rule to compile the executable
$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET)

# Clean target to remove the compiled executable
clean:
	rm -f $(TARGET)

# Phony targets to prevent name conflicts
.PHONY: all clean
