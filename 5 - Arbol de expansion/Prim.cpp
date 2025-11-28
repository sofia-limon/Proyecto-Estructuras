#include "Prim.h"
#include <bits/stdc++.h>

using namespace std;

struct Prim{
    int n;
    long long peso=0;
    set<vector<long long>> djk;
    vector<vector<int>> component;
    vector<int> id;

    Graph g;
    Prim(int _n):n(_n){
        component.resize(n);
        g.adj.resize(n);
        id.resize(n);
        for(int i=0; i<n; i++)id[i]=i, component[i].push_back(i);
    }

    void reverse(){
        peso=-peso;
        for(auto& v:g.adj)for(auto& e:v)e.weight=-e.weight;
    }

    void DSU(int x, int y){
        if(component[x].size()<component[y].size())swap(x,y);
        for(auto& u:component[y]){
            component[x].push_back(u);
            id[u]=x;
        }
        component[y].clear();
    }

    void kruskal(){
        while(!heap.empty()){
            auto v=*heap.begin();
            heap.erase(heap.begin());
            int w=v[0], x=id[v[1]], y=id[v[2]];

            if(x==y)continue;
            DSU(x, y);
            peso+=w;
            Edge e;
            e.to=y, e.weight=w;
            g.adj[x].push_back(e);
        }
    }
};

void startPrim(Graph &g){
    int root, to;
    cout<<"Ingresa el nodo en el que inicia la busqueda (Indexado a 0): ";
    cin>>root;
    cout<<"Ingresa el nodo objetivo (Indexado a 0): ";
    cin>>to;

    vector<int> dis(g.n, 0);

    bfs(g, dis, root);

    if(dis[to]==-1)cout<<"No se puede alcanzar el nodo "<<to<<" desde el nodo "<<root<<".\n";
    else cout<<"La distancia entre "<<root<<" y "<<to<<" es de "<<dis[to]<<"\n";
    cout<<"La distancia de los nodos alcanzados desde "<<root<<" son:\n";
    
    for(int i=0; i<g.n; i++){
        if(dis[i]==-1)continue;
        cout<<root<<"->"<<i<<'='<<dis[i]<<"\n";
    }
    
    return;
}

