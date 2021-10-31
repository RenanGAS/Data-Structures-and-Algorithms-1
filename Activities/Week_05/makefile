# Passo 4.3 - Automatizar a utilização do TAD

MAIN = main
TAD = timer

all:
	gcc -c ${TAD}_TAD.c
	gcc ${MAIN}.c ${TAD}_TAD.o -o ${MAIN}

run:
	./${MAIN}

clean:
	rm *.o
	rm ${MAIN}