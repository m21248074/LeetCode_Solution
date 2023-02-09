class Solution {
public:
    int longestPath(vector<int>& parent, string s) {
        int n=s.length();
        int result=0;
        vector<vector<int>> children(n,vector<int>());
        for(int i=0;i<n;i++)
            if(parent[i]!=-1) children[parent[i]].push_back(i);
        function<int(int)> helper=[&](int i)-> int
        {
            int big1=0;
            int big2=0;
            for(int j:children[i])
            {
                int cur=helper(j);
                if(s[i]==s[j]) continue;
                if(cur>big2) big2=cur;
                if(big2>big1) swap(big1,big2);
            }
            result=max(result,big1+big2+1);
            return big1+1;
        };
        helper(0);
        return result;
    }
};