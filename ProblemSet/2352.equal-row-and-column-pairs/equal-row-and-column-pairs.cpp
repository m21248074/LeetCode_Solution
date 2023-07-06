class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int result=0;
        map<vector<int>,int> m;
        int n=grid.size();
        for(int i=0;i<n;i++)
            m[grid[i]]++;
        for(int i=0;i<n;i++)
        {
            vector<int> t;
            for(int j=0;j<n;j++)
                t.push_back(grid[j][i]);
            result+=m[t];
        }
        return result;
    }
};