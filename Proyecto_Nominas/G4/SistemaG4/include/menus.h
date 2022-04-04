#ifndef MENUS_H
#define MENUS_H
#include <string>
using namespace std;

class menus
{
    public:
        void menuPrincipal();
		void consultas();
		void contabilidad();
		void gestionEmpleados();
		void seguridad();
        menus();
        virtual ~menus();

    protected:

    private:
};

#endif // MENUS_H
