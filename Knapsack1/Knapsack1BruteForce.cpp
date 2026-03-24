#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, W;
vector<int> w, v;

long long solve(int i, int cap)
{
    // No more objects
    if (i == N)
        return 0;
    // Not taking object i
    long long ans = solve(i + 1, cap);
    // take it if possible
    if (w[i] <= cap)
    {
        ans = max(ans, (long long)v[i] + solve(i + 1, cap - w[i]));
    }
    return ans;
}

int main()
{
    cin >> N >> W;
    w.resize(N);
    v.resize(N);
    for (int i = 0; i < N; i++)
    {
        cin >> w[i] >> v[i];
    }

    cout << solve(0, W) << "\n";

    return 0;
}
