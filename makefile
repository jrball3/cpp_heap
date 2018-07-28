OBJECTS = heap.o driver.o
EXE = heapme
FLAGS = -g -std=c++11

all:	$(OBJECTS)
	g++ -o $(EXE) $(OBJECTS)

heap.o:	heap.cpp heap.h
	g++ -c $(FLAGS) heap.cpp

driver.o: driver.cpp
	g++ -c $(FLAGS) driver.cpp

clean:
	rm -rf $(OBJECTS) $(EXE)
