sims : sims.o print.o config.o 

sims.o : sims.c

config.o : config.c

print.o : print.c

.PHONY : clean
clean : 
	rm sims sims.o print.o config.o
