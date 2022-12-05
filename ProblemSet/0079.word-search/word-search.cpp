class Solution {
public:
    bool search(vector<vector<char>>& board,string word,int idx,int i,int j,vector<vector<bool>>& visited)
    {
        if(word.length()==idx) return true;
        int m=board.size();
        int n=board[0].size();
        if(i<0||i>=m||j<0||j>=n||visited[i][j]||board[i][j]!=word.at(idx)) return false;
        visited[i][j]=true;
        bool result=search(board,word,idx+1,i-1,j,visited);
        result|=search(board,word,idx+1,i+1,j,visited);
        result|=search(board,word,idx+1,i,j-1,visited);
        result|=search(board,word,idx+1,i,j+1,visited);
        visited[i][j]=false;
        return result;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        for(int i=0;i<m;i++) for(int j=0;j<n;j++) if(search(board,word,0,i,j,visited)) return true;
        return false;
    }
};