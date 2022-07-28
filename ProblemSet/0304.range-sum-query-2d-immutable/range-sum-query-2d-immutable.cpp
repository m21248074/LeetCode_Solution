class NumMatrix {
private:
    vector<vector<int>> preMatrix;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        preMatrix=vector<vector<int>>(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                preMatrix[i][j]=preMatrix[i][j-1]+preMatrix[i-1][j]+matrix[i-1][j-1]-preMatrix[i-1][j-1];
            }
        }
    }
    int sumRegion(int row1, int col1, int row2, int col2) {
        return preMatrix[row2+1][col2+1]-preMatrix[row1][col2+1]-preMatrix[row2+1][col1]+preMatrix[row1][col1];
    }
};
/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */