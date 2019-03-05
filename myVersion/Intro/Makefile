IDIR=../include
CC=gcc
CFLAGS=-I$(IDIR)

ODIR=obj
LDIR = ../lib

LIBS=-lm

_DEPS = unp.h 
DEPS= $(patsubst %,$(IDIR)/%, $(_DEPS))

_OBJ = daytimetcpsrv.o error.o wrapsock.o daemon_init.o
OBJ = $(patsubst %, $(ODIR)/%, $(_OBJ))

$(ODIR)/%.o: %.c $(DEPS)
		$(CC) -c -o $@ $< $(CFLAGS)
		
hellomake: $(OBJ)
		 $(CC) -o $@ $^ $(CFLAGS) $(LIBS)
		 
.PHONY: clean

clean:
		rm -f $(ODIR)/*.o*~ core $(INCDIR)/*~



DEPS = unp.h
OBJ = daytimetcpsrv.o error.o wrapsock.o daemon_init.o
%.o: %.c $(DEPS)
		 $(CC) -c -o $@ $< $(CFLAGS)

hellomake: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)