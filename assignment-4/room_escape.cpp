#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;

    vector<string> nums(n);
    vector<int> ind(n);

    for (int i = 0; i < n; i++) {
        int a;
        cin >> nums[i];
        ind[i] = i;
    }

    sort(ind.begin(), ind.end(), [&](const int& a, const int& b) -> bool {
        return nums[a] + nums[b] > nums[b] + nums[a];
    });

    for (int i : ind) cout << nums[i];

    cout << '\n';

    return 0;
}