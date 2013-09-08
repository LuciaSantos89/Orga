#include "Campo.h"

Campo::Campo(){

}

bool Campo::crearCampo(string n, int t, int s, int s_dec, bool k){
	this->nombre=n;
	this->tipo=t;
	this->size=s;
	this->size_dec=s_dec;
	this->key=k;
    return true;
}


string Campo::getNombre(){
	return this->nombre;
}

int Campo::getTipo(){
	return this->tipo;
}

int Campo::getSize(){
	return this->size;
}

int Campo::getSize_d(){
	return this->size_dec;
}

bool Campo::getKey(){
	return this->key;
}

bool Campo::setNombre(string nombre){
    this->nombre=nombre;
    return true;
}

bool Campo::setTipo(int tipo){
    this->tipo=tipo;
    return true;
}

bool Campo::setSize(int size){
    this->size=size;
    return true;
}

bool Campo::setSize_d(int size_d){
    this->size_dec=size_d;
    return true;
}

bool Campo::setKey(bool key){
    this->key=key;
    return true;
}
