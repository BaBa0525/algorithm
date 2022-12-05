#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    long long n, current_max = numeric_limits<int>::min(),
                 general_max = numeric_limits<int>::min(),
                 current_min = numeric_limits<int>::max(),
                 general_min = numeric_limits<int>::max();

    cin >> n;

    for (int i = 0; i < n; i++) {
        long long revenue;
        cin >> revenue;

        current_max = max(current_max + revenue, revenue);
        general_max = max(general_max, current_max);
        current_min = min(current_min + revenue, revenue);
        general_min = min(general_min, current_min);
    }

    cout << max(abs(general_max), abs(general_min)) << '\n';

    return 0;
}