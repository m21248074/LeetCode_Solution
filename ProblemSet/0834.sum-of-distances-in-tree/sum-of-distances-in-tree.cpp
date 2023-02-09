class Solution {
public:
    void helper(vector<vector<int>>& tree,int cur,int pre,vector<int>& count,vector<int>& result)
    {
        for(int i:tree[cur])
        {
            if(i==pre) continue;
            helper(tree,i,cur,count,result);
            count[cur]+=count[i];
            result[cur]+=result[i]+count[i];
        }
        count[cur]++;
    }
    void helper2(vector<vector<int>>& tree,int cur,int pre,vector<int>& count,vector<int>& result)
    {
        for(int i:tree[cur])
        {
            if(i==pre) continue;
            result[i]=result[cur]-count[i]+count.size()-count[i];
            helper2(tree,i,cur,count,result);
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> result(n);
        vector<int> count(n);
        vector<vector<int>> tree(n);
        for(auto edge:edges)
        {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
        }
        helper(tree,0,-1,count,result);
        helper2(tree,0,-1,count,result);
        return result;
    }
};