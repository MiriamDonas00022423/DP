#include <iostream>
using namespace std;

int countWays(int n, int k)
{
    // Base cases
    if (n == 0)
    {
        // One way to stay on the ground (do nothing)
        return 1;
    }
    if (n < 0)
    {
        // Impossible
        return 0;
    }
    int ans = 0;
    for (int jump = 1; jump <= k; jump++)
    {
        ans += countWays(n - jump, k);
    }
    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;
    cout << countWays(n, k) << "\n";

    return 0;
}

