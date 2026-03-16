#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

vector<int> memo;
vector<int> h;
int n;

int f(int i)
{
    if (i == n - 1)
    {
        return 0;
    }
    if (memo[i] != -1)
    {
        return memo[i];
    }

    int cost1 = abs(h[i] - h[i + 1]) + f(i + 1);
    int cost2 = 1e9;
    if (i + 2 < n)
    {
        cost2 = abs(h[i] - h[i + 2]) + f(i + 2);
    }
    return memo[i] = min(cost1, cost2);
}

int main()
{

    cin >> n;
    h.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> h[i];
    }
    memo.assign(n, -1);
    cout << f(0) << "\n";

    return 0;
}
