OBJS   = glibps.o
TARGET = glibps.a
LDFLAGS =  -lm

all: $(TARGET)

clean:
	rm -f core *.o *~ $(TARGET)

lint:
	lint $(INCLUDE_DIRS) $(SRCS)

$(TARGET): $(OBJS)
	$(AR) crv $(TARGET) $(OBJS)

testlib:
	$(CC) $(CFLAGS) -o testlib testlib.c $(TARGET) $(LDFLAGS)
