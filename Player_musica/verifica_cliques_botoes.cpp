#include "verifica_cliques_botoes.h"

int Verifica(botoes* Botao,int x,int y,string* local,int aux,SDL_Renderer* render, int Tamanho,Musica *musica){
    cout <<"X:" <<x<<" Y:" << y << endl;

    if((musica->random|| (musica->random&&musica->repeat))){
        if(x>=Botao->Bskip.destino.x&&x<=Botao->Bskip.destino.x+Botao->Bskip.destino.w&&y>=Botao->Bskip.destino.y&&y<=Botao->Bskip.destino.y+Botao->Bskip.destino.h)
            aux=Musica_aleatoria(Botao,aux,Tamanho,local,musica,1);

        else if(x>=Botao->Breturn.destino.x&&x<=Botao->Breturn.destino.x+Botao->Breturn.destino.w&&y>=Botao->Breturn.destino.y&&y<=Botao->Breturn.destino.y+Botao->Breturn.destino.h)
            aux=Musica_aleatoria(Botao,aux,Tamanho,local,musica,0);

        else if(x>=Botao->Brandom.destino.x&&x<=Botao->Brandom.destino.x+Botao->Brandom.destino.w&&y>=Botao->Brandom.destino.y&&y<=Botao->Brandom.destino.y+Botao->Brandom.destino.h)
                 Acao_Random(Botao,render,&aux,Tamanho,local,musica);

        else if(x>=Botao->Brepeat.destino.x&&x<=Botao->Brepeat.destino.x+Botao->Brepeat.destino.w&&y>=Botao->Brepeat.destino.y&&y<=Botao->Brepeat.destino.y+Botao->Brepeat.destino.h)
                Acao_Repeat(Botao,render,&aux,local,musica);

        else if (x>=Botao->Bpause.destino.x&&x<=Botao->Bpause.destino.x+Botao->Bpause.destino.w&&y>=Botao->Bpause.destino.y&&y<=Botao->Bpause.destino.y+Botao->Bpause.destino.h)
            Acao_Pause(musica);
        else if(x>=Botao->Bsom.destino.x&&x<=Botao->Bsom.destino.x+Botao->Bsom.destino.w&&y>=Botao->Bsom.destino.y&&y<=Botao->Bsom.destino.y+Botao->Bsom.destino.h)
            Acao_volume(Botao,musica);

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

   else if(x>=Botao->Bsom.destino.x&&x<=Botao->Bsom.destino.x+Botao->Bsom.destino.w&&y>=Botao->Bsom.destino.y&&y<=Botao->Bsom.destino.y+Botao->Bsom.destino.h)
        Acao_volume(Botao,musica);

    return aux;

}
}
