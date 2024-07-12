CC=g++
BIN=taskman
LIB=-lsqlite3

OPT=-O
DEPFLAGS=-MP -MD
CFLAGS=-Wall -Wextra -g $(INCLUDE) $(OPT) $(DEPFLAGS)

CODEDIRS= . ./src
INCDIRS=. ./include/ ./lib/
INCLUDE=$(foreach D,$(INCDIRS),-I$(D))

CFILES= $(foreach D, $(CODEDIRS), $(shell find $(D) -name '*.cpp'))
OBJ=$(patsubst %.cpp,%.o,$(CFILES))
DEPFILES=$(patsubst %.cpp,%.d,$(CFILES))

all: $(BIN)

$(BIN): $(OBJ)
	$(CC) -o $@ $^ $(LIB)

%.o:%.cpp
	$(CC) $(CFLAGS) -c -o $@ $^

run: all
	@./$(BIN)

clean: 
	@rm -rf $(BIN) *.o *.d $(OBJ) $(DEPFILES)
