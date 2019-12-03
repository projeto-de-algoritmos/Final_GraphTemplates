#include <bits/stdc++.h>

using namespace std;
using edge = tuple<int, int, int>;

const int MAX { 100010 }, INF { 1000000010 };
int dist[MAX];

void bellman_ford(int s, int N, const vector<edge>& edges) {
    for(int i = 1; i <= N; ++i)
        dist[i] = INF;
    
    dist[s] = 0;

    for(int i = 1; i <= N-1; i++)
        for(const auto& [u, v, w] : edges)
            dist[v] = min(dist[v], dist[u]+w);
}

int main() {
    vector<edge> edges { edge(1, 2, 9), edge(1, 3, 7), edge(1, 4, 4), edge(1, 5, 2),
                         edge(2, 3, 1), edge(2, 6, 3), edge(3, 4, 2), edge(4, 5, 1), edge(5, 6, 11) };

    // não inicia do zero, pois edges aumenta seu tamanho
    for(int i = edges.size()-1; i >= 0; --i) {
        const auto& [u, v, w]  = edges[i];
        edges.push_back(edge(v, u, w));
    }

    // distância dos 6 nós em relação ao nó 1
    bellman_ford(1, 6, edges);

    for(int u = 1; u <= 6; ++u)
        cout << "Distância mínima de 1 a " << u << ": " << dist[u] << '\n';
    
    return 0;
}