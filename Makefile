GCC=gcc
GCCFLAGS= -g -std=c99 #-Wall -Werror

%.o: %.c
	$(GCC) -c $(GCCFLAGS) $<

all: main.o Products.o
	$(GCC) -o main main.o Products.o
	
clean:
	rm *.o main