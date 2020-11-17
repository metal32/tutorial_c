OBJS	= copy_and_idiom.o
SOURCE	= copy_and_idiom.cpp
HEADER	= 
OUT	= a.out
CC	 = g++
FLAGS	 = -g -c -Wall -fno-elide-constructors
LFLAGS	 = 

all: $(OBJS)
	$(CC) -g $(OBJS) -o $(OUT) $(LFLAGS)

copy_and_idiom.o: copy_and_idiom.cpp
	$(CC) $(FLAGS) copy_and_idiom.cpp -std=c11


clean:
	rm -f $(OBJS) $(OUT)