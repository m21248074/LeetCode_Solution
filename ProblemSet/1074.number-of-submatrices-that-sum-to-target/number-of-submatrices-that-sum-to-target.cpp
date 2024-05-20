class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int result=0;
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> prefixSums(m+1,vector<int>(n+1));
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
                prefixSums[i][j]=prefixSums[i-1][j]+prefixSums[i][j-1]-prefixSums[i-1][j-1]+matrix[i-1][j-1];
        }
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                for(int p=1;p<=i;p++)
                {
                    for(int q=1;q<=j;q++)
                    {
                        int t=prefixSums[i][j]-prefixSums[i][q-1]-prefixSums[p-1][j]+prefixSums[p-1][q-1];
                        if(t==target)
                            result++;
                    }
                }
            }
        }
        return result;
    }
};