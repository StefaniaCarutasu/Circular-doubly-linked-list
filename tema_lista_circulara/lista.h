#pragma once
#include "node.h"
#include<iostream>
using namespace std;

class lista
{
    node* start;
    node* end;
    int length;
   
    void inserareInceput(int);  
    void inserareFinal(int);  
    node* getStart() const;

public:
    lista(); 
    lista(node*); 
    lista(const lista& l); 
    ~lista(); 
    void inserarePoz(int, int);  
    int stergerePoz(int);  
    int cautare(int);   
    int Suma(); 
    int nrElem();   
    void inversare();  
    int detMin();  
    int detMax();   
    friend ostream& operator << (ostream&, lista&);   
    friend istream& operator >> (istream&, lista&);   
    lista& operator + (lista&);   
    bool operator > (lista&);    
    bool operator < (lista&);    
    int operator [] (int);   
    void operator * (int);   
    void operator = (lista&);  
};



