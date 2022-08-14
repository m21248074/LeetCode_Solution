class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int src_r=mat.size();
        int src_c=mat[0].size();
        if(r*c!=src_r*src_c) return mat;
        vector<vector<int>> result(r,vector<int>(c,0));
        for(int i=0;i<src_r;i++)
        {
            for(int j=0;j<src_c;j++)
            {
                int index=i*src_c+j;
                result[index/c][index%c]=mat[i][j];
            }
        }
        return result;
    }
};