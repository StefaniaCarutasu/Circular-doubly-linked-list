#pragma once
#include "node.h"
#include<iostream>
using namespace std;

class lista
{
    node* start;
    node* end;
    int length;
public:
    lista(); //facut
    lista(int[], int); //facut
    lista(const lista& l); //facut
    ~lista(); //facut
    node* getStart();
    node* getEnd();
    void inserareInceput(int);  //facut
    void inserarePoz(int, int);  //facut
    void inserareFinal(int);    //facut
    void stergerePoz(int);  //facut
    int cautare(int);   //facut
    int Suma(); //facut
    int nrElem();   //facut
    void inversare();   //facut
    int detMin();   //facut
    int detMax();   //facut
    friend ostream& operator << (ostream&, const lista&);   //
    friend istream& operator >> (istream&, const lista&);   //
    lista& operator + (lista&);    //facut
    bool operator > (lista);    //facut
    bool operator < (lista);    //facut
    int operator [] (int);    //facut
    void operator * (int);   //facut
    void operator = (lista&);  //facut
    
};



