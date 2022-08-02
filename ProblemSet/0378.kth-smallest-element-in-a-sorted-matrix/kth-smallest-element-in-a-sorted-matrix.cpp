class Solution {
public:
    int countSmallerOrEqual(vector<vector<int>>& matrix,int value)
    {
        int n=matrix.size();
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]<=value)
                    count++;
            }
        }
        return count;
    }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        if(n==1) return matrix[0][0];
        int l=matrix[0][0],r=matrix[n-1][n-1];
        while(l<r)
        {
            int m=(l+r)/2;
            if(m<0)
                m=((l+r)%2)?m-1:m;
            int count=countSmallerOrEqual(matrix,m);
            if(count<k)
                l=m+1;
            else if(count>=k)
                r=m;
        }
        return l;
    }
};