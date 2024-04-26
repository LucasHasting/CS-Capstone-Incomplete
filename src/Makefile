# Build Witty Pet Shop demo application
# jajerkins, 02/20/2023
PROG=app
SRCS=main.cpp petShopApp.cpp \
       pet.cpp petList.cpp petType.cpp petTypeList.cpp \
       petForm.cpp addPetView.cpp searchPetsView.cpp
OBJS=${SRCS:S/cpp$/o/g}

CXXFLAGS=-Wall -std=c++17
CXXFLAGS+=-I/usr/local/include -I${.CURDIR}/model -I${.CURDIR}/view
LDFLAGS=-L/usr/local/lib
LDFLAGS+=-lwthttp -lwt

.PHONY: all clean run

all: ${PROG}

${PROG}: ${OBJS}
	${CXX} ${CXXFLAGS} -o $@ ${OBJS} ${LDFLAGS}

# model
pet.o: model/pet.cpp model/pet.h model/petType.h
petList.o: model/petList.cpp model/petList.h model/pet.h model/petType.h model/petTypeList.h
petType.o: model/petType.cpp model/petType.h
petTypeList.o: model/petTypeList.cpp model/petTypeList.h model/petType.h

# views
petForm.o: view/petForm.h view/petForm.cpp model/petList.h
addPetView.o: view/addPetView.h view/addPetView.cpp model/petList.h
searchPetsView.o: view/searchPetsView.h view/searchPetsView.cpp model/petList.h

# utilities
clean:
	@rm -f ${PROG} ${OBJS} *.core

run: ${PROG}
	./${PROG} --docroot ../ --http-address 0.0.0.0 --http-port 8080 &

