#ifndef GAMEMAP_H
#define GAMEMAP_H
#include "mapcell.h"
// Encabezado que define toda la funcionabilidad del mapa del juego

class gamemap
{
    public:
        gamemap();
        mapcell* playerCell;
        mapcell cell [15][70];//Dimensiones nuevas del mapa, Carlos hernandez 9959-21-363.
        void draw();
        bool setPlayerCell(int playerX, int playerY);
        void drawPortada(); //Funcionalidad portada, Victor Jerez 9959-21-2081.
        void drawVictoria();//Funcionalidad premio, Victor Jerez 9959-21-2081.
        void drawDerrota();//Funcionalidad trampa, Salvador martinez 9959-21-4167.
        virtual ~gamemap();
        bool isGameOver = false;


    protected:

    private:
        void loadMapFromFile();
        void createMapToFile();
};

#endif // GAMEMAP_H
