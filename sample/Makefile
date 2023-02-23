CC = gcc
CFLAGS = -Wall -I../src
OBJS = main.o tfd_interval_timer.o
VPATH = ../src
EXE = a.out


all: $(EXE)

$(EXE): $(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(EXE)

clean:
	rm -f *.o *~ $(EXE)
