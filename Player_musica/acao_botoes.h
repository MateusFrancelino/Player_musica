#ifndef ACAO_BOTOES_H
#define ACAO_BOTOES_H
#include <SDL2/SDL.h>
#include <iostream>
#include "struct.h"
#include <SDL2/SDL_mixer.h>


#include <cstdlib>
#include <ctime>

using namespace std;

int Random(int Tamanho);

void Alterna_Botao(botoes *Botao,SDL_Renderer*render,Musica *musica);

void Acao_Repeat(botoes *Botao,SDL_Renderer *render,int *aux,string* local, Musica *musica);

int Acao_Skip(botoes *Botao,SDL_Renderer *render,int aux,int Tamanho,string* local, Musica *musica);

int Acao_Return(botoes *Botao,SDL_Renderer *render,int aux,int Tamanho,string* local, Musica *musica);

void Acao_Pause(Musica *musica);

void Acao_volume(botoes *Botao,Musica* musica);

int Musica_aleatoria(botoes *Botao,int aux,int Tamanho, string* local, Musica *musica,int i);

void Acao_Random(botoes *Botao,SDL_Renderer *render,int *aux,int Tamanho,string* local,Musica *musica);

#endif // ACAO_BOTOES_H
