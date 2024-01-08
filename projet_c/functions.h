#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED
#include<SDL2/SDL.h>

void SDL_ExiTWithError(const char *message)
{
    SDL_Log("ERREUR: %s > %s\n",message,SDL_GetError());
    SDL_Quit();
    exit(EXIT_FAILURE);
}
/******************************/
void affect_image_texture()
{
     int i;
     char pas_image[40];
     for(i=0;i<board_size*board_size -1;i++)
     {
        sprintf(pas_image,"images/numbers/N%d.bmp",i+1);
        SDL_Surface* surface=SDL_LoadBMP(pas_image);
        if(surface==NULL)
         {
            fprintf(stderr,"Errur de creation de %s:%s",pas_image,SDL_GetError());
            exit(EXIT_FAILURE);
         }
        side_textures[i]=SDL_CreateTextureFromSurface(renderer,surface);
        SDL_FreeSurface(surface);
     }
    // affect nomber 0 dans  la dernier carree
     side_textures[(board_size*board_size)-1]=NULL;
}
/****************************************/
void permutations_aleatoires()
 {
     int pos_i_0=board_size-1;
     int pos_j_0=board_size-1;
    // Initialiser le g�n�rateur de nombres al�atoires avec une graine diff�rente � chaque ex�cution
    srand(time(NULL));
    int nombreAleatoire;
    // G�n�rer et afficher un nombre al�atoire entre 1 et 4
    int k;
    for ( k=0;k<500;k++){
       nombreAleatoire = rand() % 4 + 1;
       int intermedier;
       if (nombreAleatoire==1 && pos_i_0>0)
        {
           //vers le haut
           intermedier=board[pos_i_0][pos_j_0];
           board[pos_i_0][pos_j_0]=board[pos_i_0-1][pos_j_0];
           board[pos_i_0-1][pos_j_0]=intermedier;
           pos_i_0=pos_i_0-1;
       } else if (nombreAleatoire==2 && pos_i_0<board_size-1){
           //vers le bas
           intermedier=board[pos_i_0][pos_j_0];
           board[pos_i_0][pos_j_0]=board[pos_i_0+1][pos_j_0];
           board[pos_i_0+1][pos_j_0]=intermedier;
           pos_i_0=pos_i_0+1;
       } else if (nombreAleatoire==3 && pos_j_0<board_size-1){
           //vers le droit
           intermedier=board[pos_i_0][pos_j_0];
           board[pos_i_0][pos_j_0]=board[pos_i_0][pos_j_0+1];
           board[pos_i_0][pos_j_0+1]=intermedier;
           pos_j_0=pos_j_0+1;
       } else if (nombreAleatoire==4 && pos_j_0>0){
           //vers le gauche
           intermedier=board[pos_i_0][pos_j_0];
           board[pos_i_0][pos_j_0]=board[pos_i_0][pos_j_0-1];
           board[pos_i_0][pos_j_0-1]=intermedier;
           pos_j_0=pos_j_0-1;
       }
    }
}
/*******************/
void initialiser_board(){
    int i,j;
    for ( i = 0; i < board_size; i++) {
        for ( j = 0; j < board_size; j++) {
            board[j][i] = i * board_size + j + 1;
        }
    }
    board[board_size-1][board_size-1]=0;
}
/************************/
void affect(){

   int i,j,valeur;
   int side=(600/board_size);

   for(i=0;i<board_size;i++)
   {
       for(j=0;j<board_size;j++)
       {
           int valeur=board[i][j];
           // position of number in bord
           int pos_x=i*side;
           int pos_y=j*side;
           SDL_SetRenderDrawColor(renderer,255,255,255,255);
           SDL_Rect rect={pos_x,pos_y,side,side};
           if(valeur==0)
           {
               SDL_RenderFillRect(renderer,&rect);
           }

           else  // affect l'image on nomber correspandante
           {
               SDL_RenderCopy(renderer,side_textures[valeur-1],NULL,&rect);
           }
            SDL_SetRenderDrawColor(renderer,102,51,0,255);
            SDL_RenderDrawRect(renderer,&rect);
       }

   }

}

/********************************/
int check_win()
{
    int valur=1;
    int i,j;
    for(i=0;i<board_size ;i++)
    {
        for(j=0;j<board_size;j++)
        {
            if(board[j][i]!=valur &&(i!=board_size - 1 || j!=board_size - 1 ))
                return 0;
                valur++;
        }
    }
    return 1 ;
}




#endif // FUNCTIONS_H_INCLUDED
