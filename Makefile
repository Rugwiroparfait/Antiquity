CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c99
LIBS = -lcurl

SRC = main.c fetcher.c
OBJ = $(SRC:.c=.o)
TARGET = browser

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

clean:
	rm -f *.o $(TARGET)

