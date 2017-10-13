OBJS = main.o Elevator.o Floor.o node.o PriorityQueue.o

UserMenu: $(OBJS)
	g++ $(OBJS) -o Elevator
	
UserMenu.o: Elevator.cpp
	g++ -c Elevator.cpp
	
main.o: main.cpp
	g++ -c main.cpp
	
RoC.o: Floor.cpp
	g++ -c Floor.cpp
	
PointCharge.o: node.cpp
	g++ -c node.cpp
	
LineCharge.o: PriorityQueue.cpp
	g++ -c PriorityQueue.cpp