CC = gcc
WARNS = -Werror -Wall -Wextra -Wno-unused-parameter -Wno-unused-but-set-variable \
	-Wno-unused-result
CFLAGS = -O3 $(WARNS)
OBJS = binary.o main.o

main: $(OBJS)
	$(CC) -o binary $(OBJS)

binary.o: binary.h
main.o: binary.h

.PHONY: clean
clean:
	rm -f main
	rm -f *.o
