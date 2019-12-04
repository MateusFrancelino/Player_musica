#ifndef STRUCT_H
#define STRUCT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
struct Musica{
     Mix_Music *audio;
     bool tocando = true;
     bool acabou = false;
     bool repeat = false;
     bool random = false;
     bool som=true;
};



struct  botao{
    SDL_Rect origem;
    SDL_Rect destino;
    SDL_Texture* textura_normal;
    SDL_Texture* textura_clique;



};
struct botao_som{
    SDL_Rect origem;
    SDL_Rect destino;
    SDL_Texture* textura_vol0;
    SDL_Texture* textura_vol1;
    SDL_Texture* textura_vol2;
    SDL_Texture* textura_vol3;
    int volume=3;


};

struct botoes{
    botao Bplay;
    botao Bskip;
    botao Breturn;
    botao Bpause;
    botao Brepeat;
    botao Brandom;
    botao_som Bsom;
};
#endif // STRUCT_H
