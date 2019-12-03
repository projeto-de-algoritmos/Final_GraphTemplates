#include <bits/stdc++.h>

using namespace std;
using edge = pair<int, int>;

const int MAX { 100010 };

vector<int> adj[MAX];
bitset<MAX> visited;
int dist[MAX];

void bfs(int s) {
    visited.reset();

    queue<int> q;
    q.push(s);
    visited[s] = true;
    dist[s] = 0;

    while (not q.empty()) {
        auto u = q.front();
        q.pop();

        cout << u << endl;

        for (const auto& v: adj[u]) {
            if (visited[v])
                continue;
            
            visited[v] = true;
            dist[v] = dist[u] + 1;
            q.push(v);
        }
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

    bfs(1);
    cout << '\n';

    return 0;
}