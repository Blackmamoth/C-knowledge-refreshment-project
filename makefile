CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c2x -I./headers

SRCS = $(wildcard ./*.c)
OBJS = $(SRCS:.c=.o)

TARGET = management

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET) students.csv
