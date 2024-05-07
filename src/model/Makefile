#Generic Makefile for Wt "witty" programs on the CS server
# 02 / 28 / 24, jajerkins @una.edu
#
#"make start" will compile(if needed) and launch your program
#"make stop" will terminate your program, ALWAYS stop after you've tested
#
PROG = test #set your program name here 
PORT = 8085 #any port in the range 8080 - 8085 is valid 
SRCS!= ls *.cpp
OBJS = ${SRCS:S/cpp$/o/g}

CXXFLAGS = -Wall -std=c++20 -g -O0 
CXXFLAGS+= -I/usr/local/include 
LDFLAGS = -L/usr/local/lib 
LDFLAGS+= -lwt -lwtdbo -lwtdbomysql -lwthttp

.PHONY : all clean

all : ${PROG}

${PROG} : ${OBJS} 
	${CXX} ${CXXFLAGS} -o $@ ${OBJS} ${LDFLAGS} 

clean : 
	@rm -f ${PROG} ${OBJS} resources
