#ifndef DECLARA_BOTAO_H
#define DECLARA_BOTAO_H
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>
#include <windows.h>
#include <dirent.h>
#include <fstream>
#include "struct.h"

using namespace std;


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
//SOM

    Botao->Bsom.textura_vol0=CarregaImagem("vol_0.bmp",render);
    Botao->Bsom.textura_vol1=CarregaImagem("vol_1.bmp",render);
    Botao->Bsom.textura_vol2=CarregaImagem("vol_2.bmp",render);
    Botao->Bsom.textura_vol3=CarregaImagem("vol_3.bmp",render);
    Botao->Bsom.origem.x=0;
    Botao->Bsom.origem.y=0;
    Botao->Bsom.origem.h=980;
    Botao->Bsom.origem.w=980;
    Botao->Bsom.destino.x=180;
    Botao->Bsom.destino.y=540;
    Botao->Bsom.destino.h=40;
    Botao->Bsom.destino.w=40;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//RANDOM
    Botao->Brandom.textura_normal=CarregaImagem("random.bmp",render);
    Botao->Brandom.textura_clique=CarregaImagem("random_clique.bmp",render);
    Botao->Brandom.origem.x=0;
    Botao->Brandom.origem.y=0;
    Botao->Brandom.origem.h=980;
    Botao->Brandom.origem.w=980;
    Botao->Brandom.destino.x=320;
    Botao->Brandom.destino.y=540;
    Botao->Brandom.destino.h=40;
    Botao->Brandom.destino.w=40;


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//REPEAT
    Botao->Brepeat.textura_normal=CarregaImagem("repeat.bmp",render);
    Botao->Brepeat.textura_clique=CarregaImagem("repeat_clique.bmp",render);
    Botao->Brepeat.origem.x=0;
    Botao->Brepeat.origem.y=0;
    Botao->Brepeat.origem.h=980;
    Botao->Brepeat.origem.w=980;
    Botao->Brepeat.destino.x=40;
    Botao->Brepeat.destino.y=540;
    Botao->Brepeat.destino.h=40;
    Botao->Brepeat.destino.w=40;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//PLAY
    Botao->Bplay.textura_normal=CarregaImagem("play.bmp",render);

    Botao->Bplay.origem.x=0;
    Botao->Bplay.origem.y=0;
    Botao->Bplay.origem.h=980;
    Botao->Bplay.origem.w=980;
    Botao->Bplay.destino.x=160;
    Botao->Bplay.destino.y=440;
    Botao->Bplay.destino.h=80;
    Botao->Bplay.destino.w=80;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//RETURN
    Botao->Breturn.textura_normal=CarregaImagem("return.bmp",render);
    Botao->Breturn.origem.x=0;
    Botao->Breturn.origem.y=0;
    Botao->Breturn.origem.h=900;
    Botao->Breturn.origem.w=900;
    Botao->Breturn.destino.x=70;
    Botao->Breturn.destino.y=450;
    Botao->Breturn.destino.h=60;
    Botao->Breturn.destino.w=60;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//PAUSE
    Botao->Bpause.textura_normal=CarregaImagem("pause.bmp",render);
    Botao->Bpause.origem.x=0;
    Botao->Bpause.origem.y=0;
    Botao->Bpause.origem.h=900;
    Botao->Bpause.origem.w=900;
    Botao->Bpause.destino.x=160;
    Botao->Bpause.destino.y=440;
    Botao->Bpause.destino.h=80;
    Botao->Bpause.destino.w=80;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//SKIP
    Botao->Bskip.textura_normal=CarregaImagem("skip.bmp",render);
    Botao->Bskip.origem.x=0;
    Botao->Bskip.origem.y=0;
    Botao->Bskip.origem.h=900;
    Botao->Bskip.origem.w=900;
    Botao->Bskip.destino.x=270;
    Botao->Bskip.destino.y=450;
    Botao->Bskip.destino.h=60;
    Botao->Bskip.destino.w=60;

}

void Carrega_Album(Imagem *Foto_album,SDL_Renderer* render){
    
    Foto_album[0].Album=CarregaImagem("",render);
    Foto_album[0].origem={0,0,0,0};
    Foto_album[0].destino={0,0,0,0};
    
    Foto_album[1].Album=CarregaImagem("",render);
    Foto_album[1].origem={0,0,0,0};
    Foto_album[1].destino={0,0,0,0};
    
    Foto_album[2].Album=CarregaImagem("",render);
    Foto_album[2].origem={0,0,0,0};
    Foto_album[2].destino={0,0,0,0};
    
    Foto_album[3].Album=CarregaImagem("",render);
    Foto_album[3].origem={0,0,0,0};
    Foto_album[3].destino={0,0,0,0};
    
    Foto_album[4].Album=CarregaImagem("",render);
    Foto_album[4].origem={0,0,0,0};
    Foto_album[4].destino={0,0,0,0};
    
    Foto_album[5].Album=CarregaImagem("",render);
    Foto_album[5].origem={0,0,0,0};
    Foto_album[5].destino={0,0,0,0};
    
    Foto_album[6].Album=CarregaImagem("",render);
    Foto_album[6].origem={0,0,0,0};
    Foto_album[6].destino={0,0,0,0};
    
    Foto_album[7].Album=CarregaImagem("",render);
    Foto_album[7].origem={0,0,0,0};
    Foto_album[7].destino={0,0,0,0};
    
    Foto_album[8].Album=CarregaImagem("",render);
    Foto_album[8].origem={0,0,0,0};
    Foto_album[8].destino={0,0,0,0};
    
    Foto_album[9].Album=CarregaImagem("",render);
    Foto_album[9].origem={0,0,0,0};
    Foto_album[9].destino={0,0,0,0};
    
    
    
}






#endif // DECLARA_BOTAO_H
