CXXFLAGS=-Wall -I/usr/local/include
SRCS=../view/main.cpp ../model/User.cpp userTest.cpp
OBJS=${SRCS:S/cpp$/o/g}
LDFLAGS=-L/usr/local/lib -lgtest -lgtest_main

.PHONY: all clean

all: utest

utest: ${OBJS}
	${CXX} ${CXXFLAGS} -o $@ ${OBJS} ${LDFLAGS}

User.o : ../model/User.cpp ../model/User.h

clean:
	@rm -f utest *.o
