bst : bstexe
	./bstexe
bstexe : bst.o
	gcc -o bstexe bst.o
bst.o : bst.c
	gcc -c bst.c
clean :
	rm -f *.o
	rm bstexe