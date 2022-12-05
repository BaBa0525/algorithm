#include <bits/stdc++.h>
using namespace std;
typedef priority_queue<long long, vector<long long>, greater<long long>>
    min_heap;

int min_bricks(long long n, min_heap &heap) {
    long long two_power = 1;
    int bricks = 0;
    while (n - two_power > two_power) two_power *= 2;

    while (n > 0) {
        if (two_power > n) {
            two_power /= 2;
            continue;
        }
        n -= two_power;
        heap.push(two_power);
        bricks++;
    }

    return bricks;
}

void print_last(int diff, long long two_power) {
    int count = 1;
    while (count < diff) {
        two_power /= 2;
        count *= 2;
    }
    cout << count << '\n';
    while (count--) cout << two_power << ' ';
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    long long n;
    int k;
    cin >> n >> k;

    if (n % 2) {
        cout << "NO\n";
        return 0;
    }

    min_heap heap;
    int min_br = min_bricks(n, heap);
    int max_br = n / 2;

    if (min_br <= k && k <= max_br) {
        cout << "YES\n";
        while (min_br < k) {
            long long min_two = heap.top();
            heap.pop();
            long long add = (min_two / 2) - 1;
            if (min_br + add <= k) {
                min_br += add;
                add++;
                while (add--) cout << 2 << ' ';
            } else {
                print_last(k - min_br + 1, min_two);
                break;
            }
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