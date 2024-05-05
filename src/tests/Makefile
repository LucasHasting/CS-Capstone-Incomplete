CXXFLAGS=-Wall -I/usr/local/include
SRCS=userTest.cpp ../model/User.cpp \
	riskTest.cpp ../model/Risk.cpp
OBJS=${SRCS:S/cpp$/o/g}
LDFLAGS=-L/usr/local/lib -lgtest -lgtest_main
LDFLAGS+=-lwthttp -lwt
.PHONY: all clean

all: utest

utest: ${OBJS}
	${CXX} ${CXXFLAGS} -o $@ ${OBJS:T} ${LDFLAGS}

clean:
	@rm -f utest *.o
