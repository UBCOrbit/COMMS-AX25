IDIR = Inc
CC = gcc
CFLAGS = -I$(IDIR)

ODIR = obj
SDIR = Src
OBJECTS = $(subst $(SDIR),$(ODIR),$(SOURCES:.c=.o))
SOURCES = $(wildcard $(SDIR)/*.c)
 
main : $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS)

$(ODIR)/%.o : $(SDIR)/%.c
	$(CC) -c $(CFLAGS) -o $@ $<

.PHONY: clean

clean:
	del .\$(ODIR)\*.o
