#ifndef GAMEMAPDIEGOCULAJAY_H
#define GAMEMAPDIEGOCULAJAY_H
#include "mapcellDiegoCulajay.h"
// Encabezado que define toda la funcionabilidad del mapa del juego

class gamemapDiegoCulajay
{
    public:
        gamemapDiegoCulajay();
        mapcellDiegoCulajay* playerCell;
        mapcellDiegoCulajay cell [15][10];
        void draw();
        // método que obtiene las coordenadas del jugador y actualiza el mapa
        bool setPlayerCell(int playerX, int playerY);
        void drawPortada();
        void drawVictoria();
        virtual ~gamemapDiegoCulajay();
        bool isGameOver = false;


    protected:

    private:
        void loadMapFromFile();
        void createMapToFile();
};

#endif // GAMEMAPDIEGOCULAJAY_H
