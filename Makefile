output: shell.o read.o parsing.o pwd.o ls.o cd.o mkdir.o grep.o cat.o
	gcc shell.o read.o parsing.o pwd.o ls.o cd.o mkdir.o grep.o cat.o -o output
	
shell.o: shell.c
	gcc -c shell.c
	
read.o: read.c read.h
	gcc -c read.c

parsing.o: parsing.c parsing.h
	gcc -c parsing.c
	
pwd.o: pwd.c pwd.h
	gcc -c pwd.c

ls.o: ls.c ls.h
	gcc -c ls.c

cd.o: cd.c cd.h
	gcc -c cd.c

mkdir.o: mkdir.c mkdir.h
	gcc -c mkdir.c

grep.o: grep.c grep.h
	gcc -c grep.c

cat.o: cat.c cat.h
	gcc -c cat.c

clean:
	rm *.o output
