#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    ll L, R;
    cin >> n >> L >> R;
    vector<ll> arr(n);

    for (int i = 0; i < n; i++) cin >> arr[i];

    sort(arr.begin(), arr.end());

    int lower = n - 1, upper = n - 1, current = 0;
    ll total = 0;

    while (current < n - 1) {
        if (arr[current] * arr[n - 1] < L) {
            current++;
            continue;
        }
        if (arr[current] * arr[current + 1] > R) break;

        while (lower > current + 1 && arr[current] * arr[lower - 1] >= L)
            lower--;

        while (arr[current] * arr[upper] > R) upper--;

        total += upper - lower + 1;
        current++;
        lower++;
    }

    cout << total << '\n';

    return 0;
}