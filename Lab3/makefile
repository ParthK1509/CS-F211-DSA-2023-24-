runStackWithArray: stackDriver.o stack_array.o
	gcc -o runStackWithArray stackDriver.o stack_array.o
	./runStackWithArray

runStackWithll: stackDriver.o stack_ll.o linked_list.o
	gcc -o runStackWithll stackDriver.o stack_ll.o linked_list.o
	./runStackWithll
	
stackDriver.o: stackDriver.c stack.h
	gcc -c stackDriver.c

stack_array.o: stack_array.c stack.h
	gcc -c stack_array.c

stack_ll.o: stack_ll.c stack.h linked_list.h
	gcc -c stack_ll.c

linked_list.o: linked_list.c element.h linked_list.h
	gcc -c linked_list.c

clean:
	rm -f *.o runStackWithArray
	rm -f *.o runStackWithll
