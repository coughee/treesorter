all: TreeSorter

TreeSorter: Tree.o TreeSorter.o Node.o main.o	
	g++ -O3 Tree.o TreeSorter.o Node.o main.o -o treesorter.exe

Main.o: main.cpp
	g++ -c main.cpp

Tree.o: Tree.cpp
	g++ -c Tree.cpp

TreeSorter.o: TreeSorter.cpp
	g++ -c TreeSorter.cpp

Node.o: Node.cpp
	g++ -c Node.cpp