CC=gcc

CFLAGS=-c -Wall -std=c99

LDFLAGS=-lreadline

SRCS=main.c enter.c write.c edit.c check.c fill.c chooser.c QuickSort.c

OBJS=$(SRCS:.c=.o)

EXE=lab5

all: $(SRCS) $(EXE)

$(EXE): $(OBJS)
	$(CC) $(LDFLAGS) $(OBJS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf $(OBJS) $(EXE)
		
