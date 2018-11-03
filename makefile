CC = gcc
CFLAGS = -Wall

clean:
	rm -f *.o

%.o: %.c
	$(CC) $(CFLAGS) $^ -c 

main: funciones.o main.o
	$(CC) $(CFLAGS) $^ -o exe
