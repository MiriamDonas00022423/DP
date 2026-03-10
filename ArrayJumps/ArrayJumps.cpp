#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main()
{

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> dp(n, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (dp[j] != INT_MAX && j + a[j] >= i)
            {
                dp[i] = min(dp[i], dp[j] + 1);
            }
        }
    }

    if (dp[n - 1] == INT_MAX)
    {
        cout << -1 << "\n";
    }
    else
    {
        cout << dp[n - 1] << "\n";
    }

    return 0;
}
