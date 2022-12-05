#include <bits/stdc++.h>
using namespace std;
using ll = long long;

array<int, 1000001> dp;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;

    vector<ll> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    dp.fill(0x3fff'ffff);
    dp[0] = 0;
    for (int i = 0; i < dp.size(); i++) {
        for (int coin : coins) {
            if (coin > i) continue;
            dp[i] = min(dp[i], dp[i - coin] + 1);
        }
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        ll price, total_coins = 0;
        cin >> price;
        for (ll coin : coins) {
            ll coin_num;
            cin >> coin_num;
            total_coins += coin * coin_num;
        }
        cout << dp[total_coins - price] << '\n';
    }
}