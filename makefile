SOURCES = main.cpp train.cpp wagon.cpp material_wagon.cpp wagon_for_people.cpp input_functions.cpp main_functions.cpp myexceptions.cpp

program: $(SOURCES)
	g++ $(SOURCES) -std=c++11 -g -Wall -o program
