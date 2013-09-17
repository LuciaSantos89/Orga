#ifndef INDEX_H
#define INDEX_H

#include <string>
#include <map>

using namespace::std;

class Index
{
public:
    Index();
    ~Index();
    bool agregarIndice(string,int);
    int getOffset(string);
    void cambiarIndice(string,string);
    bool verificarIndice(string);

private:
    string pkey;
    int offset;
    map <string,int> indices;
};

#endif // INDEX_H
