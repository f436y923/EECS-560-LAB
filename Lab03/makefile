Run: Lab03
	./Lab03 Input.txt
	
test: Lab03
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./Lab03 Input.txt 

Lab03: main.o executive.o HashMap.o Node.o
	g++ -std=c++11 -g -Wall main.o executive.o HashMap.o Node.o -o Lab03

main.o: main.cpp executive.h
	g++ -std=c++11 -g -Wall -c main.cpp

executive.o: executive.h executive.cpp HashMap.h
	g++ -std=c++11 -g -Wall -c executive.cpp

HashMap.o: HashMap.h HashMap.cpp Node.h
	g++ -std=c++11 -g -Wall -c HashMap.cpp

Node.o: Node.h Node.cpp
	g++ -std=c++11 -g -Wall -c Node.cpp
clean:
	rm *.o Lab03
