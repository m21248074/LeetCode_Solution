class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        stack<vector<int>> result;
        sort(pairs.begin(),pairs.end(),[&](vector<int> &a,vector<int> &b)->bool{
            return a[1]<b[1];
        });
        for(auto pair:pairs)
        {
            if(result.empty()) result.push(pair);
            else
                if(pair[0]>result.top()[1]) result.push(pair);
        }
        return result.size();
    }
};