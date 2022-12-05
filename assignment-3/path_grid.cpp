#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int mod = 1e8 + 7;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int m, n;
    cin >> m >> n;

    int choose = min(m, n);
    vector<ll> pascal(choose);

    for (int i = 0; i < m + n - 1; i++) {
        if (i < choose) pascal[i] = 1;
        for (int j = min(i, choose) - 1; j > 0; j--) {
            pascal[j] += pascal[j - 1];
            pascal[j] %= mod;
        }
    }

    cout << pascal.back() << '\n';

    return 0;
}