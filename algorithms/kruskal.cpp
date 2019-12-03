#include <bits/stdc++.h>

using namespace std;
using ii = pair<int, int>;

const int MAX { 200020 };

// disjoint sets data structure
int fathers[MAX];
int setsize[MAX];
vector< pair<int, ii> > edges;

// find the upper dad
int find(int x) {
    while (x != fathers[x]) x = fathers[x];
    return x;
}

// link the fathers
void unite(int x, int y) {
    int fx = find(x);
    int fy = find(y);
    if (setsize[fx] < setsize[fy]) swap(fx, fy); // fx: maior set
    setsize[fx] += setsize[fy];
    fathers[fy] = fx;
}

int main() {
    int n, m;
    int a, b, w;
    cin >> n >> m;

    // initialize fathers and sizes for the disjoint sets
    for(int i = 0; i < n; i++) {
        fathers[i] = i;
        setsize[i] = 1;
    }

    for(int i = 0; i < m; i++) {
        cin >> a >> b >> w;
        edges.push_back({w, {a, b}});
    }
    sort(edges.begin(), edges.end());
    
    int mst_weight = 0, mst_edges = 0, mst_ni = 0;
    while ((mst_edges < n-1) || (mst_ni < m)) {
        a = edges[mst_ni].second.first; b = edges[mst_ni].second.second; w = edges[mst_ni].first;
        // should be in different trees, otherwise, it creates a cycle
        if (find(a) != find(b)) {
            unite(a, b);
            mst_weight += w;
            // cout << a << " " << b << " " << w << "\n";
            mst_edges++;
        }
        mst_ni++;
    }
    cout << "O peso da árvore mínima é : " << mst_weight << '\n';

    return 0;
}