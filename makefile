Main01: Main.o Option.o BSModel01.o MCOption.o grid.o AsianCon.o BSOption.o BSModel.o
	g++ Main.o Option.o BSModel01.o MCOption.o grid.o AsianCon.o BSOption.o BSModel.o -o Main01

Main.o: Main.cpp
	g++ -c Main.cpp

Option.o: Option.cpp Option.h
	g++ -c Option.cpp

BSModel01.o: BSModel01.cpp BSModel01.h
	g++ -c BSModel01.cpp

MCOption.o: MCOption.cpp MCOption.h
	g++ -c MCOption.cpp

AsianCon.o: AsianCon.cpp AsianCon.h
	g++ -c AsianCon.cpp

grid.o: grid.cpp grid.h
	g++ -c grid.cpp

BSOption.o: BSOption.cpp BSOption.h
	g++ -c BSOption.cpp

BSModel.o: BSModel.cpp BSModel.h
	g++ -c BSModel.cpp -o BSModel.o

clean:
	rm *.o Main01

