#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> price(n);

    for (int i = 0; i < n; i++) {
        cin >> price[i];
    }

    sort(price.begin(), price.end());
    price.erase(unique(price.begin(), price.end()), price.end());

    ll k, extra_cost;
    cin >> k;
    extra_cost = k * (k + 1) / 2;

    for (auto &cost : price) {
        if (cost <= k) {
            k++;
            extra_cost += (k - cost);
        }
    }

    cout << extra_cost << '\n';

    return 0;
}