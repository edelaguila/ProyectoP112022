#ifndef MENUS_H
#define MENUS_H


class menus
{
    public:
        menus();
        virtual ~menus();
        menuGeneral();
        menuConsultas();
        menuContabilidad();
        menuEmpleados();
        menuSeguridad();
        menuTransferencia();
        int opcion;
    protected:

    private:
};

#endif // MENUS_H
