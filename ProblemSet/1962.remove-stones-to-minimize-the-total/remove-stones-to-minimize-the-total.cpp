class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int n=piles.size();
        priority_queue<int> pq;
        for(int i=0;i<n;i++)
            pq.push(piles[i]);
        for(int i=0;i<k;i++)
        {
            int top=pq.top();
            pq.pop();
            top-=top/2;
            pq.push(top);
        }
        int result=0;
        while(!pq.empty())
        {
            int top=pq.top();
            pq.pop();
            result+=top;
        }
        return result;
    }
};