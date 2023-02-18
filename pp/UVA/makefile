name = la4794
name.cpp = $(name).cpp
name.o = $(name).o
$(name) : $(name.o)
	g++ -o $(name) $(name.o)
$(name.o): $(name.cpp)
	g++ -c -g $(name.cpp) -o $(name.o)
.PHONY: clear
clear :
	./$(name) < input
	rm $(name.o)



