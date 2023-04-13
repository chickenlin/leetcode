class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int> ans;
        int m = potions.size(), n = spells.size();
        sort(potions.begin(), potions.end());
        for (int i = 0; i < n; i++)
        {
            int mod = success % spells[i] == 0 ? 0 : 1;
            auto it = lower_bound(potions.begin(), potions.end(), success / spells[i] + mod);
            ans.push_back(potions.end() - it);
        }
        return ans;
    }
};
