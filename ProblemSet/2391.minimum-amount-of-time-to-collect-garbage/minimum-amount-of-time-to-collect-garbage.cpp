class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n=garbage.size();
        int lastM=-1;
        int lastP=-1;
        int lastG=-1;
        int result=0;
        vector<int> M(n);
        vector<int> P(n);
        vector<int> G(n);
        for(int i=0;i<n;i++)
        {
            for(char c:garbage[i])
            {
                if(c=='M')
                {
                    M[i]++;
                    lastM=i;
                }
                else if(c=='P')
                {
                    P[i]++;
                    lastP=i;
                }
                else
                {
                    G[i]++;
                    lastG=i;
                }
            }
        }
        if(lastM!=-1)
            result+=M[0];
        if(lastP!=-1)
            result+=P[0];
        if(lastG!=-1)
            result+=G[0];
        for(int i=1;i<=lastM;i++)
            result+=M[i]+travel[i-1];
        for(int i=1;i<=lastP;i++)
            result+=P[i]+travel[i-1];
        for(int i=1;i<=lastG;i++)
            result+=G[i]+travel[i-1];
        return result;
    }
};