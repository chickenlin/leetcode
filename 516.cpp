// Time: O(n*n)
// Space: O(n*n)
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();

        // dp[i][j]: the longest palindromic subsequence's length of substring(i, j)
        vector<vector<int>> dp(n, vector<int>(n));

        // Initialization
        for (int i = 0; i < n; i++)
            dp[i][i] = 1;

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j + i < n; j++)
            {
                int tmp = max(dp[j + 1][j + i], dp[j][j + i - 1]);
                if (s[j] == s[j + i])
                    tmp = max(tmp, dp[j + 1][j + i - 1] + 2);
                dp[j][j + i] = tmp;
            }
        }
        return dp[0][n - 1];
    }
};

// Memorization
// Time: O(n*n)
// Space: O(n)
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();

        // dp[i][j]: the longest palindromic subsequence's length of substring(i, j)
        vector<vector<int>> dp(3, vector<int>(n));

        // Initialization
        for (int i = 0; i < n; i++)
            dp[i % 3][i] = 1;

        for (int i = 1; i < n; i++)
        {
            for (int j = 0; j + i < n; j++)
            {
                int tmp = max(dp[(j + 1) % 3][j + i], dp[j % 3][j + i - 1]);
                if (s[j] == s[j + i])
                    tmp = max(tmp, dp[(j + 1) % 3][j + i - 1] + 2);
                dp[j % 3][j + i] = tmp;
            }
        }
        return dp[0][n - 1];
    }
};
