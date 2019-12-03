#include <bits/stdc++.h>

using namespace std;
using edge = pair<int, int>;

const int MAX { 100010 };
bitset<MAX> visited;
vector<int> adj[MAX];

void dfs(int u) {
    if (visited[u]) return;

    visited[u] = true;
    cout << u << endl;

    for (const auto& v: adj[u])
        dfs(v);
}

void dfs_it(int u) {
    stack<int> s;
    s.push(u);

    while (not s.empty()) {
        auto v = s.top();

        if (not visited[v]) {
            visited[v] = true;
            cout << v << endl;
        }

        for (const auto& w: adj[v]) {
            if (not visited[w]) {
                s.push(w);
                break;
            }
        }

        if (s.top() == v)
            s.pop();

    }

}

int main() {
    vector<edge> edges { {1, 2}, {1, 3}, {2, 4}, {2, 5}, 
        {3, 6}, {5, 6}, {5, 8}, {5, 9}, {6, 7}, {6, 10}, 
        {8, 11}, {9, 10}, {11, 12}, {11, 13} };

    for (const auto& [u, v] : edges) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    visited.reset();

    // dfs(1);
    cout << '\n';

    dfs_it(1);

    return 0;
}