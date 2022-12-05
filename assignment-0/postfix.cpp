#include <bits/stdc++.h>
using namespace std;
using ll = long long;

constexpr int mod = 1e9 + 7;

bool is_op(string exp)
{
    if (exp == "+" || exp == "*")
        return true;
    return false;
}

ll calculate(ll a, ll b, string op)
{
    if (op == "+")
        return (a + b) % mod;
    if (op == "*")
        return (a * b) % mod;
    return -1;
}

int main()
{

    string exp, op;
    getline(cin, exp);

    stringstream ss(exp);
    vector<int> stack;

    while (ss >> op)
    {
        if (is_op(op))
        {
            ll a = stack.back();
            stack.pop_back();
            ll b = stack.back();
            stack.back() = calculate(a, b, op);
        }
        else
        {
            stack.push_back(stoi(op));
        }
    }

    cout << stack[0] << '\n';

    return 0;
}