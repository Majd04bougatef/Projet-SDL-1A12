#ifndef PERSONNE_H
#define PERSONNE_H
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_getenv.h>
#define SCREEN_W 1600
#define SCREEN_H 750


typedef struct {
    SDL_Surface *sprite;
    SDL_Rect posScreen;
    SDL_Rect posSprite;
    int direction;
    SDL_Rect posScreenAbs;
    int up;
    int position_saut;
    SDL_Rect saut;
    double vitesse , acceleration;

}personne;

void initPerso(personne *p);
void afficherPerso(personne p, SDL_Surface * screen);
void movePerso(personne *p);
void animerPerso(personne* p);
void saut(personne* p);
void down (personne *p);
void initPerso_stop (personne * p);
void initPerso_stop_left (personne *p);
#endif