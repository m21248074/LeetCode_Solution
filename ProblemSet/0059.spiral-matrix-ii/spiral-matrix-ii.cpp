class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n,vector<int>(n));
        int value=1;
        int up=0,down=n-1,left=0,right=n-1;
        while(true)
        {
            for(int i=left;i<=right;i++)
            {
                result[up][i]=value;
                value++;
            }
            up++;
            if(up>down) break;
            for(int i=up;i<=down;i++)
            {
                result[i][right]=value;
                value++;
            }
            right--;
            if(right<left) break;
            for(int i=right;i>=left;i--)
            {
                result[down][i]=value;
                value++;
            }
            down--;
            if(down<up) break;
            for(int i=down;i>=up;i--)
            {
                result[i][left]=value;
                value++;
            }
            left++;
            if(right<left) break;
        }
        return result;
    }
};