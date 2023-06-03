class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int,vector<int>> um;
        for(int i=0;i<n;i++)
            um[manager[i]].push_back(i);
        function<int(int)> dfs=[&](int cur)->int{
            int r=0;
            if(!um.count(cur)) return r;
            for(int i=0;i<um[cur].size();i++)
                r=max(r,dfs(um[cur][i]));
            return r+informTime[cur];
        };
        return dfs(headID);
    }
};