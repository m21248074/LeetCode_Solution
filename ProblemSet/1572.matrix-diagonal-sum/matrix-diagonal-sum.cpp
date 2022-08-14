class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n=mat.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            int temp=mat[i][i]+mat[i][n-i-1];
            sum+=(i==n-i-1)?temp/2:temp;
        }
        return sum;
    }
};