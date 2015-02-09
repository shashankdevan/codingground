all: g++ Driver.cpp RandomBST.h RandomBST.cpp -o Driver.out

Driver.o: Driver.cpp
	g++ -Wall -c Driver.cpp
RandomBST.o: RandomBST.cpp
	g++ -Wall -c RandomBST.cpp
run:
	./Driver.out
clean:
	rm -rf *.o
	rm -rf Driver.out
	rm -f *~ *.h.gch *
