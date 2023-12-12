class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<int> colCount(n);
        int result=0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j])
                    colCount[j]+=1;
                else
                    colCount[j]=0;
            }
            auto temp=colCount;
            sort(temp.begin(),temp.end(),greater<int>());
            for(int j=0;j<n;j++)
            {
                int area=(j+1)*temp[j];
                result=max(result,area);
            }
        }
        return result;
    }
};