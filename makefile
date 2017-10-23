OBJS = main.o Elevator.o Floor.o node.o PriorityQueue.o ControlHub.o

Elevator: $(OBJS)
	g++ $(OBJS) -o Elevator
	
Elevator.o: Elevator.cpp
	g++ -c Elevator.cpp
	
main.o: main.cpp
	g++ -c main.cpp
	
Floor.o: Floor.cpp
	g++ -c Floor.cpp
	
node.o: node.cpp
	g++ -c node.cpp
	
PriorityQueue.o: PriorityQueue.cpp
	g++ -c PriorityQueue.cpp

ControlHub.o: ControlHub.cpp
	g++ -c ControlHub.cpp