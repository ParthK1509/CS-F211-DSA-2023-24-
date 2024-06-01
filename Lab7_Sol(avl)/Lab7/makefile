debugbst : bst.out
	gdb bst.out
bst : bstexe
	./bstexe
bst.out: bst.c
	gcc bst.c -o bst.out -g
bstexe : bst.o
	gcc -o bstexe bst.o
bst.o : bst.c
	gcc -c bst.c
clean :
	rm -f *.o
	rm bstexe