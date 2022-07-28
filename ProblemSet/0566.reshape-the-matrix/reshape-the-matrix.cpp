class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int m=mat.size(),n=mat[0].size();
        if(r*c!=m*n) return mat;
        vector<vector<int>> result(r,vector<int>(c,0));
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                int k=i*c+j;
                result[i][j]=mat[k/n][k%n];
            }
        }
        return result;
    }
};