#include <bits/stdc++.h>
using namespace std;

struct pos {
    pos(int r, int c) : r(r), c(c) {}
    int r, c;
};

int r[4] = {1, 0, -1, 0};
int c[4] = {0, -1, 0, 1};
int lsize = 7001;

char land[7001][7001] = {};

int dfs(int cur_r, int cur_c);
int find_max_area(int l, int r);

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        lsize = l;
        for (int j = 0; j < lsize; j++) {
            for (int k = 0; k < lsize; k++) {
                cin >> land[j][k];
            }
        }
        cout << find_max_area(l, r) << '\n';
    }

    return 0;
}

bool check_range(int value, int bound) {
    if (value < 0) return false;
    if (value >= bound) return false;
    return true;
}

int dfs(int cur_r, int cur_c) {
    int area = 0;
    vector<pos> stack;
    stack.emplace_back(cur_r, cur_c);

    while (!stack.empty()) {
        auto [row, col] = stack.back();
        stack.pop_back();

        if (land[row][col] == '^') continue;
        land[row][col] = '^';

        for (int i = 0; i < 4; i++) {
            int new_r = row + r[i];
            int new_c = col + c[i];

            if (!check_range(new_r, lsize)) continue;
            if (!check_range(new_c, lsize)) continue;
            if (land[new_r][new_c] == '^') continue;

            stack.emplace_back(new_r, new_c);
        }
        area++;
    }
    return area;
}

int find_max_area(int l, int r) {
    int center = l / 2, max_area = 0;
    for (int i = center - r; i <= center + r; i++) {
        for (int j = center - r; j <= center + r; j++) {
            int area = dfs(i, j);
            max_area = max(area, max_area);
        }
    }
    return max_area;
}