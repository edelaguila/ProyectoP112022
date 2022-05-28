#ifndef PLAYER_H
#define PLAYER_H


class player
{
    public:
        player();
        virtual ~player();
        int lastX, lastY;
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

#endif // PLAYER_H
