#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;

    list<int> tmp;
    priority_queue<int> max_heap;
    for (int i = 0; i < n; i++) {
        int op, num;
        cin >> op;
        switch (op) {
            case 1:
                cin >> num;
                tmp.push_back(num);
                break;
            case 2:
                for (int i : tmp) max_heap.push(i);
                tmp.clear();
                break;
            case 3:
                if (!max_heap.empty()) {
                    cout << max_heap.top() << '\n';
                    max_heap.pop();
                    continue;
                }
                if (!tmp.empty()) {
                    cout << tmp.front() << '\n';
                    tmp.pop_front();
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