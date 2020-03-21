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
public:
    lista(); 
    lista(node*); 
    lista(const lista& l); 
    ~lista(); 
    node* getStart() const;
    void inserarePoz(int, int);  
    void stergerePoz(int);  
    int cautare(int);   
    int Suma(); 
    int nrElem();   
    void inversare();  
    int detMin();  
    int detMax();   
    friend ostream& operator << (ostream&, lista&);   
    friend istream& operator >> (istream&, lista&);   
    lista& operator + (lista&);   
    int operator > (lista);    
    int operator < (lista);    
    int operator [] (int);   
    void operator * (int);   
    void operator = (const lista&);  
    
};



