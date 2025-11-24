#include <bits/stdc++.h>
#include "Graph.h"
#include "DFS.h"

using namespace std;

Graph g;

int main(){
    vector<string> menu = {
        "Salir",
        "Leer Grafo",
        "DFS",
        "BFS",
        "Backtracking"
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
            //case 2: startDFS(); break;
            case 3: break;
            case 4: break;
            default: cout<<"Opcion no valida\n"; break;
        }
    }
}