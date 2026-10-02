class Solution {
public:
    typedef pair<int, int> pii;

    pii getCoord(int blockNo, int n){
        blockNo--;
        bool parity = (blockNo / n) & 1;
        if(parity)
            return {n - blockNo/n - 1, (blockNo/n + 1)*(n) - blockNo - 1};
        else
            return {n - blockNo/n - 1, blockNo - blockNo/n * n};
    }

    int getBlockNo(int x, int y, int n){
        bool parity = (x & 1);
        if(n & 1)
            parity = parity ^ 1;
        if(parity)
            return ((n - x - 1)*n) + y + 1;
        else
            return ((n - x - 1)*n) + (n - y - 1) + 1;
    }
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<vector<bool>> vis(n, vector<bool>(n));
        vis[n-1][0] = true;
        queue<int> q;
        q.push(1);
        int level = 0;
        while(!q.empty()){
            int qs = q.size();
            for(int qi = 0;qi<qs;qi++){
                int u = q.front();
                q.pop();
                if(u == n*n)
                    return level;
                pii coord = getCoord(u, n);
                int x = coord.first, y = coord.second;
                for(int i = 1;i<=6;i++){
                    int v = u + i;
                    if(v > n*n)
                        break;
                    pii newCoord = getCoord(v, n);
                    int nx = newCoord.first, ny = newCoord.second;
                    if(board[nx][ny] != -1){
                        if(getBlockNo(nx ,ny, n) == n*n){
                            q.push(n*n);
                            continue;
                        }
                        newCoord = getCoord(board[nx][ny], n);
                        nx = newCoord.first, ny = newCoord.second;
                    }
                    if(!vis[nx][ny]){
                        q.push(getBlockNo(nx, ny, n));
                        vis[nx][ny] = true;
                    }
                }
            }
            level++;
        }
        return -1;
    }
};