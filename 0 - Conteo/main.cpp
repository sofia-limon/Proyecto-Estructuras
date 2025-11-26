#include <bits/stdc++.h>
#include "Conjuntopotencia.h"
#include "permutaciones.h"
#include "Combinacion.h"

using namespace std;

int main(){
    vector<string> menu = {
        "Salir", 
        "Conjunto potencia",
        "Combinaciones",
        "Permutaciones"
    };

    while(true){
        for(int i=0; i<menu.size(); i++){
            cout<<'['<<i<<']'<<menu[i]<<'\n';
        }

        int x;
        cin>>x;

        switch(x){
            case 0: return 0;
            case 1: menuconjuntopotencia(); break;
            case 2: combinacion(); break;
            case 3: permutacion(); break;
            default: cout<<"Opcion no valida\n"; break;
        }
    }
}