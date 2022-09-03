class Solution {
public:
    void helper(int cur,int acc,int len,vector<int>& result,int n,int k)
    {
        if(len==n)
        {
            if(find(result.begin(),result.end(),acc)==result.end())
                result.push_back(acc);
            return;
        }
        if(cur+k<=9)
            helper(cur+k,acc*10+cur+k,len+1,result,n,k);
        if(cur-k>=0)
            helper(cur-k,acc*10+cur-k,len+1,result,n,k);
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> result;
        for(int i=1;i<=9;i++)
            helper(i,i,1,result,n,k);
        return result;
    }
};