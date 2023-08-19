CC:= gcc
CFLAGS:= -O2 -g
LDFLAGS:= -lrt

all:	read write

read: 	read.c

write: 	write.c

.PHONY:	clean
clean:
	rm -f *.o read write /dev/shm/test
