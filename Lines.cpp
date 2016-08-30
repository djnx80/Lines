#include <iostream>
#include <allegro5/allegro_primitives.h>
#include "Lines.h"


using namespace std;

Lines::Lines()  {
    cout <<"idzie?"<<endl;
    ile = 0;
    xMax = 800;
    yMax = 600;
}
void Lines::init(int dlug, float xStart, float yStart, float dx, unsigned char rr, unsigned char gg, unsigned char bb)
{
 // iniciuj startowe pozycje, kolory i przyrost krokow
    xC = 400;
    yC = 300;
    dlugosc[ile] = dlug;
    X[ile] = xStart;
    Y[ile] = yStart;
    r[ile] = rr;
    g[ile] = gg;
    b[ile] = bb;
    dX[ile] = dx;

  //  if (xStart)

    ile++;

}

void Lines::rysujLinie() {
    // al_draw_line( x1, y1, x2, y2, kolor, szerokosc);
   //  al_draw_line( xC, yC, X[0], 0, al_map_rgba( 0, 255, 0, 128), 4);
     // al_draw_filled_triangle(x1,y1,x2,y2,x3,y3,kolor)
    float xS,yS,xK,yK, dl;

    for (int i=0; i<ile; i++)
    {
//        cout <<"i:"<<i<<"\n";

    xS = X[i];
    yS = Y[i];
    dl = dlugosc[i];

// linia na górze
    if (yS<=0 && (xS+dl)<=xMax)
    {
        xK = xS+dl;
        yK=yS;
    }
    if (yS<=0 && (xS+dl)>xMax)
    {
        xK = xMax;
        yK = dl - (xMax - xS);
    }

// linia po prawej
    if (yS>0 && xS>=xMax && (yS+dl)<=yMax)
    {
        xK = xMax;
        yK = yS + dl;
    }
    if (yS>0 && xS>=xMax && (yS+dl)>yMax)
    {
        xK = xMax - (dl - (yMax - yS));
        yK = yMax;
    }

// linia na dole
    if (yS>=yMax && (xS-dl)>=0)
    {
        xK = xS - dl;
        yK = yMax;
    }
    if (yS>=yMax && (xS-dl)<0)
    {
        xK = 0;
        yK = yMax - (dl-xS);
    }

// linia po lewej

    if (yS>0 && xS<=0 && (yS-dl)>=0)
    {
        xK = 0;
        yK = yS - dl;
    }
    if (yS>0 && xS<=0 && (yS-dl)<0)
    {
        xK = dl - yS;
        yK = 0;
    }


//cout <<"xs: "<<(int)xS<<" ys: "<<(int)yS<<" xK: "<<(int)xK<<" yK: "<<(int)yK<<"\n";
     al_draw_filled_triangle(xC, yC, xS, yS, xK, yK, al_map_rgba(r[i], g[i], b[i],60));
//      al_draw_line( xC, yC, xS, yS, al_map_rgba( 0, 255, 0, 128), 4);

    }

}

void Lines::ruszLinie() {
 //   cout <<ile;
    for (int i=0; i<ile; i++)
    {
    //    cout <<"x: "<<X[i]<<" y: "<<Y[i]<<"\n";

        if (X[i]<xMax && Y[i]==0)
        {
            X[i] = X[i] + dX[i];
        //    return;
        }
        if (X[i]>=xMax && Y[i]<yMax)
        {
            Y[i] = Y[i] + dX[i];
        //    return;
        }
        if (X[i]>=0 && Y[i]>=yMax)
        {
            X[i] = X[i] - dX[i];
         //   return;
        }
        if (X[i]<=0 && Y[i]>0)
        {
            Y[i] = Y[i] - dX[i];
          //  return;
        }

    }
}


