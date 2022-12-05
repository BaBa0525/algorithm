#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class construction {
   public:
    construction() {}
    construction(int n, int k, int A, int B) {
        this->n = n;
        this->k = k;
        this->A = A;
        this->B = B;
    }
    ll min_cost(int s, ll n);
    void set_building(int loc);
    void sort_building() {
        sort(this->buildings.begin(), this->buildings.end());
    }
    int get_building_number(int s, int n);

   private:
    int n, k, A, B;
    vector<ll> buildings;
};

void construction::set_building(int loc) { this->buildings.push_back(loc); }
int construction::get_building_number(int s, int n) {
    auto low = lower_bound(buildings.begin(), buildings.end(), s);
    auto up = lower_bound(buildings.begin(), buildings.end(), s + n);
    return up - low;
}

ll construction::min_cost(int s, ll n) {
    // int building_no = 0;
    // for (int i = 0; i < k; i++) {
    //     if (s <= buildings[i] && buildings[i] < s + n) building_no++;
    // }
    int building_no = get_building_number(s, n);
    //  cout << n << ", " << building_no << '\n';

    ll cost = 0;
    if (building_no > 0) {
        if (n < 2) {
            cost = building_no * this->B;
        } else {
            ll split_cost = this->B * building_no * n;
            cost += min_cost(s, n / 2);
            cost += min_cost(s + (n / 2), n / 2);
            cost = min(cost, split_cost);
        }
    } else
        cost = this->A;

    // cout << "s: " << s << " n: " << n << " cost: " << cost
    //      << " building: " << building_no << '\n';
    return cost;
}

int main() {
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    int n, k, A, B;
    cin >> n >> k >> A >> B;
    construction c(n, k, A, B);

    for (int i = 0; i < k; i++) {
        ll loc;
        cin >> loc;
        c.set_building(loc);
    }
    // c.sort_building();

    cout << c.min_cost(1, n) << '\n';

    return 0;
}