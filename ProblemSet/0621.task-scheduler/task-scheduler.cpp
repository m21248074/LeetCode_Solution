class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> um;
        for(auto task:tasks) um[task]++;
        priority_queue<int> pq;
        for(auto i:um)
            pq.push(i.second);
        int result=0;
        while(!pq.empty())
        {
            vector<int> temp;
            int time=0; // time actually spent on the task
            for(int i=0;i<n+1;i++)
            {
                if(!pq.empty())
                {
                    temp.push_back(pq.top());
                    pq.pop();
                    time++;
                }
            }
            for(int t: temp)
            {
                t--;
                if(t)
                    pq.push(t);
            }
            result+=pq.empty()?time:n+1;
        }
        return result;
    }
};