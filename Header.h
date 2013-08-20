#ifndef HEADER_H
#define HEADER_H

#include "TDAFile.h"
#include "Campo.h"
#include <sstream>
#include<string.h>
#include <stdlib.h>

class Header
{
public:
    Header();
    bool agregarCampo(Campo*);
    vector<Campo*> getCampos();
    string guardarCampos();
    string guardarAvailList();
    void recuperarCampos(char*);

private:
    vector<Campo*> C;
    vector<int> AvailList;
};

#endif // HEADER_H
