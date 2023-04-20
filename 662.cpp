/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, long>> bfs;
        long ans = 1, level = 1, next_level = 0;
        if (root) bfs.push({root, 0});
        while (!bfs.empty())
        {
            long bias = bfs.front().second;
            long maxIndex;
            while (level--)
            {
                TreeNode* curr = bfs.front().first;
                long index = bfs.front().second - bias;
                if (level == 0) maxIndex = index;
                bfs.pop();
                if (curr->left)
                {
                    bfs.push({curr->left, index * 2});
                    next_level++;
                }
                if (curr->right)
                {
                    bfs.push({curr->right, index * 2 + 1});
                    next_level++;
                }
            }
            ans = max(ans, maxIndex + 1);
            level = next_level;
            next_level = 0;
        }
        return ans;
    }
};
