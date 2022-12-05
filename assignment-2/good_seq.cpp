#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll make_seq_equal(vector<int> &arr, int s, int n) {
    ll step = 0;
    for (int i = 0; i < n; i++) {
        step += abs(arr[s + i] - arr[s + n / 2]);
    }

    return step;
}

void merge(vector<int> &arr, int s, int n) {
    vector<int> tmp(n);
    int k = 0, i = s, j = s + (n + 1) / 2;
    while (i < s + (n + 1) / 2 || j < s + n) {
        if (i < s + (n + 1) / 2 && j < s + n)
            tmp[k++] = (arr[i] < arr[j]) ? arr[i++] : arr[j++];
        else
            tmp[k++] = (i < s + (n + 1) / 2) ? arr[i++] : arr[j++];
    }
    for (int i = 0; i < n; i++) {
        arr[s + i] = tmp[i];
    }
}

ll good_seq(vector<int> &arr, int s, int n) {
    if (n == 1) return 0;

    ll first_seq = good_seq(arr, s, (n + 1) / 2);
    ll sec_seq = good_seq(arr, s + (n + 1) / 2, n / 2);

    ll first_equal = make_seq_equal(arr, s, (n + 1) / 2);
    ll sec_equal = make_seq_equal(arr, s + (n + 1) / 2, n / 2);

    merge(arr, s, n);

    return min(first_seq + sec_equal, sec_seq + first_equal);
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    ll step = good_seq(arr, 0, n);
    cout << step << '\n';

    return 0;
}