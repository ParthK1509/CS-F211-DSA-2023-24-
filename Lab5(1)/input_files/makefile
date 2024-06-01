seq : seqexe
	./seqexe

seqexe : seq.o
	gcc -o seqexe seq.o

seq.o : seq.c
	gcc -c seq.c

matrix : matgenexe
	./matgenexe

matgenexe : matrix_generator.o
	gcc -o matgenexe matrix_generator.o

matrix_generator.o : matrix_generator.c
	gcc -c matrix_generator.c

clean :
	rm -f *.o
	rm seqexe
	rm matrix