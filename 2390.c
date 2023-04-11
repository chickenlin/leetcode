class Solution {
public:
    string removeStars(string s) {
        int size = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '*')
                size--;
            else
                s[size++] = s[i];
        }
        return s.substr(0, size);
    }
};
