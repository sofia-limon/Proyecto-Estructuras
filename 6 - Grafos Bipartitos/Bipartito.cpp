#include <bits/stdc++.h>
#include "Graph.h"

using namespace std;

int bfsColor(const Graph& g, int x, vector<int>& color){    
    queue<int> bfs;
    color[x] = 0;
    bfs.push(x);

    while (!bfs.empty()) {
        int u = bfs.front();
        bfs.pop();

        for (int v : g.adj[u]) {
            if (color[v] == -1) {
                color[v] = color[u] ^ 1; 
                bfs.push(v);
            } else if (color[v] == color[u]) {
                return 0;
            }
        }
    }

    return 1;
}

int esBipartito(const Graph& g){
    int n = g.n;
    vector<int> color(n, -1);

    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {
            if (!bfsColor(g, i, color)) {
                return 0;
            }
        }
    }
    return 1;
}

void startBiparticion(const Graph& g){
    int n = g.n;
    vector<int> color(n, -1);

    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {
            if (!bfsColor(g, i, color)) {
                cout << "\nEl grafo no es bipartito.\n\n";
                return;
            }
        }
    }

    cout << "\nEl grafo es bipartito.\n";

    vector<int> team1, team2;
    for (int v = 0; v < n; v++) {
        if (color[v] == 0) team1.push_back(v);
        else if (color[v] == 1) team2.push_back(v);
    }

    cout << "Lado 0: ";
    for (auto& v : team1) cout << v << ' ';
    cout << "\n";

    cout << "Lado 1: ";
    for (auto& v : team2) cout << v << ' ';
    cout << "\n\n";
}
