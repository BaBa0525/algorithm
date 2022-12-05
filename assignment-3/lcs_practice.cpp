#include <bits/stdc++.h>
using namespace std;

int a[] = {1, 3, 2, 5};
int b[] = {1, 2, 5};
int lcs(int n, int m) {
    if (n < 0 || m < 0) return 0;

    int max_length = 0;

    if (a[n] == b[m])
        max_length = 1 + lcs(n - 1, m - 1);
    else
        max_length = max(lcs(n - 1, m), lcs(n, m - 1));

    return max_length;
}

int main() {
    cout << lcs(3, 2) << '\n';

    return 0;
}