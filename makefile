simulationExecutable: cityNode.o singlyLinkedList.o main.o
	g++ -o simulationExecutable cityNode.o singlyLinkedList.o main.o

cityNode.o: cityNode.h cityNode.cpp
	g++ -c cityNode.cpp

singlyLinkedList.o: listInterface.h singlyLinkedList.h singlyLinkedList.cpp
	g++ -c singlyLinkedList.cpp

main.o: singlyLinkedList.h main.cpp
	g++ -c main.cpp

clean:
	rm *.o simulationExecutable

