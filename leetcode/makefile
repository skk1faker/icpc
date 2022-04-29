aim = 542

$(aim) : $(aim).cpp
	g++ $(aim).cpp -o $(aim) -g

.PHONY: vim debug clear exe
vim:
	vim $(aim).cpp
debug:
	gdb $(aim)
clear:
	clear $(aim)
exe :
	./$(aim) <input
