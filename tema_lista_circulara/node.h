#pragma once
#include<iostream>
class node
{
    int info;
    node* next;
    node* before;
public:
    node();
    node(int, node*, node*);
    node* getNext()const;
    int getInfo()const;
    friend class lista;
};



