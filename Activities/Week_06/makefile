MAIN = main
TAD = vector

all:
	gcc -c ${TAD}_TAD.c
	gcc ${MAIN}.c ${TAD}_TAD.o -o ${MAIN}

run:
	./${MAIN}
	rm *.o
	rm ${MAIN}

