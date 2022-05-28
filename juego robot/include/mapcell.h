#ifndef MAPCELL_H
#define MAPCELL_H


class mapcell
{
    public:
        mapcell();
        char id;
        bool isBlockedCell();
        virtual ~mapcell();

    protected:

    private:
};

#endif // MAPCELL_H
