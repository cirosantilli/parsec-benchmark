OBJS   = glib.o
TARGET = glib.a
CFLAGS = $(CCOPT) $(CCDEFS) $(INCLUDE_DIRS)
LDFLAGS += -lgl -lpanel -lm

all: $(TARGET)

clean:
	rm -f core *.o *~ $(TARGET)

$(TARGET): glib.o
	$(AR) crv $(TARGET) glib.o

testlib:
	$(CC) -O -o testlib testlib.c $(TARGET) $(LDFLAGS)
