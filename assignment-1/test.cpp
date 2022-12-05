#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;

    list<int> heap;
    for (int i = 0; i < n; i++) {
        int op, num;
        cin >> op;
        switch (op) {
            case 1:
                cin >> num;
                heap.push_back(num);
                break;
            case 2:
                heap.sort(greater<int>());
                break;
            case 3:
                if (heap.size() != 0) {
                    cout << heap.front() << '\n';
                    heap.pop_front();
                    continue;
                }
                cout << "Oh Oh\n";
                break;
            default:
                break;
        }
    }

    return 0;
}