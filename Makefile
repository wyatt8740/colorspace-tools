CC=gcc
CFLAGS=-Wall -Os -I.
LDFLAGS=-lm
TARGETS=cmy2cmyk cmy2rgb cmyk2rgb cmyk2cmy rgb2cmy rgb2cmyk

.PHONY : all clean strip

all: $(TARGETS)

clean:
	rm -f cmy2cmyk cmy2rgb cmyk2rgb cmyk2cmy rgb2cmy rgb2cmyk *.o

common.o: common.c common.h
	gcc $(CFLAGS) -c $< -o $@

cmy2cmyk: cmy2cmyk.c common.o
	gcc $(CFLAGS) -o $@ $^ $(LDFLAGS)

cmy2rgb: cmy2rgb.c common.o
	gcc $(CFLAGS) -o $@ $^ $(LDFLAGS)

cmyk2rgb: cmyk2rgb.c common.o
	gcc $(CFLAGS) -o $@ $^ $(LDFLAGS)

cmyk2cmy: cmyk2cmy.c common.o
	gcc $(CFLAGS) -o $@ $^ $(LDFLAGS)

rgb2cmy: rgb2cmy.c common.o
	gcc $(CFLAGS) -o $@ $^ $(LDFLAGS)

rgb2cmyk: rgb2cmyk.c common.o
	gcc $(CFLAGS) -o $@ $^ $(LDFLAGS)

strip: all
	strip -s $(TARGETS)
