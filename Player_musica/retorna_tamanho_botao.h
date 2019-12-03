#ifndef RETORNA_TAMANHO_BOTAO_H
#define RETORNA_TAMANHO_BOTAO_H

#include "declara_botao.h"


void Normaliza_botoes(botoes *Botao){
    Botao->Bsom.destino.x=180;
    Botao->Bsom.destino.y=540;
    Botao->Bsom.destino.h=40;
    Botao->Bsom.destino.w=40;

    Botao->Brandom.destino.x=320;
    Botao->Brandom.destino.y=540;
    Botao->Brandom.destino.h=40;
    Botao->Brandom.destino.w=40;

    Botao->Brepeat.destino.x=40;
    Botao->Brepeat.destino.y=540;
    Botao->Brepeat.destino.h=40;
    Botao->Brepeat.destino.w=40;

    Botao->Bplay.destino.x=160;
    Botao->Bplay.destino.y=440;
    Botao->Bplay.destino.h=80;
    Botao->Bplay.destino.w=80;

    Botao->Breturn.destino.x=60;
    Botao->Breturn.destino.y=440;
    Botao->Breturn.destino.h=80;
    Botao->Breturn.destino.w=80;


    Botao->Bpause.destino.x=160;
    Botao->Bpause.destino.y=440;
    Botao->Bpause.destino.h=80;
    Botao->Bpause.destino.w=80;

    Botao->Bskip.destino.x=260;
    Botao->Bskip.destino.y=440;
    Botao->Bskip.destino.h=80;
    Botao->Bskip.destino.w=80;

}

#endif // RETORNA_TAMANHO_BOTAO_H
