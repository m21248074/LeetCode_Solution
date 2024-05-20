class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n=heights.size();
        int cur=0;
        int sum=0;
        priority_queue<int> pq;
        for(;cur<n-1;cur++)
        {
            if(heights[cur+1]>heights[cur])
            {
                int diff=heights[cur+1]-heights[cur];
                bricks-=diff;
                pq.push(diff);
                if(bricks<0)
                {
                    bricks+=pq.top();
                    pq.pop();
                    ladders--;
                }
                if(ladders<0)
                    break;
            }
        }
        return cur;
    }
};