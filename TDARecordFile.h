#ifndef TDARECORDFILE
#define TDARECORDFILE

#include "Campo.h"
#include "TDAFile.h"
#include "Registro.h"
#include "Index.h"
#include <string>
#include <vector>
#include <stack>

using namespace::std;

class TDARecordFile:public TDAFile
{
public:
    TDARecordFile();
	~TDARecordFile();

    void getAvaillist();

    //Secuencial
    /*bool addRecord(vector <Campo*>,vector<string>);
    string* searchRecord(string);
	bool deleteRecord(int);
    string* listRecord(vector <Campo*>);*/

    //Indices Simples
    bool addRecord(Registro*,Index*);
    string* searchRecord(int);
    bool deleteRecord(int);
    vector<Registro*> listRecord(vector <Campo*>);

    //Indices Arbol B


private:
    stack<int> AvailList;
};
#endif
