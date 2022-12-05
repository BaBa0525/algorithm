#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> lis;

    for (int i = 0; i < n; i++) {
        int flower;
        cin >> flower;
        auto it = lower_bound(lis.begin(), lis.end(), flower);
        if (it == lis.end())
            lis.push_back(flower);
        else
            *it = flower;
    }

    cout << lis.size() << '\n';

    return 0;
}