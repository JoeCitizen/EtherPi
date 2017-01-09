IDIR =./include
CC=g++
CFLAGS=-I$(IDIR)

ODIR=obj
LDIR =./lib

LIBS=-lm -lwiringPi -lstdc++

_DEPS = Common.h Receive.h Send.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = EtherPi.o Receive.o Send.o 
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

EtherPi: $(OBJ)
	gcc -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f $(ODIR)/*.o *~ core $(INCDIR)/*~ 
