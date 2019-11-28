#ifndef VERIFICA_CLIQUES_BOTOES_H
#define VERIFICA_CLIQUES_BOTOES_H
#include <SDL2/SDL.h>
#include <iostream>
#include "declara_botao.h"
#include <SDL2/SDL_mixer.h>


#include <cstdlib>
#include <ctime>

using namespace std;


static Mix_Music *musica;
static bool tocando = true;
static bool acabou = false;
static bool repeat = false;
static bool random = false;


int Random(int Tamanho){
    srand((unsigned)time(0));
    int x;
    x=(rand()%Tamanho);
    cout<<x<<endl;
    return x;
}

int Verifica(botoes* Botao,int x,int y,string* local,int aux,SDL_Renderer* render, int Tamanho){
    cout <<"X:" <<x<<" Y:" << y << endl;
    if(x>=Botao->Bskip.destino.x&&x<=Botao->Bskip.destino.x+Botao->Bskip.destino.w&&y>=Botao->Bskip.destino.y&&y<=Botao->Bskip.destino.y+Botao->Bskip.destino.h){
            aux++;
            cout<<endl<<"aux:"<<aux;
            if(aux>=Tamanho){
            aux=0;
            }
            //cout<<local[aux]<<endl;
            Botao->Bskip.destino.x=580;
            Botao->Bskip.destino.y=460;
            Botao->Bskip.destino.h=40;
            Botao->Bskip.destino.w=40;
            Mix_FreeMusic(musica);
            musica= Mix_LoadMUS(local[aux].c_str());
            Mix_PlayMusic(musica,0);
            return aux;
    }
    else if (x>=Botao->Bpause.destino.x&&x<=Botao->Bpause.destino.x+Botao->Bpause.destino.w&&y>=Botao->Bpause.destino.y&&y<=Botao->Bpause.destino.y+Botao->Bpause.destino.h){

        if(tocando==false){
            Mix_ResumeMusic();
            tocando=true;

        }

        else{
            Mix_PauseMusic();
            tocando=false;

        }


    }
    else if(x>=Botao->Breturn.destino.x&&x<=Botao->Breturn.destino.x+Botao->Breturn.destino.w&&y>=Botao->Breturn.destino.y&&y<=Botao->Breturn.destino.y+Botao->Breturn.destino.h){
            aux--;
            cout<<endl<<"aux:"<<aux;
            if(aux<0){
            aux=Tamanho-1;
            }
            //cout<<local[aux]<<endl;
            Botao->Breturn.destino.x=180;
            Botao->Breturn.destino.y=460;
            Botao->Breturn.destino.h=40;
            Botao->Breturn.destino.w=40;
            Mix_FreeMusic(musica);
            musica= Mix_LoadMUS(local[aux].c_str());
            Mix_PlayMusic(musica,0);
            return aux;

    }
    else if(x>=Botao->Brepeat.destino.x&&x<=Botao->Brepeat.destino.x+Botao->Brepeat.destino.w&&y>=Botao->Brepeat.destino.y&&y<=Botao->Brepeat.destino.y+Botao->Brepeat.destino.h){

        if(repeat)
        {
            Botao->Brepeat.destino.x=290;
            Botao->Brepeat.destino.y=520;
            Botao->Brepeat.destino.h=40;
            Botao->Brepeat.destino.w=40;
            Botao->Brepeat.textura=CarregaImagem("repeat.bmp",render);
            musica= Mix_LoadMUS(local[aux].c_str());
            Mix_PlayMusic(musica,0);
            repeat=false;
        }
        else
        {
            Botao->Brepeat.destino.x=290;
            Botao->Brepeat.destino.y=520;
            Botao->Brepeat.destino.h=40;
            Botao->Brepeat.destino.w=40;
            Botao->Brepeat.textura=CarregaImagem("repeat_clique.bmp",render);
            musica= Mix_LoadMUS(local[aux].c_str());
            Mix_PlayMusic(musica,-1);
            repeat=true;
        }
        return aux;
}
    else if(x>=Botao->Brandom.destino.x&&x<=Botao->Brandom.destino.x+Botao->Brandom.destino.w&&y>=Botao->Brandom.destino.y&&y<=Botao->Brandom.destino.y+Botao->Brandom.destino.h){

         if(random){
                Botao->Brandom.destino.x=480;
                Botao->Brandom.destino.y=480;
                Botao->Brandom.destino.h=40;
                Botao->Brandom.destino.w=40;
                Botao->Brandom.textura=CarregaImagem("random.bmp",render);
                random=false;
            }
         else
            {
                Botao->Brandom.destino.x=480;
                Botao->Brandom.destino.y=480;
                Botao->Brandom.destino.h=40;
                Botao->Brandom.destino.w=40;
                Botao->Brandom.textura=CarregaImagem("random_clique.bmp",render);

                aux=Random(Tamanho);
             
                musica= Mix_LoadMUS(local[aux].c_str());
                Mix_PlayMusic(musica,0);
                random=true;
            }
        return aux;

    }



}

#endif // VERIFICA_CLIQUES_BOTOES_H
