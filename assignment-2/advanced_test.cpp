#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int arr[501]{};

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int total = 0;
        for (int j = 0; j < 5; j++) {
            int score;
            cin >> score;
            total += score;
        }
        arr[total] += 1;
    }

    for (int i = 500; i >= 0; i--) {
        for (int j = 0; j < arr[i]; j++) {
            cout << i << '\n';
        }
    }

    return 0;
}