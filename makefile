CC = g++
FLAGS = -Wall -Werror -ansi -pedantic
EXEC=format
all:
	$(CC) $(FLAGS) main.cpp -o $(EXEC)
test:
	$(CC) $(FLAGS) test.cpp -o $(EXEC)
clean:
	rm -f format
	rm -f a_formatted
	rm -f b_formatted
	rm -f a.out
