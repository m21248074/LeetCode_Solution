class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int result=0;
        int n=tickets.size();
        while(1)
        {
            for(int i=0;i<n;i++)
            {
                if(tickets[i])
                {
                    result++;
                    tickets[i]--;
                    if(i==k&&!tickets[k])
                        return result;
                }
            }
        }
        return -1;
    }
};