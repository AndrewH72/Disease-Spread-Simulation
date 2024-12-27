simulationExecutable: disease.o cityNode.o singlyLinkedList.o adjListGraph.o adjMatrixGraph.o helpers.o main.o
	g++ -o simulationExecutable disease.o cityNode.o singlyLinkedList.o adjListGraph.o adjMatrixGraph.o helpers.o main.o

disease.o: disease.h disease.cpp
	g++ -c disease.cpp

cityNode.o: cityNode.h cityNode.cpp
	g++ -c cityNode.cpp

singlyLinkedList.o: listInterface.h singlyLinkedList.h singlyLinkedList.cpp
	g++ -c singlyLinkedList.cpp

adjListGraph.o: graphInterface.h arrayStack.h arrayQueue.h adjListGraph.h adjListGraph.cpp
	g++ -c adjListGraph.cpp

adjMatrixGraph.o: graphInterface.h arrayStack.h arrayQueue.h adjMatrixGraph.h adjMatrixGraph.cpp
	g++ -c adjMatrixGraph.cpp

helpers.o: singlyLinkedList.h adjMatrixGraph.h adjListGraph.h disease.h helpers.h helpers.cpp
	g++ -c helpers.cpp

main.o: helpers.h main.cpp
	g++ -c main.cpp

clean:
	rm *.o simulationExecutable

