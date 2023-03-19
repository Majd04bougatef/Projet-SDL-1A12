#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include "personne.h"

int main(int argc, char **argv)
{
    printf(" test du mon jeu");
    Uint32 t_prev ,dt;
    int frame=0,aux;
    int continuer = 1;
    int x,y;
    SDL_Surface *back = NULL;
    SDL_Rect posback;
    personne p;
    SDL_Event event;
    SDL_Surface *ecran = NULL;
    if (SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO | SDL_INIT_TIMER) == -1)
    {
        printf("Could not initialisze SDL : %s .\n", SDL_GetError());
        return -1;
    }

    ecran = SDL_SetVideoMode(SCREEN_W, SCREEN_H, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

    SDL_WM_SetCaption("JEU", NULL);
    back = IMG_Load("Sans titre-1.png");
    posback.x = 0;
    posback.y = 0;
    initPerso(&p);

    SDL_EnableKeyRepeat(5, 5);
    
    while (continuer)
    {
        t_prev=SDL_GetTicks();
        frame++;
        SDL_BlitSurface(back, NULL, ecran, &posback);
        
        afficherPerso(p, ecran);
        p.direction = -1;
        while (SDL_PollEvent(&event))
        {

            switch (event.type)
            {
            case (SDL_KEYDOWN):
                switch (event.key.keysym.sym)
                {
                case (SDLK_ESCAPE):
                    continuer = 0;
                    break;
                case (SDLK_RIGHT):
                    p.direction = 0;
                    afficherPerso (p,ecran);
                    break;
                case (SDLK_LEFT):
                    p.direction = 1;
                    afficherPerso (p,ecran);
                    break;

                case (SDLK_UP):
                    p.up=1;
                    aux=p.posScreen.y;
                    saut (&p);
                    afficherPerso (p,ecran);
                    
                    p.posScreen.y=aux;
                    break;

                case (SDLK_DOWN):
                    p.up=0;
                    down (&p);
                    afficherPerso (p,ecran);
                    break;
                }

                break;

            case (SDL_KEYUP):
                switch (event.key.keysym.sym)
                {

                case (SDLK_RIGHT):

                    //initPerso_stop(&p);
                    //afficherPerso(p, ecran);
                    break;
                case (SDLK_LEFT):

                    //initPerso_stop_left(&p);
                    //afficherPerso(p, ecran);
                    
                    break;

                case (SDLK_UP):
                    /*p.up=0;
                    down (&p);
                    afficherPerso (p,ecran);*/
                    
                    break;

                
                }

                break;
            }
        }
        if (p.direction == 0 || p.direction == 1)
        {
            if (p.direction == 0)
            {
                p.posScreen.x += 5;
            }
            
            else
            {
                p.posScreen.x -= 5;
            }
            
            
            

            
            animerPerso(&p);
        }

        SDL_Flip(ecran);
        dt=SDL_GetTicks()-t_prev;
    }

    SDL_Quit();
    return EXIT_SUCCESS;
}