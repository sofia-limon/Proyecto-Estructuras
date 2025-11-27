#include <bits/stdc++.h>
#include "Graph.h"
#include "Recorrido.h"
#include "Kosaraju.h"
#include "DSU.h"

using namespace std;

Graph g;

int main(){
    vector<string> menu = {
        "Salir",
        "Leer Grafo",
        "Kosaraju",
        "DSU",
        "Recorrido",
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
            case 2: startKosaraju(g); break;
            case 3: startDSU(g); break;
            case 4: startTraversal(g); break;
            default: cout<<"Opcion no valida\n"; break;
        }
    }
}