CODEDIRS= . ./src
INCDIRS=. ./include/

LIB=-lsqlite3

CC=g++
OPT=-O

DEPFLAGS=-MP -MD 

CFLAGS=-Wall -Wextra -g $(foreach D,$(INCDIRS),-I$(D)) $(OPT) $(DEPFLAGS)

SRC=src

CFILES=$(foreach D,$(CODEDIRS), $(wildcard $(D)/*.cpp))

OBJ=$(patsubst %.cpp,%.o,$(CFILES))
DEPFILES=$(patsubst %.cpp,%.d,$(CFILES))

BINARY=taskman

all: $(BINARY)

$(BINARY): $(OBJ)
	$(CC) -o $@ $^ $(LIB)

%.o:%.cpp
	$(CC) $(CFLAGS) -c -o $@ $^ 

run:
	@./$(BINARY)

clean: 
	rm -rf $(BINARY) *.o *.d src/*.o src/*.d
