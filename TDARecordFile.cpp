#include "TDARecordFile.h"

TDARecordFile::TDARecordFile()
{
}

TDARecordFile::~TDARecordFile()
{
}

bool TDARecordFile::addRecord(Registro* r, Index* i){
    string aGuardar=r->convertirAString();
    int tam=0;
    vector<Campo*> campos = r->getCampos();
    for (unsigned int i = 0; i < campos.size(); i++) {
        tam+=campos.at(i)->getLongitud();
    }
    int offset;
    if(AvailList.empty()){
        this->seek(0,ios_base::end);
    }
    else{
        offset=AvailList.top();
        AvailList.pop();
        this->seek(offset);
    }
    this->write(aGuardar.c_str(),tam);
    this->flush();
    string llave=r->campoLLave();
    cout<<llave<<endl;
    //i->agregarIndice(,offset);
    return true;
}
