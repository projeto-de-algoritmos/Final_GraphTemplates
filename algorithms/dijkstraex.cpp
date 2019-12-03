// deu problema em usar int (provável overflow ao somar a distância e o peso da aresta)

#include <bits/stdc++.h>

using namespace std;
using ii = pair<long long, long long>;

typedef long long ll;
inline void FAST_IO(){ ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);}

#define pb push_back
#define ff first
#define ss second
#define len(a) (int)(a).size()
#define all(x) x.begin(), x.end()
#define debug(x) cout << "> x:" << x << endl;

const ll MAX { 100010 }, INF { 1000000000000000010LL };
ll dist[MAX], pred[MAX];
vector<ii> adj[MAX];
bitset<MAX> visited;

void dijkstra(int s, int N) {
    for(int i = 1; i <= N; i++) {
        dist[i] = INF;
        pred[i] = -1;
    }

    dist[s] = 0;
    pred[s] = s;
    visited.reset();

    // min-heap (pair<distância, nó>)
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, s});

    while(not pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (visited[u])
            continue;
        
        visited[u] = true;

        for(const auto& [v, w] : adj[u]) {
            if (dist[v] > d+w) {
                dist[v] = d+w;
                pq.push({dist[v], v});
                pred[v] = u;
            }
        }
    }
}

int main() {
    FAST_IO();
    int n, m;
    cin >> n >> m;

    int a, b, w;
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> w;
        adj[a].pb({b, w});
        adj[b].pb({a, w});
    }
    dijkstra(1, n);

    vector<int> path;
    auto p = n;
    while (p != 1 and p >= 0) {
        path.pb(p);
        p = pred[p];
        // nó isolado: flag -1
        if (p < 0)
            path = vector<int> {};
    }
    
    if (path.empty()) {
        cout << -1 << '\n';
        return 0;
    }

    path.pb(1);
    reverse(all(path));
    for(int i = 0; i < len(path); i++) {
        cout << path[i] << (i + 1 == len(path) ? '\n' : ' ');
    }

    return 0;
}