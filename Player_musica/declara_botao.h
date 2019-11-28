#ifndef DECLARA_BOTAO_H
#define DECLARA_BOTAO_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>
#include <windows.h>
#include <dirent.h>
#include <fstream>
using namespace std;

struct  botao{
    SDL_Rect origem;
    SDL_Rect destino;
    SDL_Texture* textura;



};
struct botoes{
    botao Bplay;
    botao Bskip;
    botao Breturn;
    botao Bpause;
    botao Brepeat;
    botao Brandom;
};


SDL_Texture *CarregaImagem(const char *imagem, SDL_Renderer* renderizador){
    SDL_Surface*img =SDL_LoadBMP(imagem);
    if (img==nullptr){
        //cout<<"Erro ao carregar imagem";
    }
    SDL_Texture*textura=SDL_CreateTextureFromSurface(renderizador,img);
    SDL_FreeSurface(img);
    return textura;
}

void Declarar_botoes(botoes*Botao,SDL_Renderer*render){

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///RANDOM
    Botao->Brandom.textura=CarregaImagem("random.bmp",render);
    Botao->Brandom.origem.x=0;
    Botao->Brandom.origem.y=0;
    Botao->Brandom.origem.h=980;
    Botao->Brandom.origem.w=980;
    Botao->Brandom.destino.x=470;
    Botao->Brandom.destino.y=500;
    Botao->Brandom.destino.h=60;
    Botao->Brandom.destino.w=60;


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//REPEAT
    Botao->Brepeat.textura=CarregaImagem("repeat.bmp",render);
    Botao->Brepeat.origem.x=0;
    Botao->Brepeat.origem.y=0;
    Botao->Brepeat.origem.h=980;
    Botao->Brepeat.origem.w=980;
    Botao->Brepeat.destino.x=270;
    Botao->Brepeat.destino.y=500;
    Botao->Brepeat.destino.h=60;
    Botao->Brepeat.destino.w=60;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//PLAY
    Botao->Bplay.textura=CarregaImagem("play.bmp",render);
    Botao->Bplay.origem.x=0;
    Botao->Bplay.origem.y=0;
    Botao->Bplay.origem.h=980;
    Botao->Bplay.origem.w=980;
    Botao->Bplay.destino.x=360;
    Botao->Bplay.destino.y=440;
    Botao->Bplay.destino.h=80;
    Botao->Bplay.destino.w=80;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//RETURN
    Botao->Breturn.textura=CarregaImagem("return.bmp",render);
    Botao->Breturn.origem.x=0;
    Botao->Breturn.origem.y=0;
    Botao->Breturn.origem.h=980;
    Botao->Breturn.origem.w=980;
    Botao->Breturn.destino.x=160;
    Botao->Breturn.destino.y=440;
    Botao->Breturn.destino.h=80;
    Botao->Breturn.destino.w=80;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//PAUSE
    Botao->Bpause.textura=CarregaImagem("pause.bmp",render);
    Botao->Bpause.origem.x=0;
    Botao->Bpause.origem.y=0;
    Botao->Bpause.origem.h=980;
    Botao->Bpause.origem.w=980;
    Botao->Bpause.destino.x=360;
    Botao->Bpause.destino.y=440;
    Botao->Bpause.destino.h=80;
    Botao->Bpause.destino.w=80;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//SKIP
    Botao->Bskip.textura=CarregaImagem("skip.bmp",render);
    Botao->Bskip.origem.x=0;
    Botao->Bskip.origem.y=0;
    Botao->Bskip.origem.h=980;
    Botao->Bskip.origem.w=980;
    Botao->Bskip.destino.x=560;
    Botao->Bskip.destino.y=440;
    Botao->Bskip.destino.h=80;
    Botao->Bskip.destino.w=80;

}
#endif // DECLARA_BOTAO_H
//
