#ifndef BANCO_H
#define BANCO_H


using namespace std;


class Banco
{
    public:

        Banco();

        virtual ~Banco();
        void menu();
		void insert();
		void display();
		void modify();
		void search();
		void delet();




    protected:

    private:
};

#endif // BANCO_H
