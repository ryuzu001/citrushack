CC = g++
FLAGS = -Wall -Werror -ansi -pedantic
EXEC=format
all:
	$(CC) $(FLAGS) main.cpp -o $(EXEC)
clean:
	rm -f format
