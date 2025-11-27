#include <bits/stdc++.h>
#include "DSU.h"

using namespace std;

void startDSU(const Graph& g) {
    int n = g.n;

    vector<vector<int>> ans(n);
    vector<int> p(n);

    for (int i = 0; i < n; i++) {
        p[i] = i;
        ans[i].push_back(i);
    }

    function<void(int, int)> DSU = [&](int X, int Y) {
        int x = p[X], y = p[Y];
        if (x == y) return;

        if (x > y) swap(x, y);
        if (ans[x].size() < ans[y].size()) swap(ans[x], ans[y]);

        for (auto& u : ans[y]) {
            p[u] = x;
            ans[x].push_back(u);
        }
        ans[y].clear();
    };

    for (int i = 0; i < n; i++) {
        for (const Edge& e : g.adj[i]) {
            DSU(e.to, i);
        }
    }

    cout << "\nComponentes (DSU):\n";

    for (auto& v : ans) {
        if (v.empty()) continue;
        for (auto& u : v) cout << u << ' ';
        cout << "\n";
    }

    cout << "\n";
}
