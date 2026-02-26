#include <iostream>
#include <vector>
using namespace std;

// O(n*k)
vector<long long> dp;

long long countWays(int n, int k)
{
    // Base cases
    if (n == 0)
    {
        return 1;
    }
    if (n < 0)
    {
        return 0;
    }
    // check if state is already computed
    if (dp[n] != -1)
    {
        return dp[n];
    }
    long long ans = 0;
    for (int jump = 1; jump <= k; jump++)
    {
        ans += countWays(n - jump, k);
    }
    dp[n] = ans;
    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;
    // initialize all with -1
    dp.resize(n + 1, -1);
    cout << countWays(n, k) << "\n";

    return 0;
}