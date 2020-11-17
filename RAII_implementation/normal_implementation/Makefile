OBJS	= move_semantics.o
SOURCE	= move_semantics.cpp
HEADER	= 
OUT	= a.out
CC	 = g++
FLAGS	 = -g -c -Wall -fno-elide-constructors
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

move_semantics.o: move_semantics.cpp
	$(CC) $(FLAGS) move_semantics.cpp -std=c11


clean:
	rm -f $(OBJS) $(OUT)