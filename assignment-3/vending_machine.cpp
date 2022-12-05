#include <bits/stdc++.h>
using namespace std;
using ll = long long;
constexpr int DPSIZE = 100001;

array<int, DPSIZE> dp;

void initial(vector<ll> &coins) {
    dp.fill(0x3fff'ffff);
    dp[0] = 0;

    for (int i = 0; i < dp.size(); i++) {
        for (ll coin : coins) {
            if (coin > i) continue;
            dp[i] = min(dp[i], dp[i - coin] + 1);
        }
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, q;
    cin >> n;
    vector<ll> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];
    initial(coins);

    cin >> q;

    for (int i = 0; i < q; i++) {
        ll price;
        cin >> price;

        ll coins_sum = 0;
        for (ll coin : coins) {
            ll num;
            cin >> num;
            coins_sum += coin * num;
        }

        cout << dp[coins_sum - price] << '\n';
    }

    return 0;
}