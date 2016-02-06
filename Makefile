sims : sims.o print_ui.o config.o 

sims.o : sims.c

config.o : config.c

print_ui.o : print_ui.c

.PHONY : clean
clean : 
	rm sims sims.o print_ui.o 
