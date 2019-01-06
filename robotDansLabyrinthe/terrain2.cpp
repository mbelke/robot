#include "terrain2.h"

     const int nombreDesColonnes = 20;
     const int nombreDesLignes = 20;
     char matrice[nombreDesColonnes][nombreDesLignes];

terrain2::terrain2()
{}

 void terrain2::initialiser()
 {

        for(int i = 0; i < nombreDesColonnes; i++){
        for(int j = 0; j < nombreDesLignes; j++){
            matrice[i][j]=1;
        }
    }
}


// les deux points doivent être sur une même "ligne"
//  et dessine un couloir
terrain2::dessinerLesLignes(unsigned char *data, unsigned long x1, unsigned long y1,unsigned long x2,
                            unsigned long y2, unsigned long ligne_size){

cout<<x1<<y1<<x2<<y2<<endl;

    unsigned long i;
    if (x1 == x2)
        {
             if (y1 > y2)
             for (i = y2; i < y1; i++)
                 //set(data,x1,i,1,67,188,ligne_size);
             else
             for (i = y1; i < y2; i++)
                // set(data,x1,i,1,67,188,ligne_size);
        }
    else    // y1==y2
        {
             if (x1 > x2)
             for (i = x2;  i < x1; i++)
                 //set(data,i,y1,1,67,188,ligne_size);
             else
             for (i = x1; i < x2; i++)
                 //set(data,i,y1,1,67,188,ligne_size);
        }
}

void terrain2::dessinerLabyrhinte(unsigned char *data, unsigned long departx, unsigned long departy, unsigned long coin1x,
                                  unsigned long coin1y, unsigned long coin2x, unsigned long coin2y, unsigned long ligne_size)
{


    // condition d'arrêt
    if ((ABS(coin1x-coin2x)>3) && (ABS(coin1y-coin2y)>3))
      {
        // on se déplace au milieu de la zone
        draw_line(data, departx, departy, (int)((coin1x+coin2x)/2), (int)((coin1y+coin2y)/2),ligne_size);
        if (departy==(int)((coin1y+coin2y)/2))
           {
               dessinerLabyrhinte(data,(int)((coin1x+coin2x)/2), (int)((coin1y+coin2y)/2), coin1x, coin1y, coin2x, (int)((coin1y+coin2y)/2), ligne_size);  //bas
               dessinerLabyrhinte(data,(int)((coin1x+coin2x)/2), (int)((coin1y+coin2y)/2), coin1x, (int)((coin1y+coin2y)/2), coin2x, coin2y, ligne_size);  // haut
           }
        else
           {
               dessinerLabyrhinte(data, (int)((coin1x+coin2x)/2), (int)((coin1y+coin2y)/2), coin1x, coin1y, (int)((coin1x+coin2x)/2), coin2y, ligne_size);  //gauche
               dessinerLabyrhinte(data, (int)((coin1x+coin2x)/2), (int)((coin1y+coin2y)/2), (int)((coin1x+coin2x)/2), coin1y, coin2x, coin2y, ligne_size);  //droite
           }
      }
}


