class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int result=0;
        int n=img1.size();
        vector<vector<int>> list1,list2;
        unordered_map<string,int> um;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(img1[i][j]) list1.push_back({i,j});
                if(img2[i][j]) list2.push_back({i,j});
            }
        }
        for(auto x:list1)
            for(auto y:list2) um[to_string(x[0]-y[0])+"-"+to_string(x[1]-y[1])]++;
        for(auto i:um)
            result=max(result,i.second);
        return result;
    }
};