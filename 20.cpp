class Solution {
public:
    bool isValid(string s) {
        int size = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                s[size++] = s[i];
            else if (size <= 0 || (s[size - 1] == '(' && s[i] != ')') || (s[size - 1] == '[' && s[i] != ']') || (s[size - 1] == '{' && s[i] != '}'))
                return false;
            else
                size--;
            if (size < 0) return false;
        }
        return size == 0;
    }
};
