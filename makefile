myHugeInt: myHugeInt.o HugeInt.o
	g++ -o myHugeInt HugeInt.o myHugeInt.o
myHugeInt.o: HugeInt.h myHugeInt.cpp
	g++ -c myHugeInt.cpp
HugeInt.o: HugeInt.h HugeInt.cpp
	g++ -c HugeInt.cpp

clean:
	rm myHugeInt *.o