#ifndef VERIFICA_CLIQUES_BOTOES_H
#define VERIFICA_CLIQUES_BOTOES_H
#include <SDL2/SDL.h>
#include <iostream>
#include "declara_botao.h"
#include <SDL2/SDL_mixer.h>


#include <cstdlib>
#include <ctime>

using namespace std;


struct Musica{
     Mix_Music *audio;
     bool tocando = true;
     bool acabou = false;
     bool repeat = false;
     bool random = false;
};





int Random(int Tamanho){
    srand((unsigned)time(0));
    int x;
    x=(rand()%Tamanho);
    cout<<x<<endl;
    return x;
}



int Musica_aleatoria(int aux,int Tamanho, string* local, Musica *musica){
    aux=Random(Tamanho);
    Mix_FreeMusic(musica->audio);
    musica->audio= Mix_LoadMUS(local[aux].c_str());
    Mix_PlayMusic(musica->audio,0);
    musica->acabou =false;

    cout << "aux no if de random: "<<aux<<endl;

    return aux;

}


void Alterna_Botao(botoes *Botao,SDL_Renderer*render,Musica *musica){
    if(!musica->random)
        SDL_RenderCopy(render,Botao->Brandom.textura_normal,&Botao->Brandom.origem,&Botao->Brandom.destino);

    else
        SDL_RenderCopy(render,Botao->Brandom.textura_clique,&Botao->Brandom.origem,&Botao->Brandom.destino);

     if(!musica->repeat)
         SDL_RenderCopy(render,Botao->Brepeat.textura_normal,&Botao->Brepeat.origem,&Botao->Brepeat.destino);

     else
         SDL_RenderCopy(render,Botao->Brepeat.textura_clique,&Botao->Brepeat.origem,&Botao->Brepeat.destino);

     if(musica->tocando)
         SDL_RenderCopy(render,Botao->Bpause.textura_normal,&Botao->Bpause.origem,&Botao->Bpause.destino);

     else
         SDL_RenderCopy(render,Botao->Bplay.textura_normal,&Botao->Bplay.origem,&Botao->Bplay.destino);

}

void Acao_Random(botoes *Botao,SDL_Renderer *render,int *aux,int Tamanho,string* local,Musica *musica){
    Botao->Brandom.destino.x=480;
    Botao->Brandom.destino.y=520;
    Botao->Brandom.destino.h=40;
    Botao->Brandom.destino.w=40;
     if(musica->random){
         Alterna_Botao(Botao,render,musica);
            musica->random=false;
        }
     else
        {
         Alterna_Botao(Botao,render,musica);
            *aux=Random(Tamanho);
         cout<<"aux random"<<endl<<*aux<<endl<<endl<<endl;
            musica->audio= Mix_LoadMUS(local[*aux].c_str());
            Mix_PlayMusic(musica->audio,0);
            musica->random=true;
        }
}




void Acao_Repeat(botoes *Botao,SDL_Renderer *render,int *aux,string* local, Musica *musica){

    Botao->Brepeat.destino.x=290;
    Botao->Brepeat.destino.y=520;
    Botao->Brepeat.destino.h=40;
    Botao->Brepeat.destino.w=40;
    if(musica->repeat)
    {
        Alterna_Botao(Botao,render,musica);
        musica->audio= Mix_LoadMUS(local[*aux].c_str());
        Mix_PlayMusic(musica->audio,0);
        musica->repeat=false;
    }
    else
    {
        Alterna_Botao(Botao,render,musica);

        musica->audio= Mix_LoadMUS(local[*aux].c_str());
        Mix_PlayMusic(musica->audio,-1);
        musica->repeat=true;
    }
}

int Acao_Skip(botoes *Botao,SDL_Renderer *render,int aux,int Tamanho,string* local, Musica *musica){
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
    Mix_FreeMusic(musica->audio);
    musica->audio= Mix_LoadMUS(local[aux].c_str());
    Mix_PlayMusic(musica->audio,0);
return aux;
}

