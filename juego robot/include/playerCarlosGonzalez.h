#ifndef PLAYERCARLOSGONZALEZ_H
#define PLAYERCARLOSGONZALEZ_H


class playerCarlosGonzalez
{
    public:
        playerCarlosGonzalez();
        virtual ~playerCarlosGonzalez();
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

#endif // PLAYERCARLOSGONZALEZ_H
