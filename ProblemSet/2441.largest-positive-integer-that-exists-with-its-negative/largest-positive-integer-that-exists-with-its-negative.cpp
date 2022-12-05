class Solution {
public:
    int findMaxK(vector<int>& nums) {
        set<int> s;
        priority_queue<int> pq;
        for(int num:nums)
        {
            if(num<0)
                s.insert(num);
            else
                pq.push(num);
        }
        while(!pq.empty())
        {
            int top=pq.top();
            if(s.count(-top))
                return top;
            pq.pop();
        }
        return -1;
    }
};