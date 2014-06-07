##############################################################
#                                                            #
#                         MAKEFILE                           #
#                                                            #
##############################################################
CC=gcc
OUTPUT=../bin/
HEADER=../include/
OBJ=../obj/
SRC=../src/
CFLAGS=-c -g -Wall

$(OUTPUT)server: $(OBJ)server.o $(OUTPUT)client $(OBJ)func.o
	$(CC) -o server $(OBJ)server.o $(OBJ)func.o 
	mv server $(OUTPUT)

$(OUTPUT)client: $(OBJ)client.o $(OBJ)func.o
	$(CC) -o client $(OBJ)client.o $(OBJ)func.o
	mv client $(OUTPUT)

$(OBJ)func.o: $(SRC)func.c
	$(CC) $(CFLAGS) $(SRC)func.c -I $(HEADER)
	mv func.o $(OBJ)

$(OBJ)server.o: $(SRC)server.c
	$(CC) $(CFLAGS) $(SRC)server.c -I $(HEADER)
	mv server.o $(OBJ)

$(OBJ)client.o: $(SRC)client.c
	$(CC) $(CFLAGS) $(SRC)client.c -I $(HEADER)
	mv client.o $(OBJ)

clean:
	rm $(OUTPUT)server $(OUTPUT)client
	rm $(OBJ)server.o $(OBJ)client.o


