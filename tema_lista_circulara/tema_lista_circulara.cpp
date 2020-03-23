#include <iostream>
#include "lista.h"
#include<cassert>
using namespace std;

void testeLista()
{
    lista l, m, n;
    l.inserarePoz(6, 6);
    l.inserarePoz(2, 1);
    l.inserarePoz(4, 0);
    l.inserarePoz(10, -3);
    assert(l.nrElem() == 4);
    assert(l.detMin() == 2);
    assert(l.detMax() == 10);
    assert(l.cautare(2) == 3);
    l.inversare();
    assert(l[0] == 2);
    assert(l.Suma() == 22);
    assert(l.stergerePoz(0) == 2);
    assert(l[0] == 6);
    m = l;
    for (int i = 0; i < l.nrElem(); i++)
        assert(l[i] == m[i]);
    l * 2;
    assert(l[0] == 12);
    n=l + m;
    assert(n.nrElem() == 6);
    bool i = l < n;
    assert(i == true);
    i = l > n;
    assert(l > n == false);
    assert(l.cautare(78) == -1);
    assert(l.cautare(12) == 0);
}

int main()
{
    /*lista L, M;
    cin >> L >> M;  //L=1,2,3,4,5;   M= 7,5,0,4
    cout << L + M << '\n';  //1 2 3 4 5 7 5 0 4
    L.inversare(); 
    cout << L<<'\n';  //5,4,3,2,1
    L.inserarePoz(7, -1);
    cout << L << '\n';  // 7 5,4,3,2,1
    L.inserarePoz(6, 9);
    cout << L  << '\n';  //7,5,4,3,2,1,6 
    L.inserarePoz(10, 4);
    cout << L << '\n';  //7,5,4,10,3,2,1,6
    cout << L.detMax() << ' ' << L.detMin() << '\n';  // 10 1
    cout << L.Suma();  //38*/

    testeLista();
    cout << "Testele au trecut bv fata meriti 10";

    return 0;
}

