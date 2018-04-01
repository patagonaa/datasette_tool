COMPILER = gcc
CFLAGS = -Wall -Wextra -Wpedantic -std=c99

all: encoder.out decoder.out

# compile and generate dependency info
%.out: %.c
	$(COMPILER) $(CFLAGS) $*.c -o $*.out -lm

clean:
	find -name "*.o" -delete -o -name "*.out" -delete -o -name "*.d" -delete
