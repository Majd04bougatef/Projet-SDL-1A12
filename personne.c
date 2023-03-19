#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <string.h>
#include "personne.h"

void initPerso(personne *p)
{
    printf("test de double changement");
    p->sprite = IMG_Load("perso 2.png");
    if (p->sprite == NULL)
    {
        printf("Unable to load background image %s \n", SDL_GetError());
        return;
    }
    p->posSprite.x = 0;
    p->posSprite.y = 0;
    p->posSprite.w = 840 / 8;
    p->posSprite.h = 400 / 2;
    p->posScreen.x = 100;
    p->posScreen.y = 550;
    p->vitesse=5; 
    p->acceleration=0;

    p->saut.x = -50;
    p->saut.y = 0;
    p->position_saut = 450;
    p->up = 0;
}

void initPerso_stop(personne *p)
{
    p->sprite = IMG_Load("perso 2.png");
    if (p->sprite == NULL)
    {
        printf("Unable to load background image %s \n", SDL_GetError());
        return;
    }
    p->posSprite.x = 0;
    p->posSprite.y = 0;
    p->posSprite.w = 840 / 8;
    p->posSprite.h = 400 / 2;
    p->posScreen.x = 550;
    p->posScreen.y = 100;
}

void initPerso_stop_left(personne *p)
{

    p->sprite = IMG_Load("perso 2 gauche.png");
    if (p->sprite == NULL)
    {
        printf("Unable to load background image %s \n", SDL_GetError());
        return;
    }
    p->posSprite.x = 0;
    p->posSprite.y = 200;
    p->posSprite.w = 480 / 8;
    p->posSprite.h = 80 / 1;
}
void afficherPerso(personne p, SDL_Surface *screen)
{
    SDL_BlitSurface(p.sprite, &p.posSprite, screen, &p.posScreen);
}

void movePerso(personne *p)
{
}
void animerPerso(personne *p)
{
    if (p->posSprite.x == 840 - p->posSprite.w)
    {
        p->posSprite.x = 0;
    }
    else
    {
        p->posSprite.x = p->posSprite.x + p->posSprite.w;
    }
    p->posSprite.y = p->direction * p->posSprite.h;
}
void saut(personne *p)
{
     for (int i = 0; i <= 100; i++)
        {
            p->posScreen.y -= 1;
        }  

}

void down(personne *p)
{
    for (int i = 0; i <= 10; i++)
        {
            p->posScreen.y += 1;
        }   

}


