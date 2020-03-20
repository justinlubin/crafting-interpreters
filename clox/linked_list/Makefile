src = $(wildcard *.c)
obj = $(src:.c=.o)

CFLAGS = -g -Wall
LDFLAGS = -lm

main: $(obj)
	$(CC) -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(obj) main
