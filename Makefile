# Makefile

CXX = g++
CXXFLAGS = -Wall -g -pg
TARGET = wordrange
OBJS = wordrange.o

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

wordrange.o: wordrange.cpp wordrange.h
	$(CXX) $(CXXFLAGS) -c wordrange.cpp

clean:
	rm -f $(OBJS) $(TARGET)

.PHONY: clean
