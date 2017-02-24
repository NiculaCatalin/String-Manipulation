build-t1: task1.o
		gcc task1.c -o task1
build-t2: task2.o
		gcc task2.c -o task2
run-t1:
		./task1
run-t2:
		./task2
clean:
		rm -f task1 task2 