MAIN=main
TAD=timer_TAD

all:
	@echo "Compilando..."
	gcc -c $(TAD).c -o $(TAD).o
	gcc $(MAIN).c $(TAD).o -o $(MAIN)
	
run:
	./$(MAIN)

clean:
	rm *.o
	rm $(MAIN)