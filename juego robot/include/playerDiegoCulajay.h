#ifndef PLAYERDIEGOCULAJAY_H
#define PLAYERDIEGOCULAJAY_H

// Encabezado que define toda la funcionabilidad del Jugador
class playerDiegoCulajay
{
    public:
        playerDiegoCulajay();
        int lastX, lastY;
        virtual ~playerDiegoCulajay();
        void callInput();
        int getValueX();
        void setValueX(int valueX);
        int getValueY();
        void setValueY(int valueY);
        void resetToSafePosition();
        void drawCreditos();

    protected:

    private:
        int x, y;

};

#endif // PLAYERDIEGOCULAJAY_H
