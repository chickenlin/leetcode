class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int index = 0, n = pushed.size();
        for (int i = 0; i < n; i++)
        {
            s.push(pushed[i]);
            while (!s.empty() && s.top() == popped[index])
            {
                index++;
                s.pop();
            }
        }
        return s.empty();
    }
};
