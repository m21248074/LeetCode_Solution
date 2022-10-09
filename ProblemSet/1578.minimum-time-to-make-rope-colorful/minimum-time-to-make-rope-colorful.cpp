class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n=colors.length();
        int result=0;
        if(n==1) return result;
        char cur=colors[0];
        int time=neededTime[0];
        for(int i=1;i<n;i++)
        {
            if(colors[i]==cur)
            {
                if(neededTime[i]<=time)
                    result+=neededTime[i];
                else // neededTime[i]>time
                {
                    result+=time;
                    time=neededTime[i];
                }
            }
            else // colors[i]!=cur
            {
                cur=colors[i];
                time=neededTime[i];
            }
        }
        return result;
    }
};