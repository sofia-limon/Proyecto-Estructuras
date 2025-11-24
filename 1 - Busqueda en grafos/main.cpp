#include <bits/stdc++.h>

using namespace std;

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
            cout<<'['<<i<<']'<<menu[i];
        }

        int x;
        cin>>x;

        switch(x){
            case 0: return 0;
            case 1: 
            case 2:
            case 3:
            case 4:
            default: cout<<"Opcion no valida"; break;
        }
    }
}