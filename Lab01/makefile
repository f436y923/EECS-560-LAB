Lab01: main.o executive.o DoubleLinkList.o Node.o
	g++ -std=c++11 -g -Wall main.o executive.o DoubleLinkList.o Node.o -o Lab01 
main.o: main.cpp executive.h
	g++ -std=c++11 -g -Wall -c main.cpp 
executive.o: executive.h executive.cpp DoubleLinkList.h
	g++ -std=c++11 -g -Wall -c executive.cpp 
DoubleLinkList.o: DoubleLinkList.h DoubleLinkList.cpp Node.h
	g++ -std=c++11 -g -Wall -c DoubleLinkList.cpp
Node.o: Node.h Node.cpp
	g++ -std=c++11 -g -Wall -c Node.cpp
clean:
	rm *.o Lab01 
