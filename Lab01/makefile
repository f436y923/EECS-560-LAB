
objects = main.o executive.o DoubleLinkList.o Node.o


Lab01: $(objects)
	rm *.o Lab01 
	g++ -std=c++11 -g -Wall $(objects) -o Lab01 
main.o: main.cpp executive.h

executive.o: executive.h executive.cpp DoubleLinkList.h

DoubleLinkList.o: DoubleLinkList.h DoubleLinkList.cpp Node.h
	g++ -std=c++11 -g -Wall -c DoubleLinkList.cpp
Node.o: Node.h Node.cpp
	g++ -std=c++11 -g -Wall -c Node.cpp
clean:
	rm *.o Lab01 
