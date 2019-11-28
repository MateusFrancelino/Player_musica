#include "declara_botao.h"

using namespace std;
#undef main



Mix_Music *musica;
bool tocando = true;
bool acabou =false;
int repeat=2;

int Tamanho_array(){
    ifstream ler;
    string linha;
    int i=0;
    int g=0;
    ler.open("lista_musica.txt");
    if(ler.is_open()){
        while(getline(ler,linha)){
            if(g>2){
               i++;
               }
            else{g++;}
        }
    }cout<<endl<<endl<<endl<<endl<<endl;
    ler.close();
    return i;
    
    
    
}



void ler_playlist(string *local){
    ifstream ler;
    string linha;
    int i=0;
    int g=0;
    ler.open("lista_musica.txt");
    if(ler.is_open()){
        while(getline(ler,linha)){
            if(g>2){
                cout<<linha<<endl;
               local[i]=linha;
               i++;
               }
            else{g++;}
        }
    }cout<<endl<<endl<<endl<<endl<<endl;

}



int Verifica(botoes* Botao,int x,int y,string* local,int aux,SDL_Renderer* render){
    cout <<"X:" <<x<<" Y:" << y << endl;
    if(x>=Botao->Bskip.destino.x&&x<=Botao->Bskip.destino.x+Botao->Bskip.destino.w&&y>=Botao->Bskip.destino.y&&y<=Botao->Bskip.destino.y+Botao->Bskip.destino.h){
            aux++;
            cout<<endl<<"aux:"<<aux;
            if(aux>12){
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
            aux=11;
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

        repeat++;
        if(repeat%2==0)
        {
            Botao->Brepeat.destino.x=290;
            Botao->Brepeat.destino.y=520;
            Botao->Brepeat.destino.h=40;
            Botao->Brepeat.destino.w=40;
            Botao->Brepeat.textura=CarregaImagem("repeat.bmp",render);
            Mix_PlayMusic(musica,0);
        }
        else
        {
            Botao->Brepeat.destino.x=290;
            Botao->Brepeat.destino.y=520;
            Botao->Brepeat.destino.h=40;
            Botao->Brepeat.destino.w=40;
            Botao->Brepeat.textura=CarregaImagem("repeat_clique.bmp",render);
            //musica= Mix_LoadMUS(local[aux].c_str());
            Mix_PlayMusic(musica,-1);
        }
        return aux;
}
    else if(x>=Botao->Brandom.destino.x&&x<=Botao->Brandom.destino.x+Botao->Brandom.destino.w&&y>=Botao->Brandom.destino.y&&y<=Botao->Brandom.destino.y+Botao->Brandom.destino.h){
            Botao->Brandom.destino.x=480;
            Botao->Brandom.destino.y=480;
            Botao->Brandom.destino.h=40;
            Botao->Brandom.destino.w=40;
            Botao->Brandom.textura=CarregaImagem("random_clique.bmp",render);
    }

}



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

 SDL_Rect origem;
 SDL_Rect destino;

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



string local[11];
/*local[0]="C:/teste/athe-muffin-song-asdfmovie-feat-schmoyoho.mp3";
local[1]="C:/teste/camila-cabello-living-proof-live-from-the-2019-amas.mp3";
local[2]="C:/teste/i-like-trains-asdfmovie-song.mp3";
local[3]="C:/teste/shawn-mendes-camila-cabello-senorita-live-from-the-amas-2019.mp3";
// char *caminho="musica.mp3";*/
ler_playlist(local);

musica= Mix_LoadMUS(local[0].c_str());

 closedir(dir);
int aux=0;
//Mix_PlayChannel(-1,som,0);
Mix_PlayMusic(musica,0);
int z=0;

while(1){
    cout<<Mix_PlayingMusic()<<endl;

    SDL_RenderClear(render);
    if(tocando==true)
        SDL_RenderCopy(render,Botao.Bpause.textura,&Botao.Bpause.origem,&Botao.Bpause.destino);
    else
        SDL_RenderCopy(render,Botao.Bplay.textura,&Botao.Bplay.origem,&Botao.Bplay.destino);


    SDL_RenderCopy(render,Botao.Bskip.textura,&Botao.Bskip.origem,&Botao.Bskip.destino);
    SDL_RenderCopy(render,Botao.Breturn.textura,&Botao.Breturn.origem,&Botao.Breturn.destino);
    SDL_RenderCopy(render,Botao.Brepeat.textura,&Botao.Brepeat.origem,&Botao.Brepeat.destino);
    SDL_RenderCopy(render,Botao.Brandom.textura,&Botao.Brandom.origem,&Botao.Brandom.destino);
    SDL_RenderPresent(render);



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

                      aux=Verifica(&Botao,x,y,local,aux,render);
                      cout<<"retornando aux: "<<aux;
                      cout <<"X:" <<x<<" Y:" << y << endl;
  /*                    if(x>=Botao.Bskip.destino.x&&x<=Botao.Bskip.destino.x+Botao.Bskip.destino.w&&y>=Botao.Bskip.destino.y&&y<=Botao.Bskip.destino.y+Botao.Bskip.destino.h){
                          aux++;
                          if(aux>12){
                              aux=0;
                          }
                          //cout<<local[aux]<<endl;
                          musica= Mix_LoadMUS(local[aux].c_str());
                          Mix_PlayMusic(musica,0);
                      }
*/



                    break;

        }


}
Mix_HookMusicFinished(musicFinished);
if(acabou==true||Mix_PlayingMusic()==0){
    aux++;
    cout<<endl<<"aux:"<<aux;
    if(aux>12){
        aux=0;
    }

    Mix_FreeMusic(musica);
    musica= Mix_LoadMUS(local[aux].c_str());
    Mix_PlayMusic(musica,0);
    acabou =false;
}

}


 Mix_CloseAudio();
 //Mix_FreeChunk(som);
Mix_FreeMusic(musica);
//https://www.onlinewebfonts.com/icon/packs_1469
}
