class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> results;
        if(k>n||k<0) return results;
        else if(k==0)
        {
            results.push_back(vector<int>());
            return results;
        }
        results=combine(n-1,k-1);
        for(auto &result:results) result.push_back(n);
        for(auto &result:combine(n-1,k)) results.push_back(result);
        return results;
    }
};