class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        int result=0;
        queue<int> q;
        q.push(1);
        vector<bool> visited(n*n+1);
        function<int(int)> getPos=[&](int num){
            int x=(num-1)/n;
            int y=(num-1)%n;
            if(x%2==1)
                y=n-1-y;
            x=n-1-x;
            return board[x][y];
        };
        while(!q.empty())
        {
            int size=q.size();
            for(int i=0;i<size;i++)
            {
                int num=q.front();
                q.pop();
                if(num==n*n) // reach the finish point
                    return result;
                for(int j=1;j<=6 && num+j<=n*n;j++)
                {
                    int next=getPos(num+j);
                    if(next==-1) next=num+j;
                    if(visited[next])
                        continue;
                    visited[next]=true;
                    q.push(next);
                }
            }
            result++;
        }
        return -1;
    }
};