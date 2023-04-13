class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        
        int back = people.size() - 1;
        int front = 0;
        int ans = 0;
        
        sort(people.begin(),people.end());
        
        while (front <= back)
        {
            ans++;
            int redund = limit - people[back--];
            if (redund >= people[front])
                front++;
        }
        
        return ans;
    }
};
