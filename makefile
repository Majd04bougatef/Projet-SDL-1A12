programme :main.o personne.o 
	gcc main.o personne.o  -o programme -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
main.o:main.c
	gcc -c main.c -g -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf
personne.o:personne.c
	gcc -c personne.c -g -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf

	

