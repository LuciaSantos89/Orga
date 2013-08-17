#ifndef HEADERFILE_H
#define HEADERFILE_H

#include "TDAFile.h"
#include "Campo.h"
#include <sstream>

class HeaderFile
{
public:
    HeaderFile();
    bool agregarCampo(Campo*);
    vector<Campo*> getCampos();
    string guardarCampos();
    string guardarAvailList();
    void recuperarCampos();

private:
    vector<Campo*> C;
    vector<int> AvailList;
};

#endif // HEADERFILE_H
