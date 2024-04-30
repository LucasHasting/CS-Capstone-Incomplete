CXXFLAGS=-Wall -I/usr/local/include -g -O0
SRCS=main.cpp userTest.cpp User.cpp
OBJS=${SRCS:S/cpp$/o/g}
LDFLAGS=-L/usr/local/lib -lgtest -lgtest_main

.PHONY: all clean

all: utest

utest: ${OBJS}
	${CXX} ${CXXFLAGS} -o $@ ${OBJS} ${LDFLAGS}


clean:
	@rm -f utest *.o
