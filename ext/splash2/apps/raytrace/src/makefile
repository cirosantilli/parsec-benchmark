TARGET = raytrace
OBJS = bbox.o cr.o env.o fbuf.o geo.o huprn.o husetup.o hutv.o isect.o \
	main.o matrix.o memory.o poly.o raystack.o shade.o sph.o trace.o \
	tri.o workpool.o
LDFLAGS += -lpthread -lm
MACROS = ../../../null_macros/c.m4.null.pthread
M4FLAGS = -Uindex -Ulen

x = *

ifdef version
  ifeq "$(version)" "IN_PARSEC"
    PREFIX=${PARSECDIR}/ext/splash2/apps/${TARGET}/inst/${PARSECPLAT}
    MACROS = ../../../../null_macros/c.m4.null.pthread
  endif
endif

$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(TARGET) $(LDFLAGS)

install:
	mkdir -p $(PREFIX)/bin
	cp -f $(TARGET) $(PREFIX)/bin/$(TARGET)
	cp -f run.sh $(PREFIX)/bin/run.sh

clean:
	rm -rf *.c *.h *.o $(TARGET)

.SUFFIXES:
.SUFFIXES: .o .c .C .h .H

.H.h:
	$(M4) $(M4FLAGS) $(MACROS) $*.H > $*.h

.C.c:
	$(M4) $(MACROS) $*.C > $*.c

.c.o:
	$(CC) -c $(CFLAGS) $*.c

.C.o:
	$(M4) $(MACROS) $*.C > $*.c
	$(CC) -c $(CFLAGS) $*.c

bbox.c: bbox.C rt.h
cr.c:	cr.C rt.h
env.c:	env.C rt.h
fbuf.c: fbuf.C rt.h
geo.c:	geo.C rt.h
huprn.c: huprn.C rt.h
husetup.c: husetup.C rt.h
hutv.c: hutv.C rt.h
isect.c: isect.C rt.h
main.c: main.C rt.h
matrix.c: matrix.C rt.h
memory.c: memory.C rt.h
poly.c: poly.C rt.h
raystack.c: raystack.C rt.h
shade.c: shade.C rt.h
sph.c:	sph.C rt.h
trace.c: trace.C rt.h
tri.c:	tri.C rt.h
workpool.c: workpool.C rt.h
