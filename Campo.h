#ifndef CAMPO
#define CAMPO value

#include <vector>

#include <iostream>
#include <string>

using namespace std;

class Campo
{
private:
	static const int CHAR = 0;
	static const int INT = 1;
	static const int FLOAT = 2;

    string nombre;
	int tipo;
	int size;
	int size_dec;
	bool key;

public:
	Campo();
	~Campo();
    bool crearCampo(string,int,int,int,bool); //crea un campo
    //obtiene o modifica cada atributo de un campo

    bool setNombre(string);
    string getNombre();
    bool setTipo(int);
	int getTipo();
    bool setSize(int);
	int getSize();
    bool setSize_d(int);
	int getSize_d();
    bool setKey(bool);
	bool getKey();


	/* data */
};

#endif

