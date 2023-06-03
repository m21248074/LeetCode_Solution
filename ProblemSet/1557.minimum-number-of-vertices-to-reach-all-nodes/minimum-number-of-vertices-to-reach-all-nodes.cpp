class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        set<int> in,out;
        vector<int> result;
        for(auto edge:edges)
        {
            // out -> in
            out.insert(edge[0]);
            in.insert(edge[1]);
        }
        set_difference(out.begin(),out.end(),in.begin(),in.end(),inserter(result,result.end()));
        return result;
    }
};