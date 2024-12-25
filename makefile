simulationExecutable: cityNode.o singlyLinkedList.o adjListGraph.o adjMatrixGraph.o main.o
	g++ -o simulationExecutable cityNode.o singlyLinkedList.o adjListGraph.o adjMatrixGraph.o main.o

cityNode.o: cityNode.h cityNode.cpp
	g++ -c cityNode.cpp

singlyLinkedList.o: listInterface.h singlyLinkedList.h singlyLinkedList.cpp
	g++ -c singlyLinkedList.cpp

adjListGraph.o: graphInterface.h adjListGraph.h adjListGraph.cpp
	g++ -c adjListGraph.cpp

adjMatrixGraph.o: graphInterface.h adjMatrixGraph.h adjMatrixGraph.cpp
	g++ -c adjMatrixGraph.cpp

main.o: singlyLinkedList.h adjMatrixGraph.h adjListGraph.h main.cpp
	g++ -c main.cpp

clean:
	rm *.o simulationExecutable

