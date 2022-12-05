#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> levels(n + 1, 0);

    for (int i = 0; i < n; i++) cin >> levels[i];

    for (int i = 2; i < n + 1; i++)
        levels[i] += min(levels[i - 1], levels[i - 2]);

    cout << levels[n] << '\n';

    return 0;
}