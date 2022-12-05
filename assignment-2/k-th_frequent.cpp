#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;

    int nums[20001]{};
    vector<vector<int>> freq(n + 1);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        nums[a + 10000]++;
    }
    for (int i = 0; i < 20001; i++) {
        if (nums[i] == 0) continue;
        freq[nums[i]].push_back(i);
    }

    int count = 0;
    for (int i = n; i > 0; i--) {
        for (int j : freq[i]) {
            count++;
            if (count == k) {
                cout << j - 10000 << '\n';
                return 0;
            }
        }
    }

    return 0;
}