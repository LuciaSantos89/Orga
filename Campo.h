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

	bool setNombre();
    string getNombre();
	bool setTipo();
	int getTipo();
	bool setSize();
	int getSize();
	bool setSize_d();
	int getSize_d();
	bool setKey();
	bool getKey();


	/* data */
};

#endif

