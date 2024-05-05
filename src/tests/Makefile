CXXFLAGS=-Wall -I/usr/local/include
SRCS=userTest.cpp ../model/User.cpp \
	riskTest.cpp ../model/Risk.cpp \
	databaseTest.cpp ../model/DatabaseConnection.cpp
OBJS=${SRCS:S/cpp$/o/g}
LDFLAGS=-L/usr/local/lib -lgtest -lgtest_main
LDFLAGS+=-lwthttp -lwt -lwtdbo -lwtdbomysql
.PHONY: all clean

all: utest

utest: ${OBJS}
	${CXX} ${CXXFLAGS} -o $@ ${OBJS:T} ${LDFLAGS}

clean:
	@rm -f utest *.o
