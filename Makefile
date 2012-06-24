CC = gcc
WARNS = -Werror -Wall -Wextra -Wno-unused-parameter -Wno-unused-but-set-variable \
	-Wno-unused-result
CFLAGS = -O3 $(WARNS)
OBJS = main.o

main: $(OBJS)
	$(CC) -o main $(OBJS)

.PHONY: clean
clean:
	rm -f main
	rm -f *.o
