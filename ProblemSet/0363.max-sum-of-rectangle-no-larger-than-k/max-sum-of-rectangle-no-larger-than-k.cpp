class Solution {
public:
    int helper(vector<int> &nums,int k)
    {
        set<int> s;
        s.insert(0);
        int prefixSum=0;
        int result=INT_MIN;
        for(int i=0;i<nums.size();i++)
        {
            prefixSum+=nums[i];
            auto iter=s.lower_bound(prefixSum-k);
            if(iter!=s.end())
                result=max(result,prefixSum-*iter);
            s.insert(prefixSum);
        }
        return result;
    }
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m=matrix.size();
        int n=matrix[0].size();

        if(m>n)
        {
            vector<vector<int>> t(n,vector<int>(m,0));
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                    t[j][i]=matrix[i][j];
            }
            return maxSumSubmatrix(t,k);
        }

        int result=INT_MIN;

        for(int i=0;i<m;i++)
        {
            vector<int> temp(n,0);
            for(int j=i;j<m;j++)
            {
                for(int k=0;k<n;k++)
                    temp[k]+=matrix[j][k];
                result=max(result,helper(temp,k));
            }
        }
        return result;
    }
};