#include "lista.h"
#include "node.h"
#include<iostream>
using namespace std;

lista::lista() : length(0), start(NULL), end(NULL) {} //constructor fara parametrii

lista::lista(node *n)  //constructor cu prametrii
{
    this->start = n;
    this->end = n;
    this->length = 1;
}

lista::lista(const lista& L) //constructor de copiere
{
    this->start = L.start;
    this->end = L.end;
    this->length = L.length;
}

lista::~lista() //destructor
{ 
    if (length > 0) {
        node* p = this->start; int i = 0;
        while (i<length) {
            node* q = p;
            p = p->next;
            delete q;
            i++;
        }
        this->start = NULL;
        this->end = NULL;
        this->length = 0;
    }
}

node* lista::getStart() const
{
    return this->start;
}


void lista::inserareInceput(int x)      //inserarea la inceputul listei
{
    node* aux = new node;
    aux->info = x;
    aux->next = start;
    aux->before = NULL;
    if (start == NULL)
    {
        start = aux; end = aux;
    }
    else
    {
        start->before = aux;
        aux->next = start;
        aux->before = end;
        end->next = aux;
        start = aux;
    }
    length++;
}
void lista::inserareFinal(int x)    //inserarea la finalul listei
{
    node* aux = new node;
    aux->info = x;
    aux->next = NULL;
    aux->before = NULL;
    if (start == NULL)
    {
        start = aux; end = aux;
    }
    else
    {
        end->next = aux;
        aux->before = end;
        aux->next = start;
        end = aux;
    }
    length++;

}
void lista::inserarePoz(int x, int poz)     //inserarea unei valori date pe o pozitie data
{
    node* aux = new node;
    aux->info = x;
    aux->next = NULL;
    aux->before = NULL;
    if (poz <= 0 || length==0)   // daca lista este vida sau pozitia introdusa este <0 atunci este inserat la inceput
        this->inserareInceput(x);
    else
    {
        if (poz >= length)  //daca pozitia introdusa este mai mare decat lungimea listei atunci este inserat la final
            this->inserareFinal(x);
        else
        {
            int i = 0;
            node* p = start;
            while (i < poz - 1)
            {
                p = p->next;
                i++;
            }
            aux->next = p;
            aux->before = p->before;
            p->before->next = aux;
            p->before = aux;
            length++;
        }
    }
   
}
void lista::stergerePoz(int poz)    //stergerea unei valori de pe o pozietie data
{
    
   if(poz>=0 && poz<length)
   {
       if (poz == 0)
       {
           node* aux = start;
           aux->next->before = end;
           end->next = aux->next;
           start = start->next;
           delete aux;
           this->length--;
       }
       else
       {
           if (poz == length - 1)
           {
               node* aux = end;
               end->before->next = start;
               start->before = end->before;
               end = end->before;
               delete aux;
               this->length--;
           }
           else
           {
               int i = 0;
               node* aux = start;
               while (i != poz - 1)
               {
                   aux = aux->next;
                   i++;
               }
               aux->before->next = aux->next;
               aux->next->before = aux->before;
               delete aux;
               this->length--;
           }
       }

   }
    
}
int lista::cautare(int x)   //cautarea unei valori in lista
{
    node* aux = this->start;
    int gasit = 0;
    int i = 0;
    if (this->length == 0)
        return -1;
    while (i < length && gasit == 0)
    {
        if (aux->info == x)
            gasit = 1;
        else
        {
            aux = aux->next;
            i++;
        } 
    }
    if (gasit)
        return i;
    else return -1;
}
int lista::Suma()   //suma elementelor din lista
{
    node* aux = start; int suma = 0, i = 0;
    while (i < length)
    {
        suma += aux->info;
        aux = aux->next;
        i++;
    }
    return suma;
}
int lista::nrElem()   //determinarea numarului de elemente
{
    return this->length;
}
int lista::detMax() //determinarea maximului
{
    node* aux = start->next; int max = start->info;
    for (int i = 1; i < length; i++)
    {
        if (aux->info > max)
            max = aux->info;
        aux = aux->next;
    }
    return max;
}
int lista::detMin() //determinarea minimului
{
    node* aux = start->next; int min = start->info;
    for (int i = 1; i < length; i++)
    {
        if (aux->info < min)
            min = aux->info;
        aux = aux->next;
    }
    return min;
}

void lista::inversare() //inversare: pornesc de la final si adaug fiecare element la finalul listei
{                       //apoi sterg primele l(=lungimea listei initale) elemente
    node* aux = this->end;
    int i = 0, l = this->length;
    while (i < l)
    {
        this->inserareFinal(aux->info);
        aux = aux->before;
        i++;
    }
    i = 0;
    while (i < l)
    {
        this->stergerePoz(0);
        i++;
    }
}

ostream& operator << (ostream& cout, lista& L)  //supraincarcare <<
{
    if (L.length > 0)
    {
        node* aux = L.start; int i = 1;
        while (i<=L.length)
        {
            cout << aux->getInfo() << ' ';
            aux = aux->getNext();
            i++;
        }
    }
    else cout << "Lista vida";
    return cout;

}

istream& operator >> (istream& in, lista& L)    //supraincarcare operator >>
{
    int lungime, i, x;
    in >> lungime;
    for (i = 0; i < lungime; i++)
    {
        in >> x;
        L.inserareFinal(x);
    }
    return in;
    
}

void lista::operator = (const lista& L) //supraincarcare operator =
{
    if (this->nrElem() != 0)
    {
        this->~lista();
        this->start = L.start;
        this->end = L.end;
        this->length = L.length;
    }
    else
    {
        this->start = L.start;
        this->end = L.end;
        this->length = L.length;
    }
    
}

int lista::operator [] (int poz)  //supraincarcare operator []
{
    if (poz > this->length || poz < 0)
        return -1;
    else
    {
        node* aux = start;
        int i = 0;
        while (i != poz)
        {
            aux = aux->next;
            i++;
        }
        return aux->info;
    }

}

void lista::operator * (int scalar)  //supraincarcare operator *
{
    node* aux = new node;
    int i = 0;
    aux = start; 
    while (i<length)
    {
        aux->info *= scalar;
        aux = aux->next;
        i++;
    }
}

lista& lista::operator + (lista& L)  //supraincarcare operator + 
{ 
    lista* newL = new lista;
    newL->start = this->start;
    newL->end = this->end;
    node* aux = new node;
    aux = L.start;
    newL->end->next = aux;
    aux->before = newL->end;
    newL->end = L.end;
    newL->end->next = newL->start;
    newL->start->before = newL->end;
    newL->length = this->length + L.length;
    return* newL;
}
 
int lista::operator < (lista L)  //supraincarcare operator <
{
    int x, y;
    x = this->Suma();
    y = L.Suma();
    if (x < y)
        return 1;
    else return 0;
}
int lista::operator > (lista L)  //supraincarcare operator >
{
    int x, y;
    x = this->Suma();
    y = L.Suma();
    if (x > y)
        return 1;
    else return 0;
}
