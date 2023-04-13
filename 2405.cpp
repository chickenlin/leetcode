class Solution {
public:
    int partitionString(string s) {
        int accur = 0;
        int res = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if ((1 << (s[i] - 'a') & accur))
            {
                cout << i;
                res++;
                accur = 0;
            }
            accur |= 1 << (s[i] - 'a');
        }
        res++;
        return res;
    }
};
