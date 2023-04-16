class Solution {
    const int mod = 1e9 + 7;
public:
    int numWays(vector<string>& words, string target) {
        int n = words[0].size(), m = target.size(), nWord = words.size();
        // dp[i][j]: words前i位有幾種可能可以組出target前j位
        vector<vector<long>> dp(2, vector<long>(m + 1, 0));

        // Initialization
        dp[0][0] = dp[1][0] = 1;

        for (int i = 1; i <= n; i++)
        {
            vector<int> count(26, 0);
            for (int j = 0; j < nWord; j++)
                count[words[j][i - 1] - 'a']++;
            for (int j = 1; j <= m; j++)
                dp[i % 2][j] = (dp[(i - 1) % 2][j] + dp[(i - 1) % 2][j - 1] * count[target[j - 1] - 'a'] % mod) % mod;
        }
        return dp[n % 2][m];
    }
};
