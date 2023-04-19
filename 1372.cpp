class Solution {public:
    int longestZigZag(TreeNode* root) {
        if (!root) return 0;
        stack<pair<TreeNode*, int>> dfs;
        int ans = 0;
        if (root->left) dfs.push({root->left, -1});
        if (root->right) dfs.push({root->right, 1});
        while (!dfs.empty())
        {
            TreeNode* curr = dfs.top().first;
            int dep = dfs.top().second;
            dfs.pop();

            if (curr->left)
            {
                if (dep > 0) dfs.push({curr->left, -dep - 1});
                else dfs.push({curr->left, -1});
            }
            if (curr->right)
            {
                if (dep < 0) dfs.push({curr->right, -dep + 1});
                else dfs.push({curr->right, 1});
            }
            ans = max(ans, abs(dep));
        }
        return ans;
    }
};
