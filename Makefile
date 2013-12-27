CC		= gcc
CFLAGS		= -Wall -g -D_GNU_SOURCE
DEST		= .
OBJS		= tsc_checker.o
PROGRAM		= tsc_checker

all:		$(PROGRAM)
$(PROGRAM):	$(OBJS)
		$(CC) $(OBJS) -o $(PROGRAM)
clean:;		rm -f *.o *~ $(PROGRAM)
