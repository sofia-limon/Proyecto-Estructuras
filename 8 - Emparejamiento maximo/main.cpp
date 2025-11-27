#include <bits/stdc++.h>
#include "Karp.h"
#include "Kuhn.h"
#include "Edmonds.h"
#include "Micali Vazirani.h"

using namespace std;

Graph g;

int main(){
    vector<string> menu = {
        "Salir",
        "Leer Grafo",
        "Hopcroft-Karp",
        "Kuhn",
        "Edmonds",
        "Micali Vazirani"
    };

    while(true){
        for(int i=0; i<menu.size(); i++){
            cout<<'['<<i<<']'<<menu[i]<<"\n";
        }

        int x;
        cin>>x;

        switch(x){
            case 0: return 0;
            case 1: g.init(); break;
            case 2: startKarp(g); break;
            case 3: startKuhn(g); break;
            case 4: startEdmonds(g); break;
            case 5: startMicali(g); break;
            default: cout<<"Opcion no valida\n"; break;
        }
    }
}

/*
# Grafo 1:
6 9
0 3
0 4
0 5
1 3
1 4
1 5
2 3
2 4
2 5

*/