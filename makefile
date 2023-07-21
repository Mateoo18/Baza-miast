output: main.o Graph.o Aglomeracja.o Miasto.o Wsie.o
	g++ main.o Graph.o Aglomeracja.o Miasto.o Wsie.o -o output
	
main.o: main.cpp
	g++ -c main.cpp
Aglomeracja.o: Aglomeracja.cpp
	g++ -c Aglomeracja.cpp
Graph.o: Graph.cpp
	g++ -c Graph.cpp
Miasto.o: Miasto.cpp
	g++ -c Miasto.cpp
Wsie.o: Wsie.cpp
	g++ -c Wsie.cpp
	

	
clean:
	rm  *.o output

