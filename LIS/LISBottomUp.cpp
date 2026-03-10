#include <iostream>
#include <vector>
#include <algorithm>
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
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (dp[j] < dp[i])
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    // La respuesta final no necesariamente está en dp[n-1]
    // La mejor subsecuencia puede terminar en cualquier posición
    int lis = 0;
    for (int i = 0; i < n; i++)
    {
        lis = max(lis, dp[i]);
    }

    cout << lis << "\n";

    return 0;
}