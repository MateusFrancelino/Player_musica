#ifndef VERIFICA_CLIQUES_BOTOES_H
#define VERIFICA_CLIQUES_BOTOES_H
#include <SDL2/SDL.h>
#include <iostream>
#include <SDL2/SDL_mixer.h>
#include "acao_botoes.h"

#include "struct.h"


#include <cstdlib>
#include <ctime>

using namespace std;

int Verifica(botoes* Botao,int x,int y,string* local,int aux,SDL_Renderer* render, int Tamanho,Musica *musica);

#endif // VERIFICA_CLIQUES_BOTOES_H
