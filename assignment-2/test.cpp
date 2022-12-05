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

    sort(nums, nums + 20000, greater<int>());

    int count = 0;
    for (int i = 20001; i > 0; i--) {
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