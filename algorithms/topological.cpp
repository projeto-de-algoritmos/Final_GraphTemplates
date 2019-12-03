// O B S E R V A Ç Ã O
// O GRAFO NÃO PODE TER CICLOS

#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;
using edge = tuple<int, int, int>;

const int MAX { 100010 }, INF { 1000000010 };
int dist[MAX];
vector<int> adj[MAX];
bitset<MAX> visited;
vector<int> ans;

void dfs2(int u) {
    visited[u] = true;
    for(const auto& v : adj[u])
        if (!visited[v])
            dfs2(v);
    ans.push_back(u);
}

int main() {
    int n, m, u, v;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        cin >> u >> v;
        adj[u].push_back(v);
    }

    visited.reset();

    for(int i = 1; i <= n; i++)
        if (!visited[i])
            dfs2(i);
    
    for(int i = (int) ans.size()-1; i >= 0; i--)
        cout << " " << ans[i];
    cout << "\n";

    return 0;
}