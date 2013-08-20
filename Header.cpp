#include "Header.h"

Header::Header()
{
}

bool Header::agregarCampo(Campo* ca){
    C.push_back(ca);
    cout<<"tamano "<<C.size()<<endl<<ca<<endl;
    int tam=C.size();
    for (int var = 0; var < tam; var++) {
        cout<<C.at(var)<<endl;
    }
    cout<<endl;
    return true;
}

vector <Campo*> Header::getCampos(){
    return C;
}

string Header::guardarCampos(){
    int camposNum=0;
    string camposLista="";
    camposNum=C.size();
    stringstream ss;
    ss<<camposNum;
    camposLista+=ss.str()+",";
    if(camposNum!=0){
        for (int i = 0; i < camposNum; ++i) {
            camposLista+=C.at(i)->getNombre()+",";
            ss.str("");
            ss<<C.at(i)->getTipo();
            camposLista+=ss.str()+",";
            ss.str("");
            ss<<C.at(i)->getSize();
            camposLista+=ss.str()+",";
            ss.str("");
            ss<<C.at(i)->getSize_d();
            camposLista+=ss.str()+",";
            ss.str("");
            ss<<C.at(i)->getKey();
            camposLista+=ss.str()+",";
        }
    }
    cout<<camposLista<<endl;
    camposLista+=guardarAvailList()+"\n";
    return camposLista;
}

string Header::guardarAvailList(){
    string avail="";
    int num=0;
    stringstream ss;
    if(AvailList.size()==0){
        ss<<-1;
    }
    else{
        num=AvailList.at(AvailList.size()-1);
        ss<<num;
    }
    avail=ss.str();
    ss.str("");
    return avail;
}

void Header::recuperarCampos(char* tmp){
    char* separado;
    separado=strtok(tmp,",");
    int numC=atoi((const char*)separado);

   for (int i = 0; i< numC ; i++) {
        separado=strtok(NULL,",");
        cout<<separado<<endl;
        separado=strtok(NULL,",");
        cout<<separado<<endl;
        separado=strtok(NULL,",");
        cout<<separado<<endl;
        separado=strtok(NULL,",");
        cout<<separado<<endl;
        separado=strtok(NULL,",");
        cout<<separado<<endl;
    }
   separado=strtok(NULL,",");
   int numAL=atoi((const char*)separado);
   cout<<"avai "<<numAL<<endl;
}
