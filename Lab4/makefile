task1 : task1exe
		./task1exe
task1exe : task1.o
		gcc -o task1exe task1.o
task1.o : task1.c
		gcc -c task1.c
task22 : task22exe
		./task22exe "dat1000.csv"
task22exe : task22.o
		gcc -o task22exe task22.o
task22.o : task22.c
		gcc -c task22.c
task4 : task4.o intMerge.o intMergeAuxRec.o
		gcc -o task4 task4.o intMerge.o intMergeAuxRec.o
		./task4 "dat1000.csv"
runWrec : task3.o intMerge.o intMergeAuxRec.o
		gcc -o runWrec task3.o intMerge.o intMergeAuxRec.o
		./runWrec "marks.txt"
runWiter : task3.o intMerge.o intMergeAuxRec.o
		gcc -o runWiter task3.o intMerge.o intMergeAuxRec.o
		./runWiter "marks.txt"
task3.o: task3.c intMerge.h intMergeAux.h
		gcc -c task3.c
intMerge.o: intMerge.c intMerge.h intMergeAux.h
		gcc -c intMerge.c
intMergeAuxRec.o: intMergeAuxRec.c intMerge.h intMergeAux.h
		gcc -c intMergeAuxRec.c
intMergeAuxIter.o: intMergeAuxIter.c intMerge.h intMergeAux.h
		gcc -c intMergeAuxIter.c
clean : 
	rm -f *.o
	rm task1exe
	rm task22exe
	rm task4
	rm runWrec
	rm runwiter
