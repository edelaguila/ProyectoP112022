#ifndef GAMEMAPCARLOSGONZALEZ_H
#define GAMEMAPCARLOSGONZALEZ_H
#include "mapcellCarlosGonzalez.h"

class gamemapCarlosGonzalez
{
    public:
        gamemapCarlosGonzalez();
        mapcellCarlosGonzalez* playerCell;
        mapcellCarlosGonzalez cell [12][20];
        void draw();
        // método que obtiene las coordenadas del jugador y actualiza el mapa
        bool setPlayerCell(int playerX, int playerY);
        void drawPortada();
        void drawVictoria();
        void drawFinalA();
        void drawFinalB();
        void drawMuerte();
        virtual ~gamemapCarlosGonzalez();
        bool isGameOver=false;
    protected:

    private:
        void loadMapFromFile();
        void createMapToFile();
};

#endif // GAMEMAPCARLOSGONZALEZ_H
