#include <bits/stdc++.h>
using namespace std;

struct examee {
    int cost_a, cost_b;
};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, a = 0, b = 0;
    cin >> n;
    vector<examee> costs(n);

    for (int i = 0; i < n; i++) cin >> costs[i].cost_a >> costs[i].cost_b;

    sort(costs.begin(), costs.end(), [](const examee &a, const examee &b) {
        return abs(a.cost_a - a.cost_b) > abs(b.cost_a - b.cost_b);
    });

    int total_cost = 0;
    for (auto &examee : costs) {
        if (a == n / 2) {
            total_cost += examee.cost_b;
            b++;
            continue;
        }

        if (b == n / 2) {
            total_cost += examee.cost_a;
            a++;
            continue;
        }

        if (examee.cost_a > examee.cost_b) {
            total_cost += examee.cost_b;
            b++;
        } else {
            total_cost += examee.cost_a;
            a++;
        }
    }

    cout << total_cost << '\n';

    return 0;
}