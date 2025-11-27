#include <bits/stdc++.h>
#include "Kosaraju.h"

using namespace std;

void dfsOrden(int u, const Graph& g, vector<int>& vis, vector<int>& orden) {
    vis[u] = 1;
    for (const Edge& e : g.adj[u]) {
        int v = e.to;
        if (!vis[v]) dfsOrden(v, g, vis, orden);
    }
    orden.push_back(u);
}

void dfsComponente(int u,
    const vector<vector<int>>& radj,vector<int>& vis,vector<int>& compActual) {
    vis[u] = 1;
    compActual.push_back(u);
    for (int v : radj[u]) {
        if (!vis[v]) dfsComponente(v, radj, vis, compActual);
    }
}

void startKosaraju(const Graph& g) {
    int n = g.n;

    vector<int> vis(n, 0);
    vector<int> orden;
    orden.reserve(n);

    for (int i = 0; i < n; ++i) {
        if (!vis[i]) dfsOrden(i, g, vis, orden);
    }

    vector<vector<int>> radj(n);
    for (int u = 0; u < n; ++u) {
        for (const Edge& e : g.adj[u]) {
            int v = e.to;
            radj[v].push_back(u);
        }
    }

    fill(vis.begin(), vis.end(), 0);
    vector<vector<int>> componentes;
    int numSCC = 0;

    for (int i = (int)orden.size() - 1; i >= 0; --i) {
        int u = orden[i];
        if (!vis[u]) {
            vector<int> compActual;
            dfsComponente(u, radj, vis, compActual);
            componentes.push_back(compActual);
            numSCC++;
        }
    }

    cout << "\nComponentes fuertemente conexas (Kosaraju):\n";
    cout << "Total de SCC: " << numSCC << "\n\n";

    int id = 1;
    for (auto& comp : componentes) {
        cout << "SCC " << id++ << ": ";
        for (int v : comp) cout << v << " ";
        cout << "\n";
    }
    cout << "\n";
}
