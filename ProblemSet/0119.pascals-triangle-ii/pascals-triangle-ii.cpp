class Solution {
public:
    vector<int> helper(vector<vector<int>>& dp,int rowIndex)
    {
        if(!dp[rowIndex].size())
        {
            vector<int> temp;
            for(int i=0;i<rowIndex+1;i++)
            {
                if(i==0||i==rowIndex)
                    temp.push_back(1);
                else
                {
                    helper(dp,rowIndex-1);
                    temp.push_back(dp[rowIndex-1][i-1]+dp[rowIndex-1][i]);
                }
            }
            dp[rowIndex]=temp;
        }
        return dp[rowIndex];
    }
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> dp(rowIndex+1,vector<int>());
        return helper(dp,rowIndex);
    }
};