CC = gcc
WARNS = -Werror -Wall -Wextra -Wno-unused-parameter -Wno-unused-but-set-variable \
	-Wno-unused-result
CFLAGS = -O3 $(WARNS)
OBJS = common.o basic.o main.o

main: $(OBJS)
	$(CC) -o main $(OBJS)

common.o: common.h
basic.o: common.h twiddles.h
main.o: common.h twiddles.h

.PHONY: clean
clean:
	rm -f main
	rm -f *.o
