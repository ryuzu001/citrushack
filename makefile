CC = g++
EXEC=format
all:
	$(CC) main.cpp -o $(EXEC)
clean:
	rm -f format
