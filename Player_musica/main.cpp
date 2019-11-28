#include "declara_botao.h"
#include "verifica_cliques_botoes.h"
#include "manipula_arquivo.h"

using namespace std;
#undef main



void musicFinished()
{
printf("Music stopped.\n");
acabou =true;
}





int main()
{
botoes Botao;
int x,y;





 SDL_Init(SDL_INIT_EVERYTHING);
 SDL_Window* janela =SDL_CreateWindow("Player",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,600,0);
 SDL_Renderer* render= SDL_CreateRenderer(janela,-1,0);
 SDL_SetRenderDrawColor(render,255,255,255,0);


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


musica= Mix_LoadMUS(local[0].c_str());

 closedir(dir);
int aux=0;
//Mix_PlayChannel(-1,som,0);
Mix_PlayMusic(musica,0);

while(1){
    //cout<<Mix_PlayingMusic()<<endl;

    SDL_RenderClear(render);


    SDL_RenderCopy(render,Botao.Bskip.textura_normal,&Botao.Bskip.origem,&Botao.Bskip.destino);
    SDL_RenderCopy(render,Botao.Breturn.textura_normal,&Botao.Breturn.origem,&Botao.Breturn.destino);
    Alterna_Botao(&Botao,render);




    SDL_Event evento;
    while(SDL_PollEvent(&evento)){
    switch (evento.type) {
        case SDL_QUIT:


                    break;


    case SDL_MOUSEBUTTONUP:
        Botao.Brandom.destino.x=470;
        Botao.Brandom.destino.y=500;
        Botao.Brandom.destino.h=60;
        Botao.Brandom.destino.w=60;

        Botao.Brepeat.destino.x=270;
        Botao.Brepeat.destino.y=500;
        Botao.Brepeat.destino.h=60;
        Botao.Brepeat.destino.w=60;

        Botao.Bskip.destino.x=560;
        Botao.Bskip.destino.y=440;
        Botao.Bskip.destino.h=80;
        Botao.Bskip.destino.w=80;


        Botao.Breturn.destino.x=160;
        Botao.Breturn.destino.y=440;
        Botao.Breturn.destino.h=80;
        Botao.Breturn.destino.w=80;
        break;
                  case SDL_MOUSEBUTTONDOWN:

                      SDL_GetMouseState(&x,&y);

                      aux=Verifica(&Botao,x,y,local,aux,render,Tamanho);
                      cout<<"retornando aux verifica: "<<aux<<endl;

                        break;
                        }
                }

    Mix_HookMusicFinished(musicFinished);

    if((acabou==true&&repeat==false)||(Mix_PlayingMusic()==0&&repeat==false)){
        aux=Acao_Skip(&Botao,render,aux,Tamanho,local);
        acabou =false;
    }


    SDL_RenderPresent(render);


    }








    Mix_CloseAudio();
    //Mix_FreeChunk(som);
    Mix_FreeMusic(musica);
//https://www.onlinewebfonts.com/icon/packs_1469
}
