CC = g++
FLAGS = -Wall -Werror -ansi -pedantic
EXEC=format
all:
	$(CC) $(FLAGS) main.cpp -o $(EXEC)
test:
	$(CC) $(FLAGS) test.cpp -o $(EXEC)
clean:
	rm -f format
	rm -f test_formatted.txt
	rm -f a.out
