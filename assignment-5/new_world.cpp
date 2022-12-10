#include <bits/stdc++.h>
using namespace std;

struct Edge {
    Edge(int u, int v, int w) : u(u), v(v), w(w) {}
    int u, v, w;
};

struct Cmp {
    bool operator()(Edge &e1, Edge &e2) { return e1.w < e2.w; }
};

class DisjointSet {
   public:
    DisjointSet(int n) : boss(n, -1), max_size(1) {}
    int find(int v);
    int merge(int u, int v);
    int get_size() { return max_size; }

   private:
    vector<int> boss;
    int max_size;
};

int DisjointSet::find(int v) {
    return boss[v] < 0 ? v : boss[v] = find(boss[v]);
}

int DisjointSet::merge(int u, int v) {
    u = find(u);
    v = find(v);

    if (-boss[u] > -boss[v]) {
        boss[u] += boss[v];
        boss[v] = u;
    } else {
        boss[v] += boss[u];
        boss[u] = v;
    }

    int merge_size = boss[u] < 0 ? -boss[u] : -boss[v];
    max_size = max(merge_size, max_size);
    return merge_size;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n_vertex, n_edge, n_outpost;

    while (cin >> n_vertex >> n_edge >> n_outpost) {
        DisjointSet ds(n_vertex);
        vector<Edge> edges;
        for (int i = 0; i < n_edge; i++) {
            int a, b, w;
            cin >> a >> b >> w;
            edges.emplace_back(a, b, w);
        }

        vector<bool> outposts(n_vertex, 0);
        for (int i = 0; i < n_outpost; i++) {
            int op;
            cin >> op;
            outposts[op] = true;
        }
        sort(edges.begin(), edges.end(), Cmp());

        int total_w = 0;
        for (auto &e : edges) {
            if (outposts[e.u] || outposts[e.v]) continue;
            if (ds.find(e.u) == ds.find(e.v)) continue;
            total_w += e.w;
            ds.merge(e.u, e.v);
        }

        if (ds.get_size() < n_vertex - n_outpost) {
            cout << -1 << '\n';
            continue;
        }

        for (auto &e : edges) {
            if (ds.find(e.u) == ds.find(e.v)) continue;
            total_w += e.w;
            ds.merge(e.u, e.v);
        }

        if (ds.get_size() < n_vertex) {
            cout << -1 << '\n';
            continue;
        }

        cout << total_w << '\n';
    }

    return 0;
}