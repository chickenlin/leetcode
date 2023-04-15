// DP solution
class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        // dp[i][j]: 前i個pile取j個硬幣的最大利益
        vector<vector<int>> dp(n + 1, vector<int>(k + 1));

        for (int i = 0; i <= k; i++)
            dp[0][i] = 0;
        for (int i = 0; i <= n; i++)
            dp[i][0] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= k; j++)
            {
                int tmp = dp[i - 1][j];
                int prefix = 0;
                for (int pick = 1; pick <= j && pick <= piles[i - 1].size(); pick++)
                {
                    prefix += piles[i - 1][pick - 1];
                    tmp = max(dp[i - 1][j - pick] + prefix, tmp);
                }
                dp[i][j] = tmp;
            }
        }
        return dp[n][k];
    }
};

// Memorization
class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        // dp[i][j]: 前i個pile取j個硬幣的最大利益
        vector<vector<int>> dp(2, vector<int>(k + 1, 0));

        for (int i = 1; i <= n; i++)
        {
            int size = piles[i - 1].size();
            for (int j = 1; j <= k; j++)
            {
                int tmp = dp[(i - 1) % 2][j];
                int prefix = 0;
                for (int pick = 1; pick <= j && pick <= size; pick++)
                {
                    prefix += piles[i - 1][pick - 1];
                    tmp = max(dp[(i - 1) % 2][j - pick] + prefix, tmp);
                }
                dp[i % 2][j] = tmp;
            }
        }
        return dp[n % 2][k];
    }
};
