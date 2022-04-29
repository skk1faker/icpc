name = 1627C

$(name) : $(name).cpp
	g++  $(name).cpp -o exe -g
	./exe <input
.PHONY:exe debug rm
exe:
	./$(name) < input
debug:
	gdb exe

