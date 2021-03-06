CC = g++
FLAGS = -Wall -Werror -ansi -pedantic
EXEC=format
all:
	$(CC) $(FLAGS) main.cpp -o $(EXEC)
test:
	$(CC) $(FLAGS) "other src"/test.cpp -o $(EXEC)
clean:
	rm -f format
	rm -f *_formatted*
