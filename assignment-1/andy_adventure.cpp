#include <bits/stdc++.h>
using namespace std;

int solve(int n, int t, const vector<long long>& weight) {
    int comb = 0;
    for (int i = 0; i < n; i++) {
        if (i > 0 && weight[i] == weight[i - 1]) continue;
        for (int j = i + 1; j < n; j++) {
            if (j > i + 1 && weight[j] == weight[j - 1]) continue;
            long long sum = weight[i] + weight[j];
            int k = j + 1, l = n - 1;
            while (k < l) {
                if (sum + weight[k] + weight[l] > t) {
                    l--;
                    continue;
                }
                if (sum + weight[k] + weight[l] < t) {
                    k++;
                    continue;
                }
                k++, l--, comb++;
                while (k < n && weight[k] == weight[k - 1]) k++;
                while (l > 0 && weight[l] == weight[l + 1]) l--;
            }
        }
    }
    return comb;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, t;
    cin >> n >> t;
    vector<long long> weight;

    for (int i = 0; i < n; i++) {
        long long w;
        cin >> w;
        weight.push_back(w);
    }

    sort(weight.begin(), weight.end());

    if (int comb = solve(n, t, weight); comb == 0)
        cout << "FeiDooDoo_Zuo_Wei_Men\n";
    else
        cout << comb << '\n';

    return 0;
}