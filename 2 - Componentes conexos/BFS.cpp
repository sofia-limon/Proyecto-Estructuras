#include <bits/stdc++.h>
#include "Recorrido.h"

using namespace std;

void startTraversal(const Graph& g) {
    vector<int> comp(g.n, -1);
    int numComp = 0;

    for (int start = 0; start < g.n; ++start) {
        if (comp[start] != -1) continue;

        numComp++;
        queue<int> q;
        q.push(start);
        comp[start] = numComp;

        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (const Edge& e : g.adj[u]) {
                int v = e.to;
                if (comp[v] == -1) {
                    comp[v] = numComp;
                    q.push(v);
                }
            }
        }
    }

    cout << "\nComponentes (por recorrido/BFS):\n";
    cout << "Total de componentes: " << numComp << "\n\n";

    for (int c = 1; c <= numComp; ++c) {
        cout << "Componente " << c << ": ";
        for (int v = 0; v < g.n; ++v) {
            if (comp[v] == c) cout << v << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}
