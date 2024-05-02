CXXFLAGS=-Wall -I/usr/local/include
SRCS=../view/main.cpp userTest.cpp ../model/User.cpp
OBJS=${SRCS:S/cpp$/o/g}
LDFLAGS=-L/usr/local/lib -lgtest -lgtest_main
LDFLAGS+=-lwthttp -lwt
.PHONY: all clean

all: utest

utest: ${OBJS}
	${CXX} ${CXXFLAGS} -o $@ ${OBJS:T} ${LDFLAGS}


clean:
	@rm -f utest *.o
