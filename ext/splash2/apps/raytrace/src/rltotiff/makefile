TARGET = rltotiff

TIFF_LIBDIR = ./libtiff
TIFF_INCDIR = ./libtiff
OBJS = rltotiff.o tiff_rgba_io.o
LDFLAGS += -L$(TIFF_LIBDIR) -lc_s -ltiff
CFLAGS += -I$(TIFF_INCDIR)

x = *

ifdef version
  ifeq "$(version)" "IN_PARSEC"
    PREFIX=${PARSECDIR}/ext/splash2/apps/${TARGET}/inst/${PARSECPLAT}
    MACROS = ../../../../null_macros/c.m4.null.pthread
  endif
endif

$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(TARGET) $(LDFLAGS)

.SUFFIXES:
.SUFFIXES: .o .c

.c.o:
	$(CC) -c $(CFLAGS) $*.c
