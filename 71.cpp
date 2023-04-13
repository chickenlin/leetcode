class Solution {public:
    string simplifyPath(string path) {
        string part;
        stack<string> st;
        stringstream ss(path);
        while (getline(ss, part, '/'))
        {
            if (part == "" || part == ".") continue;
            if (part == ".." && !st.empty()) st.pop();
            else if (part != "..") st.push(part);
        }
        part = "";
        while (!st.empty())
        {
            part = "/" + st.top() + part;
            st.pop();
        }
        return part != "" ? part : "/";
    }
};
