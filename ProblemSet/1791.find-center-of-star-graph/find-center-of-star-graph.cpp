class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n=edges.size();
        unordered_map<int,int> um;
        for(auto edge:edges)
        {
            um[edge[0]]++;
            um[edge[1]]++;
        }
        int result=0;
        for(auto i:um)
        {
            if(um[result]<i.second)
                result=i.first;
        }
        return result;
    }
};