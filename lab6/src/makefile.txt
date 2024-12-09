CC = gcc
CFLAGS = -I. -lpthread -Wall -Wextra

LIB = common.o

all: client server

client: client.o $(LIB)
	$(CC) -o client client.o $(LIB) $(CFLAGS)

server: server.o $(LIB)
	$(CC) -o server server.o $(LIB) $(CFLAGS)

common.o: common.c common.h
	$(CC) -c common.c $(CFLAGS)

client.o: client.c common.h
	$(CC) -c client.c $(CFLAGS)

server.o: server.c common.h
	$(CC) -c server.c $(CFLAGS)

clean:
	rm client server common.o client.o server.o