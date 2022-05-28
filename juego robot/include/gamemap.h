#ifndef GAMEMAP_H
#define GAMEMAP_H
#include "mapcell.h"

class gamemap
{
    public:
        gamemap();
        mapcell* playerCell;
        mapcell cell [12][20];
        void draw();
        // método que obtiene las coordenadas del jugador y actualiza el mapa
        bool setPlayerCell(int playerX, int playerY);
        void drawPortada();
        void drawVictoria();
        void drawFinalA();
        void drawFinalB();
        void drawMuerte();
        void drawCasa();
        void drawPortadaDiego();
        virtual ~gamemap();
        bool isGameOver=false;
    protected:

    private:
        void loadMapFromFile();
        void loadMapFromFile2();
        void loadMapFromFile3();
        void createMapToFile();
};
#endif // GAMEMAP_H
