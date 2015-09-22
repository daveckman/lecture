.PHONY: test

LFLAGS=-std=c99 -lm 

test: workq
	./workq 4

workq: workq.o 
	$(CC) -o $@ $^ -lpthread -lm

%.o: %.c
	$(CC) -c -O3 $<

clean:
	rm -f *.o workq
