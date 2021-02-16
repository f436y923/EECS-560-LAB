# Lab02: main.o HashMap.o executive.o HashMap.o Node.o
# 	g++ -std=c++11 -g -Wall main.o HashMap.o executive.o Node.o -o Lab02
test: Lab02
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./Lab02 Input.txt 

Lab02: main.o executive.o HashMap.o LinkedList.o Node.o
	g++ -std=c++11 -g -Wall main.o executive.o HashMap.o LinkedList.o Node.o -o Lab02

main.o: main.cpp executive.h
	g++ -std=c++11 -g -Wall -c main.cpp

# executive.o: executive.h executive.cpp HashMap.h
# 	g++ -std=c++11 -g -Wall -c executive.cpp

executive.o: executive.h executive.cpp LinkedList.h
	g++ -std=c++11 -g -Wall -c executive.cpp

# HashMap.o: HashMap.h HashMap.cpp Node.h
# 	g++ -std=c++11 -g -Wall -c HashMap.cpp
HashMap.o: HashMap.h HashMap.cpp LinkedList.h
	g++ -std=c++11 -g -Wall -c HashMap.cpp

LinkedList.o:LinkedList.h LinkedList.cpp Node.h
	g++ -std=c++11 -g -Wall -c LinkedList.cpp

Node.o: Node.h Node.cpp
	g++ -std=c++11 -g -Wall -c Node.cpp
clean:
	rm *.o Lab02 
