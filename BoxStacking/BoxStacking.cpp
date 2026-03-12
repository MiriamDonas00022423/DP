#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compareBoxes(vector<int> b1, vector<int> b2)
{
    return b1[2] < b2[2];
}

bool canPlace(vector<int> b1, vector<int> b2)
{
    if (b1[0] < b2[0] && b1[1] < b2[1] && b1[2] < b2[2])
    {
        return true;
    }
    return false;
}

int boxStacking(vector<vector<int>> boxes)
{
    sort(boxes.begin(), boxes.end(), compareBoxes);
    int n = boxes.size();
    vector<int> dp(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        dp[i] = boxes[i][2];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (canPlace(boxes[j], boxes[i]))
            {
                int current_height = boxes[i][2];
                if (dp[j] + current_height > dp[i])
                {
                    dp[i] = dp[j] + current_height;
                }
            }
        }
    }
    int max_height = 0;
    for (int i = 0; i < n; i++)
    {
        cout << dp[i] << ",";
        max_height = max(max_height, dp[i]);
    }
    return max_height;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> boxes(n, vector<int>(3));

    for(int i = 0; i < n; i++)
    {
        cin >> boxes[i][0] >> boxes[i][1] >> boxes[i][2];
    }

    int height = boxStacking(boxes);
    cout << "Max height: " << height << "\n";

    return 0;
}
