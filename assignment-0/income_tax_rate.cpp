#include <bits/stdc++.h>
using namespace std;

double calculate_tax(const vector<pair<int, double>> &table, int income)
{
    double tax = 0;
    if (income < table[0].first)
        return tax;

    for (int i = 1; i < table.size(); i++)
    {
        if (income >= table[i].first)
        {
            tax += (table[i].first - table[i - 1].first) * table[i - 1].second;
        }
        else
        {
            tax += (income - (table[i - 1].first - 1)) * table[i - 1].second;
            return tax;
        }
    }
    tax += (income - (table.back().first - 1)) * table.back().second;
    return tax;
}

int main()
{
    int n, m;
    cin >> n;
    
    vector<pair<int, double>> table;
    for (int i = 0; i < n; i++)
    {
        int thres;
        double rate;
        cin >> thres >> rate;
        table.emplace_back(thres, rate);
    }

    cin >> m;

    for (int i = 0; i < m; i++)
    {
        int income;
        cin >> income;
        cout << fixed << setprecision(2) << calculate_tax(table, income) << '\n';
    }

    return 0;
}