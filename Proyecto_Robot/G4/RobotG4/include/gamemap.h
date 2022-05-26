#ifndef GAMEMAP_H
#define GAMEMAP_H
#include "mapcell.h"
// Encabezado que define toda la funcionabilidad del mapa del juego

class gamemap
{
    public:
        gamemap();
        mapcell* playerCell;
        mapcell cell [15][30];
        gamemap2();
        gamemap3();
        gamemap4();
        void draw();
        void draw2();
        void draw3();
        void draw4();
        // método que obtiene las coordenadas del jugador y actualiza el mapa
        bool setPlayerCell(int playerX, int playerY);
        bool setPlayerCell2(int playerX2, int playerY2);
        bool setPlayerCell3(int playerX3, int playerY3);
        bool setPlayerCell4(int playerX4, int playerY4);
        void drawPortada();
        void drawPortada2();
        void drawPortada3();
        void drawPortada4();
        void drawVictoria();
        void drawVictoria2();
        void drawVictoria3();
        void drawVictoria4();
        virtual ~gamemap();
        int opcion = 0;
        bool isGameOver = false;



    protected:

    private:
        void loadMapFromFile();
        void createMapToFile();
        void loadMapFromFile2();
        void loadMapFromFile3();
        void loadMapFromFile4();
        void createMapToFile2();
        void createMapToFile3();
        void createMapToFile4();
};

#endif // GAMEMAP_H

