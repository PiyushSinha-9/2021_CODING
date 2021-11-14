
int savingMoney(int n, int source, int destination, int k, vector<vector<int>>& trains)
{
    int high = 1e9;

    // Initializing dp with an infinite value
    vector<vector<int>> dp(k + 2, vector<int>(n + 1, high));
    dp[0][source] = 0;
    for (int i = 1; i < k + 2; i++)
    {
        dp[i][source] = 0;

        for (int j = 0; j < trains.size(); j++)
        {
            int a = trains[j][0], b = trains[j][1], c = trains[j][2];
            dp[i][b] = min(dp[i][b], dp[i - 1][a] + c);
        }

    }

    // No such route exists
    if (dp[k + 1][destination] >= high)
    {
        return -1;
    }

    return dp[k + 1][destination];
}