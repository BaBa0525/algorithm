#include <bits/stdc++.h>
using namespace std;

struct reserve {
    int start_time, end_time;
};

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<reserve> reserves(n);

    for (int i = 0; i < n; i++)
        cin >> reserves[i].start_time >> reserves[i].end_time;

    sort(reserves.begin(), reserves.end(),
         [](const reserve &a, const reserve &b) {
             if (a.end_time == b.end_time)
                 return a.end_time - a.start_time < b.end_time - b.start_time;

             return a.end_time < b.end_time;
         });

    int last_time = 0;
    for (auto r : reserves) {
        if (r.start_time >= last_time) {
            last_time = r.end_time;
            cout << r.start_time << ' ' << r.end_time << '\n';
        }
    }

    return 0;
}