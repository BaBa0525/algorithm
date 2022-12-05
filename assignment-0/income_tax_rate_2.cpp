#include <bits/stdc++.h>
using namespace std;
using ll = long long;

double calculate_tax(const vector<pair<ll, double>> &table, ll income)
{
    double tax = 0;

    for (int i = 0; i < table.size(); i++)
    {
        if (income >= table[i].first)
        {
            tax += (income - (table[i].first - 1)) * table[i].second;
        }
        else
        {
            return tax;
        }
    }
    return tax;
}

int main()
{
    int n, m;
    cin >> n;

    vector<pair<ll, double>> table;
    double last = 0;
    for (int i = 0; i < n; i++)
    {
        ll thres;
        double rate;
        cin >> thres >> rate;
        table.emplace_back(thres, rate - last);
        last = rate;
    }

    cin >> m;

    for (int i = 0; i < m; i++)
    {
        ll income;
        cin >> income;
        cout << setprecision(10) << calculate_tax(table, income) << '\n';
    }

    return 0;
}