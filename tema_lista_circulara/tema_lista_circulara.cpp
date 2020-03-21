#include <iostream>
#include "lista.h"
using namespace std;

int main()
{
    lista L, M;
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
    cout << L.Suma();  //38
    return 0;
}

