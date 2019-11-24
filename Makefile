#Makefile 
#define variables
objects= main.o segment_tree_iter.o segment_tree_cpu.o
GCC= gcc
LIBS=  -lm
execname= main
opt = -g

#compile
$(execname): $(objects)
	$(GCC) $(opt) -o $(execname) $(objects) $(LIBS) 

segment_tree_cpu.o : segment_tree_cpu.c 
	$(GCC) $(opt) -c segment_tree_cpu.c $(LIBS)
segment_tree_iter.o : segment_tree_iter.c 
	$(GCC) $(opt) -c segment_tree_iter.c $(LIBS)
main.o : main.c 
	$(GCC) $(opt) -c main.c $(LIBS)

#clean Makefile
clean:
	rm $(objects)
#end of Makefile