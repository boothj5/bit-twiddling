CC = gcc
WARNS = -Werror -Wall -Wextra -Wno-unused-parameter -Wno-unused-but-set-variable \
	-Wno-unused-result
CFLAGS = -I ~/include -O3 $(WARNS)
TESTLIB = -L ~/lib -l headunit
OBJS = common.o basic.o main.o
TESTOBJS = test_basic.o test_common.o basic.o common.o

main: $(OBJS)
	$(CC) -o main $(OBJS)

common.o: common.h
basic.o: common.h twiddles.h
main.o: common.h twiddles.h

test_common.o: common.h
test_basic.o: common.h twiddles.h

testsuite: testsuite.h $(TESTOBJS)
	$(CC) $(CFLAGS) $(CPPLIB) testsuite.c $(TESTOBJS) -o testsuite $(TESTLIB)

.PHONY: test
test: testsuite
	./testsuite

.PHONY: clean
clean:
	rm -f main
	rm -f *.o
