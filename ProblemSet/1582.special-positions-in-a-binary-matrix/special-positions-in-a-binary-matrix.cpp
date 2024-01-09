class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int result=0;
        int m=mat.size();
        int n=mat[0].size();
        vector<int> rowCnt(m);
        vector<int> colCnt(n);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                rowCnt[i]+=mat[i][j];
                colCnt[j]+=mat[i][j];
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
                if(mat[i][j]&&rowCnt[i]+colCnt[j]==2) result++;
        }
        return result;
    }
};