int Acao_Return(botoes *Botao,SDL_Renderer *render,int aux,int Tamanho,string* local, Musica *musica){
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
    Mix_FreeMusic(musica->audio);
    musica->audio= Mix_LoadMUS(local[aux].c_str());
    Mix_PlayMusic(musica->audio,0);
    return aux;
}

void Acao_Pause(Musica *musica){
    if(musica->tocando==false){
        Mix_ResumeMusic();
        musica->tocando=true;
    }
    else{
        Mix_PauseMusic();
        musica->tocando=false;
    }
}


int Verifica(botoes* Botao,int x,int y,string* local,int aux,SDL_Renderer* render, int Tamanho,Musica *musica){
    cout <<"X:" <<x<<" Y:" << y << endl;

    if(musica->random){
        if(x>=Botao->Bskip.destino.x&&x<=Botao->Bskip.destino.x+Botao->Bskip.destino.w&&y>=Botao->Bskip.destino.y&&y<=Botao->Bskip.destino.y+Botao->Bskip.destino.h)
            aux=Musica_aleatoria(aux,Tamanho,local,musica);

        else if(x>=Botao->Breturn.destino.x&&x<=Botao->Breturn.destino.x+Botao->Breturn.destino.w&&y>=Botao->Breturn.destino.y&&y<=Botao->Breturn.destino.y+Botao->Breturn.destino.h)
            aux=Musica_aleatoria(aux,Tamanho,local,musica);

        else if(x>=Botao->Brandom.destino.x&&x<=Botao->Brandom.destino.x+Botao->Brandom.destino.w&&y>=Botao->Brandom.destino.y&&y<=Botao->Brandom.destino.y+Botao->Brandom.destino.h)
                 Acao_Random(Botao,render,&aux,Tamanho,local,musica);

        else if(x>=Botao->Brepeat.destino.x&&x<=Botao->Brepeat.destino.x+Botao->Brepeat.destino.w&&y>=Botao->Brepeat.destino.y&&y<=Botao->Brepeat.destino.y+Botao->Brepeat.destino.h)
                Acao_Repeat(Botao,render,&aux,local,musica);

        else if (x>=Botao->Bpause.destino.x&&x<=Botao->Bpause.destino.x+Botao->Bpause.destino.w&&y>=Botao->Bpause.destino.y&&y<=Botao->Bpause.destino.y+Botao->Bpause.destino.h)
            Acao_Pause(musica);
        return aux;
        }

    else{
    if(x>=Botao->Bskip.destino.x&&x<=Botao->Bskip.destino.x+Botao->Bskip.destino.w&&y>=Botao->Bskip.destino.y&&y<=Botao->Bskip.destino.y+Botao->Bskip.destino.h)
        aux=Acao_Skip(Botao,render,aux,Tamanho,local,musica);

    else if (x>=Botao->Bpause.destino.x&&x<=Botao->Bpause.destino.x+Botao->Bpause.destino.w&&y>=Botao->Bpause.destino.y&&y<=Botao->Bpause.destino.y+Botao->Bpause.destino.h)
        Acao_Pause(musica);
    else if(x>=Botao->Breturn.destino.x&&x<=Botao->Breturn.destino.x+Botao->Breturn.destino.w&&y>=Botao->Breturn.destino.y&&y<=Botao->Breturn.destino.y+Botao->Breturn.destino.h)
      aux=Acao_Return(Botao,render,aux,Tamanho,local,musica);

    else if(x>=Botao->Brepeat.destino.x&&x<=Botao->Brepeat.destino.x+Botao->Brepeat.destino.w&&y>=Botao->Brepeat.destino.y&&y<=Botao->Brepeat.destino.y+Botao->Brepeat.destino.h)
        Acao_Repeat(Botao,render,&aux,local,musica);

   else if(x>=Botao->Brandom.destino.x&&x<=Botao->Brandom.destino.x+Botao->Brandom.destino.w&&y>=Botao->Brandom.destino.y&&y<=Botao->Brandom.destino.y+Botao->Brandom.destino.h)
            Acao_Random(Botao,render,&aux,Tamanho,local,musica);

    return aux;

}
}

#endif // VERIFICA_CLIQUES_BOTOES_H
