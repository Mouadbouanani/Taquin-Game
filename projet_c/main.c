#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include"constant.h"
#include"functions.h"

int main(int argc, char *argv[])
{

    SDL_Window *Window=NULL;
    SDL_Renderer *renderer=NULL;

    if(0!=SDL_Init(SDL_INIT_VIDEO))
         {
           fprintf(stderr,"ERREUR SDL_Init %s",SDL_GetError());
           return EXIT_FAILURE;
         }
       //Creation de Window
       Window= SDL_CreateWindow("Taquin",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,600,600,SDL_WINDOW_SHOWN);
    if(Window==NULL)
       {
          SDL_ExiTWithError("impossible de cree la fenetre:");
       }
       //Creation de renderer
       renderer=SDL_CreateRenderer(Window,-1,SDL_RENDERER_ACCELERATED);
    if( renderer==NULL)
         {
            SDL_ExiTWithError("impossible de cree  le renderer:");
         }
    // Creation des textures
        SDL_Texture *texture1=NULL ,*texture2=NULL ,*texture3=NULL , *texture4=NULL ,*texture5=NULL , *affich_textur=NULL;

        SDL_Surface *surface;
          surface=SDL_LoadBMP("images/inteface/1.bmp");  ///C:\Users\MOUAD\Desktop\projet_c\images\inteface
    if(surface==NULL)
          {
             SDL_ExiTWithError("Erreur  au niveau de creation image 1:");
          }
        texture1=SDL_CreateTextureFromSurface(renderer,surface);
        //Free surface
        SDL_FreeSurface(surface);
        surface=SDL_LoadBMP("images/inteface/2.bmp");

    if(surface==NULL)
          {
             SDL_ExiTWithError("Erreur  au niveau de creation image 2:");
          }
       texture2=SDL_CreateTextureFromSurface(renderer,surface);
          //Free surface
       SDL_FreeSurface(surface);
       surface=SDL_LoadBMP("images/inteface/3.bmp");
    if(surface==NULL)
          {
             SDL_ExiTWithError("Erreur  au niveau de creation image 3:");
          }
          texture3=SDL_CreateTextureFromSurface(renderer,surface);
          SDL_FreeSurface(surface);
          surface=SDL_LoadBMP("images/inteface/4.bmp");
    if(surface==NULL)
          {
             SDL_ExiTWithError("Erreur  au niveau de creation image 4:");
          }
          texture4=SDL_CreateTextureFromSurface(renderer,surface);
          SDL_FreeSurface(surface);
          surface=SDL_LoadBMP("images/inteface/5.bmp");
    if(surface==NULL)
          {
             SDL_ExiTWithError("Erreur  au niveau de creation image 5:");
          }
          texture5=SDL_CreateTextureFromSurface(renderer,surface);
          SDL_FreeSurface(surface);

    int nbr_img=0;

    affich_textur =texture1;


/*..............................................................................*/

    SDL_bool execution=SDL_TRUE;

    while(execution)
    {
        SDL_Event event;
        while(SDL_PollEvent(&event))
          {
            if(event.type==SDL_QUIT)
                execution=SDL_FALSE;
            else if (event.type==SDL_KEYDOWN)
             {
                if(event.key.keysym.sym==SDLK_RIGHT)
                {
                   nbr_img++ ;
                   if(nbr_img<4)
                    {
                     if(nbr_img==0)
                        affich_textur=texture1;
                    else if(nbr_img==1)
                        affich_textur=texture2;
                    else if(nbr_img==2)
                        affich_textur=texture3;
                    else if(nbr_img==3)
                        affich_textur=texture4;
                   }else break;

                 }else if(event.key.keysym.sym==SDLK_LEFT)
                   {
                   nbr_img-- ;
                   if(nbr_img<4)
                    {
                    if(nbr_img==0)
                        affich_textur=texture1;
                    else if(nbr_img==1)
                        affich_textur=texture2;
                    else if(nbr_img==2)
                        affich_textur=texture3;
                    else if(nbr_img==3)
                        affich_textur=texture4;
                   }else break;

                   }else if(event.key.keysym.sym==SDLK_n)
                   {
                       affich_textur=texture4;
                   }else if(event.key.keysym.sym==SDLK_f)
                   {
                       execution=SDL_FALSE;
                   }
                   else if(affich_textur==texture4)
                   {
                       if(event.key.keysym.sym==SDLK_3)
                       {
                           board_size=3;
                           //affect_image_texture();
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
                                //Itialisation de board d une maniere ordonnee
                                initialiser_board();
                                //Faire des permutations pour desodonnee le board
                                permutations_aleatoires();
                                //Liberer la texture
                                affich_textur=NULL;
                       }else if(event.key.keysym.sym==SDLK_4)
                       {
                           board_size=4;
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
                                //Itialisation de board d une maniere ordonnee
                                initialiser_board();
                                //Faire des permutations pour desodonnee le board
                                permutations_aleatoires();
                                //Liberer la texture
                                affich_textur=NULL;
                       }
                   }
                }else if(event.type==SDL_MOUSEBUTTONDOWN)
                 {
                    int x = event.motion.x/(600/board_size);
                    int y = event.motion.y/(600/board_size);

                 if (x-1 >=0 && board[x-1][y]==0)
                    {
                      if (board[x-1][y]==0)
                        {
                            board[x-1][y]=board[x][y];
                            board[x][y]=0;
                        }
                   }else if (x+1 <= board_size-1 && board[x+1][y]==0)
                  {
                      if (board[x+1][y]==0)
                        {
                            board[x+1][y]=board[x][y];
                            board[x][y]=0;
                        }
                  } else if (y-1>=0 && board[x][y-1]==0)
                     {
                      if (board[x][y-1]==0)
                         {
                            board[x][y-1]=board[x][y];
                            board[x][y]=0;
                         }
                }else if (y+1<=board_size-1 && board[x][y+1]==0)
                {
                    if (board[x][y+1]==0)
                        {
                            board[x][y+1]=board[x][y];
                            board[x][y]=0;
                        }
                }
              }
            }
            // clear renderer
            SDL_RenderClear(renderer);
            if(affich_textur==NULL)
            {
               // affect();
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
                        SDL_SetRenderDrawColor(renderer,153,102,0,255);
                        SDL_Rect rect={pos_x,pos_y,side,side};
                        if(valeur==0)
                           {
                               SDL_RenderFillRect(renderer,&rect);
                           }

                        else  // affect l'image on nomber correspandante
                           {
                               SDL_RenderCopy(renderer,side_textures[valeur-1],NULL,&rect);
                           }
                        SDL_SetRenderDrawColor(renderer,200,200,200 ,255);
                        SDL_RenderDrawRect(renderer,&rect);
                      }
                }
                if(check_win())
                   {
                        affich_textur=texture5;
                   }
               }else
                   {
                        SDL_RenderCopy(renderer,affich_textur, NULL, NULL);
                   }

         SDL_RenderPresent(renderer);

    }
    // Free the textures
    SDL_DestroyTexture(texture1);
    SDL_DestroyTexture(texture2);
    SDL_DestroyTexture(texture3);
    SDL_DestroyTexture(texture4);
    int i;
    for ( i = 0; i < board_size * board_size - 1; i++)
    {
        SDL_DestroyTexture(side_textures[i]);
    }
/*............................................................................*/
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(Window);
        SDL_Quit();
        return 0;
}
