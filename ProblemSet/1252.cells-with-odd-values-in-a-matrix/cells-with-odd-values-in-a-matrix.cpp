class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<vector<int>> matrix(m,vector<int>(n,0));
        for(auto i:indices)
        {
            int ri=i[0],ci=i[1];
            for(int j=0;j<n;j++)
                matrix[ri][j]++;
            for(int j=0;j<m;j++)
                matrix[j][ci]++;
        }
        int cnt=0;
        for(auto row:matrix)
        {
            for(int element:row)
                if(element%2) cnt++;
        }
        return cnt;
    }
};