#include "declara_botao.h"
#include "verifica_cliques_botoes.h"
#include "manipula_arquivo.h"
#include "acao_botoes.h"
#include "retorna_tamanho_botao.h"
#include <SDL2/SDL_ttf.h>


using namespace std;
#undef main



/*void musicFinished(Musica *musica)
{
printf("Music stopped.\n");
musica- >acabou =true;
}*/





int main()
{
botoes Botao;
int x,y;

Musica musica;




 SDL_Init(SDL_INIT_EVERYTHING);
 SDL_Window* janela =SDL_CreateWindow("Player",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,400,600,0);
 SDL_Renderer* render= SDL_CreateRenderer(janela,-1,0);
 SDL_SetRenderDrawColor(render,255,0,255,0);


 /*TTF_Init();
 TTF_Font *fonte = TTF_OpenFont("CURVE-Thin.ttf",12);
 SDL_Color corFonte = {255,255,0,0};
 SDL_Color corFundo = {255,0,0,0};
 SDL_Surface *text = TTF_RenderText_Shaded(fonte,"oi",corFonte,corFundo);
 SDL_Texture* texto =SDL_CreateTextureFromSurface(render,text);
 SDL_Rect localTexto = {150,250,0,0};
*/

Declarar_botoes(&Botao,render);













 int frequencia = 22050;
 Uint16 formato = AUDIO_S16SYS;
 int canal = 2;//1 mono 2 stereo
 int buffer = 4096;

 Mix_OpenAudio(frequencia,formato,canal,buffer);//inicia o audio
 //Mix_Chunk *som;// para efeitos
 // para musicas


 //som= Mix_LoadWAV("Pow.wav");


 DIR* dir;
 struct dirent *lsdir;
 dir= opendir("C:\\teste");
 fstream arquivosom;
 if(!arquivosom.is_open()){
     arquivosom.open("lista_musica.txt",std::fstream::out);
 }
 while ((lsdir=readdir(dir))!=NULL)
 {


     cout<<endl<<lsdir->d_name;
     arquivosom<<endl<<"C:/teste/"<<lsdir->d_name;

 }

 int Tamanho = Tamanho_array();
 string *local= new string [Tamanho];
 ler_playlist(local);


musica.audio= Mix_LoadMUS(local[0].c_str());

 closedir(dir);
int aux=0;
//Mix_PlayChannel(-1,som,0);
Mix_PlayMusic(musica.audio,0);
SDL_Rect origem;
SDL_Rect destino;
origem.x=0;
origem.y=0;
origem.h=598;
origem.w=403;
destino.x=0;
destino.y=0;
destino.w=400;
destino.h=600;
//SDL_Texture *coisa=CarregaImagem("1",render);



while(1){




    //cout<<Mix_PlayingMusic()<<endl;


















   // SDL_BlitSurface(texto,NULL,janela,&localTexto);
    //SDL_Flip(janela);





    SDL_RenderClear(render);

    //SDL_RenderCopy(render,texto,NULL,&localTexto);

    SDL_RenderCopy(render,Botao.Bskip.textura_normal,&Botao.Bskip.origem,&Botao.Bskip.destino);
    SDL_RenderCopy(render,Botao.Breturn.textura_normal,&Botao.Breturn.origem,&Botao.Breturn.destino);
    Alterna_Botao(&Botao,render,&musica);




    SDL_Event evento;
    while(SDL_PollEvent(&evento)){
    switch (evento.type) {
        case SDL_QUIT:


                    break;


    case SDL_MOUSEBUTTONUP:

         Normaliza_botoes(&Botao);









        break;
                  case SDL_MOUSEBUTTONDOWN:

                      SDL_GetMouseState(&x,&y);

                      aux=Verifica(&Botao,x,y,local,aux,render,Tamanho,&musica);
                      cout<<"retornando aux verifica: "<<aux<<endl;

                        break;
                        }
                }

    //Mix_HookMusicFinished(musicFinished);

    if((musica.acabou==true&&musica.repeat==false)||(Mix_PlayingMusic()==0&&musica.repeat==false)){
        aux=Acao_Skip(&Botao,render,aux,Tamanho,local,&musica);
        musica.acabou =false;
    }



    SDL_RenderPresent(render);


    }








    Mix_CloseAudio();
    //Mix_FreeChunk(som);
    Mix_FreeMusic(musica.audio);
//https://www.onlinewebfonts.com/icon/packs_1469         https://www.libsdl.org/projects/SDL_ttf/
}
