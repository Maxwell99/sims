sims: sims.o print.o config.o login.o

sims.o: sims.c

config.o: config.c

print.o: print.c

login.o: login.c

.PHONY: clean

clean: 
	rm sims *.o
