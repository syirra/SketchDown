# Project: SketchDown

CPP  = g++
CC   = gcc
WINDRES = windres
RES  = 
OBJ  = main.o $(RES)
LINKOBJ  = main.o $(RES)
LIBS =  -lSDLmain  -lSDL
INCS = 
CXXINCS = 
BIN  = SketchDown
CXXFLAGS = $(CXXINCS)  
CFLAGS = $(INCS)  
RM = rm -f


.PHONY: all all-before all-after clean clean-custom

all: all-before SketchDown all-after


clean: clean-custom
	${RM} $(OBJ) $(BIN)

$(BIN): $(OBJ)	
	$(CPP) $(LINKOBJ) -o "SketchDown" $(LIBS)

main.o: main.cpp
	$(CPP) -c main.cpp -o main.o $(CXXFLAGS)
