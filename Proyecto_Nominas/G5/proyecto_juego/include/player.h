#ifndef PLAYER_H
#define PLAYER_H

// Encabezado que define toda la funcionabilidad del Jugador
class player//grupo
{
    public:
        player();
        int lastX, lastY;
        virtual ~player();
        void callInput();
        int getValueX();
        void setValueX(int valueX);
        int getValueY();
        void setValueY(int valueY);
        void resetToSafePosition();
        void drawCreditos();//Abigail Vasquez 9959-21-13777

    protected:

    private:
        int x, y;

};

#endif // PLAYER_H
