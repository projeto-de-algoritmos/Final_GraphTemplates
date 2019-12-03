#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

const int MAX { 200020 };
priority_queue<ii, vector<ii>, greater<ii>> edges;
vector<ii> adj[MAX];
bitset<MAX> vis;

int prims(int cnode, int n) { // nó inicial e número de nós
    int min_tree_w = 0, visn = 0;
    while (visn < n-1) { // número de arestas necessárias
        vis[cnode] = 1;
        visn++;
        for(auto &link : adj[cnode]) { // insere na heap as adjacências do nó
            edges.push(link);
        }
        while (vis[edges.top().second]) { // remove ciclos, nós já visitados
            edges.pop();
        }
        min_tree_w += edges.top().first;
        cnode = edges.top().second;
        edges.pop();
    }

    return min_tree_w;
}

int main() {
    int n, m;
    cin >> n >> m;
    int z = m, a, b, w;
    while(z--) {
        cin >> a >> b >> w;
        adj[a].push_back({w, b});
        adj[b].push_back({w, a});
    }

    int ans = prims(1, n);
    cout << "O peso da árvore mínima é: " << ans << '\n';

    return 0;
}