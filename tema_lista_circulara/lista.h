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
    lista(); //facut merge 
    lista(node*); //facut oare?
    lista(const lista& l); //facut
    ~lista(); //facut si merge cred?
    node* getStart() const;  //facut
    int getLength() const;    //facut
    void inserareInceput(int);  //facut si merge
    void inserarePoz(int, int);  //facut si merge
    void inserareFinal(int);    //facut si merge
    void stergerePoz(int);  //facut si merge
    int cautare(int);   //facut si merge
    int Suma(); //facut si merge
    int nrElem();   //facut si merge
    void inversare();   //facut si merge sort of?????????
    int detMin();   //facut si merge
    int detMax();   //facut si merge
    friend ostream& operator << (ostream&, lista&);   //facut si merge
    friend istream& operator >> (istream&, lista&);   //facut si MERGE
    lista& operator + (lista&);    //facut merge dar nu stiu de ce
    int operator > (lista);    //facut si merge dar nu stiu dc
    int operator < (lista);    //facut si merge dar nu stiu de ce
    int operator [] (int);    //facut si merge
    void operator * (int);   //facut si merge
    void operator = (const lista&);  //facut si merge
    
};



