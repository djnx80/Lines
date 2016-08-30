// kolorowe linie
//#include <stdio.h>

#include <iostream>
#include <cstdlib>
#include <math.h>
#include "allegro5/allegro.h"
#include <allegro5/allegro_primitives.h>
#include "allegro5/allegro_image.h"
#include "allegroStart.h"
#include <stdio.h>      /* printf */
#include <math.h>       /* sin */
#include <string>
#include "Lines.h"

#define PI 3.14159265

using namespace std;

allegroStart mA(800,600);
ALLEGRO_DISPLAY *okno = mA.openWindow();
ALLEGRO_BITMAP  *bitmapa = mA.openBitmap(800,600);
ALLEGRO_BITMAP  *bitmapa1 = mA.openBitmap(800,600);
ALLEGRO_BITMAP  *bitmapa2 = mA.openBitmap(800,600);
ALLEGRO_KEYBOARD_STATE klawisz;
ALLEGRO_LOCKED_REGION *lr;
unsigned char *ptr;

void *__gxx_personality_v0;


int main()
{

    bitmapa1 = al_load_bitmap("fotka.bmp");
  //  al_draw_bitmap(bitmapa_tlo,0,0,0);
  cout <<"www"<<endl;
    Lines linia;
       //init(int dlug, float xStart, float yStart, float dx, float dy, unsigned char rr, unsigned char gg, unsigned char bb)
///*
    linia.init(200, 0, 0, 10, 200, 200, 200);
    linia.init(200, 200, 0, 20, 200, 0, 100);
    linia.init(200, 400, 0, 15, 100, 50, 150);
    linia.init(200, 600, 0, 20, 100, 0, 0);

    linia.init(200, 800, 0, 10, 200, 50, 150);
    linia.init(200, 800, 200, 20, 20, 50, 150);
    linia.init(200, 800, 400, 10, 200, 50, 50);

    linia.init(300, 800, 600, 15, 20, 150, 50);
    linia.init(300, 500, 600, 20, 250, 0, 0);
    linia.init(200, 200, 600, 10, 0, 250, 0);

    linia.init(200, 0, 600, 15, 0, 0, 250);
    linia.init(200, 0, 400, 10, 0, 120, 250);
    linia.init(200, 0, 200, 20, 160, 0, 250);
//*/
/*
    linia.init(200, 0, 0, 10, 200, 200, 200);
    linia.init(200, 200, 0, 10, 200, 0, 100);
    linia.init(200, 400, 0, 10, 100, 50, 150);
    linia.init(200, 600, 0, 10, 100, 0, 0);

    linia.init(200, 800, 0, 10, 200, 50, 150);
    linia.init(200, 800, 200, 10, 20, 50, 150);
    linia.init(200, 800, 400, 10, 200, 50, 50);

    linia.init(300, 800, 600, 10, 20, 150, 50);
    linia.init(300, 500, 600, 10, 250, 0, 0);
    linia.init(200, 200, 600, 10, 0, 250, 0);

    linia.init(200, 0, 600, 10, 0, 0, 250);
    linia.init(200, 0, 400, 10, 0, 120, 250);
    linia.init(200, 0, 200, 10, 160, 0, 250);

*/

cout <<"Start"<<endl;
    while( !al_key_down( & klawisz, ALLEGRO_KEY_ESCAPE ) )    {

        lr = al_lock_bitmap(bitmapa, ALLEGRO_PIXEL_FORMAT_ABGR_8888, ALLEGRO_LOCK_WRITEONLY);
        ptr = (unsigned char *)lr->data;

        al_draw_tinted_bitmap(bitmapa1,al_map_rgba(255,255,255,120),0,0,0);

        linia.rysujLinie();
        linia.ruszLinie();

        al_draw_bitmap(bitmapa,0,0,0);
        al_unlock_bitmap(bitmapa);

        al_flip_display();
        al_get_keyboard_state( & klawisz );
        al_rest(0.04);
        }

	return 0;
}


