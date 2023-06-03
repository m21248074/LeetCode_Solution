class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int result=INT_MIN;
        int n=bombs.size();
        set<int> s;
        function<int(int)> dfs=[&](int i)->int{
            int result=1;
            for(int j=0;j<n;j++)
            {
                if(j==i||s.count(j)) continue;
                long long dx=bombs[i][0]-bombs[j][0];
                long long dy=bombs[i][1]-bombs[j][1];
                long long len=bombs[i][2];
                if(dx*dx+dy*dy<=len*len)
                {
                    s.insert(j);
                    result+=dfs(j);
                }
            }
            return result; 
        };
        for(int i=0;i<n;i++)
        {
            s.clear();
            s.insert(i);
            result=max(result,dfs(i));
        }
        return result;
    }
};