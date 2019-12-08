#include "declara_botao.h"
#include "verifica_cliques_botoes.h"
#include "manipula_arquivo.h"
#include "acao_botoes.h"
#include "retorna_tamanho_botao.h"


using namespace std;
#undef main



int main()
{
botoes Botao;
int x,y;

Musica musica;




 SDL_Init(SDL_INIT_EVERYTHING);
 SDL_Window* janela =SDL_CreateWindow("Player",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,400,600,0);
 SDL_Renderer* render= SDL_CreateRenderer(janela,-1,0);
 SDL_SetRenderDrawColor(render,0,0,0,0);


 SDL_Texture *fundo = CarregaImagem("fundoteste.bmp",render);

 SDL_Rect origemFundo = {0,0,400,600};
 SDL_Rect destinoFundo = {0,0,400,600};

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

while(1){

    SDL_RenderClear(render);

    SDL_RenderCopy(render,fundo,&origemFundo,&destinoFundo);
    SDL_RenderCopy(render,Botao.Bskip.textura_normal,&Botao.Bskip.origem,&Botao.Bskip.destino);
    SDL_RenderCopy(render,Botao.Breturn.textura_normal,&Botao.Breturn.origem,&Botao.Breturn.destino);
    Alterna_Botao(&Botao,render,&musica);


    SDL_Event evento;
    while(SDL_PollEvent(&evento))
    {
    switch (evento.type)
        {
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

    if((musica.acabou==true&&musica.repeat==false)||(Mix_PlayingMusic()==0&&musica.repeat==false)){
        aux=Acao_Skip(&Botao,render,aux,Tamanho,local,&musica);
        musica.acabou =false;
    }


    SDL_RenderPresent(render);


    }



    Mix_CloseAudio();
    //Mix_FreeChunk(som);
    Mix_FreeMusic(musica.audio);
}
