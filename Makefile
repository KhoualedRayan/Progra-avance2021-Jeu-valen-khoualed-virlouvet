CFLAGS = -O3 `sdl2-config --cflags`
LDFLAGS = `sdl2-config --libs` -lSDL2_ttf -lm 

INC = sdl2-light.h constante.h world.h graphisme.h sdl2-ttf-light.h eventsMain.h
SRC = main.c sdl2-light.c world.c graphisme.c sdl2-ttf-light.c eventsMain.c
OBJ = $(SRC:%.c=%.o)

PROG = jeu

%.o: %.c $(INC)
	gcc $(CFLAGS) -c $<

jeu: $(OBJ)
	gcc $(CFLAGS) $(OBJ) $(LDFLAGS) -o $@

doc: $(PROG)
	doxygen ./$(PROG)
	make -C latex

clean:
	rm -f *~ *.o $(PROG)
	rm -rf latex html

