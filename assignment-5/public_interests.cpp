#include <bits/stdc++.h>
using namespace std;
#define private public

struct Edge {
    Edge(int u, int v, int w) : u(u), v(v), w(w) {}
    int u, v, w;
};

class DisjointSet {
   public:
    DisjointSet(int n, int e, int r)
        : boss(n, -1), rumors(n, false), n_vertex(n), n_edge(n), max_size(1) {}
    int find(int v);
    int max_tree();
    int min_tree();
    int get_size() { return max_size; }

    void merge(int u, int v);
    void add_edge(int u, int v, int w) { edges.emplace_back(u, v, w); }
    void add_rumor(int r) { rumors[r] = true; }
    void sort_edge();
    void reset() {
        fill(boss.begin(), boss.end(), -1);
        max_size = 1;
    }

   private:
    vector<int> boss;
    vector<bool> rumors;
    vector<Edge> edges;

    int n_vertex, n_edge, max_size;
};

int DisjointSet::find(int v) {
    return boss[v] < 0 ? v : boss[v] = find(boss[v]);
}

void DisjointSet::merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) return;

    if (-boss[u] > -boss[v]) {
        boss[u] += boss[v];
        boss[v] = u;
    } else {
        boss[v] += boss[u];
        boss[u] = v;
    }

    int cur_size = boss[u] < 0 ? -boss[u] : -boss[v];
    max_size = max(cur_size, max_size);
}

void DisjointSet::sort_edge() {
    sort(edges.begin(), edges.end(),
         [](Edge &e1, Edge &e2) { return e1.w < e2.w; });
}

int DisjointSet::max_tree() {
    int total_w = 0;
    if (n_vertex == 1) return 0;
    for (auto e = edges.rbegin(); e != edges.rend(); e++) {
        if (find(e->u) == find(e->v)) continue;
        total_w += e->w;
        merge(e->u, e->v);
        if (get_size() >= n_vertex) return total_w;
    }

    return -1;
}

int DisjointSet::min_tree() {
    int total_w = 0;
    if (n_vertex == 1) return 0;
    for (auto &e : edges) {
        auto [u, v, w] = e;
        if (rumors[u] || rumors[v]) {
            total_w += w;
            merge(u, v);
        }
    }

    if (get_size() >= n_vertex) return total_w;
    for (auto &e : edges) {
        auto [u, v, w] = e;
        if (find(u) == find(v)) continue;
        total_w += w;
        merge(u, v);
        if (get_size() >= n_vertex) return total_w;
    }

    return -1;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n_vertex, n_edge, n_rumor;
    while (cin >> n_vertex >> n_edge >> n_rumor) {
        DisjointSet ds(n_vertex, n_edge, n_rumor);
        for (int i = 0; i < n_edge; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            ds.add_edge(u, v, w);
        }
        ds.sort_edge();

        for (int i = 0; i < n_rumor; i++) {
            int r;
            cin >> r;
            ds.add_rumor(r);
        }

        int c1 = ds.max_tree();
        if (c1 == -1) {
            cout << "no\n";
            continue;
        }

        ds.reset();
        int c2 = ds.min_tree();
        if (c2 == -1) {
            cout << "no\n";
            continue;
        }
        cout << c1 - c2 << '\n';
    }

    return 0;
}