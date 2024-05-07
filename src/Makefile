# Generic Makefile for Wt "witty" programs on the CS server
# 02/28/24, jajerkins@una.edu
#
# "make start" will compile (if needed) and launch your program
# "make stop" will terminate your program, ALWAYS stop after you've tested
#
PROG= SRT		# set your program name here
PORT= 8083		# any port in the range 8080-8085 is valid
SRCS!= ls model/*.cpp
SRCS!+= ls view/*.cpp
OBJS= ${SRCS:S/cpp$/o/g}
OBJ2= ${OBJS:S/^model/./g}
OBJ3= ${OBJ2:S/^view/./g}

CXXFLAGS = -Wall -std=c++20 -g -O0 
CXXFLAGS+= -I/usr/local/include 
LDFLAGS = -L/usr/local/lib 
LDFLAGS+= -lwt -lwtdbo -lwtdbomysql -lwthttp

.PHONY: all clean start stop

all: ${PROG}

${PROG}: ${OBJS} ${OBJ3}
	${CXX} ${CXXFLAGS} -o $@ ${OBJ3} ${LDFLAGS}

clean: 
	@rm -f ${PROG} ${OBJ3} resources

start: ${PROG}
	#@ln -fs /usr/local/share/Wt/resources ./resources
	./${PROG} --docroot ./ --http-address 0.0.0.0 --http-port ${PORT} &

stop:
	@rm -f resources
	@pkill -f ${PROG}
