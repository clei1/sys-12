all: fork.c
	gcc fork.c

run: a.out
	./a.out

clean:
	rm *~
	rm *.out
