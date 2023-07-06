class Solution {
public:
    void dfs(int city,set<int>& s,vector<vector<int>>& isConnected)
    {
        if(!s.count(city)) return;
        s.erase(city);
        int n=isConnected.size();
        for(int i=0;i<n;i++)
        {
            if(isConnected[city][i])
                dfs(i,s,isConnected);
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        set<int> s;
        for(int i=0;i<n;i++) s.insert(i);
        int result=0;
        while(!s.empty())
        {
            dfs(*s.begin(),s,isConnected);
            result++;
        }
        return result;
    }
};