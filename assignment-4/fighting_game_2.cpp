#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> levels(n + 1);

    for (int i = 1; i < n + 1; i++) {
        cin >> levels[i];
        levels[i] += i;
        levels[i] = min(levels[i], n);
    }

    int loc = 1, count = 0;

    while (loc < n) {
        int far_step = 0, next_loc = 0;
        for (int i = loc + 1; i <= levels[loc]; i++) {
            if (far_step <= levels[i]) {
                next_loc = i;
                far_step = levels[i];
            }
        }
        loc = next_loc;
        count++;
    }

    cout << count << '\n';

    return 0;
}