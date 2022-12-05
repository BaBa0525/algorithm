#include <bits/stdc++.h>
using namespace std;

class construction {
   public:
    construction() {}
    construction(long long n, long long k, long long A, long long B) {
        this->n = n;
        this->k = k;
        this->A = A;
        this->B = B;
        this->buildings = vector<long long>(n, 0);
    }
    long long min_cost(long long s, long long n);
    void set_building(long long loc, long long i);
    vector<long long> buildings;

   private:
    long long n, k, A, B;
};

void construction::set_building(long long loc, long long i) {
    this->buildings[i] = loc - 1;
}

long long construction::min_cost(long long s, long long n) {
    long long building_no = 0;
    for (long long i = 0; i < n; i++) building_no += buildings[s + i];

    long long cost = 0;
    if (building_no > 0)
        cost = this->B * building_no * n;
    else
        cost = this->A;

    if (n < 2) return cost;

    long long split_cost = 0;
    split_cost += min_cost(s, n / 2);
    split_cost += min_cost(s + n / 2, n / 2);

    return min(cost, split_cost);
}

long long main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    long long n, k, A, B;
    cin >> n >> k >> A >> B;
    construction c(n, k, A, B);

    for (long long i = 0; i < k; i++) {
        long long loc;
        cin >> loc;
        c.buildings[loc - 1]++;
    }

    // for (auto i : c.buildings) cout << i << ' ';
    // cout << '\n';

    cout << c.min_cost(0, n) << '\n';

    return 0;
}