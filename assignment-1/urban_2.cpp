#include <bits/stdc++.h>
using namespace std;
typedef priority_queue<long long> max_heap;

void min_bricks(long long n, max_heap &heap) {
    long long i = 1;
    while (i < n) {
        if (i & n) heap.push(i);
        i <<= 1;
    }
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    long long n;
    int k;
    cin >> n >> k;

    max_heap heap;
    min_bricks(n, heap);
    long long min_br = heap.size();

    if (min_br <= k && k <= n) {
        cout << "YES\n";
        while (min_br < k) {
            long long min_two = heap.top();
            heap.pop();
            min_two /= 2;
            heap.push(min_two);
            heap.push(min_two);
            min_br++;
        }
        while (!heap.empty()) {
            cout << heap.top() << ' ';
            heap.pop();
        }
        cout << '\n';
    } else
        cout << "NO\n";

    return 0;
}