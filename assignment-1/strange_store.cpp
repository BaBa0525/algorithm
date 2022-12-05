#include <bits/stdc++.h>
using namespace std;

constexpr int mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int *arr = (int *)malloc(sizeof(int) * n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);

    long long permutation = 1;
    for (int i = 0; i < n; i++) {
        if (arr[i] < n)
            permutation *= (arr[i] - i);
        else
            permutation *= (n - i);
        permutation %= mod;
    }

    cout << permutation << '\n';

    return 0;
}