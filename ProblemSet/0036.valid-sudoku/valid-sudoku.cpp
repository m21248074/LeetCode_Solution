class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        set<string> s;
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.') continue;
                string p="("+to_string(board[i][j])+")";
                string row=to_string(i)+p,column=p+to_string(j),box=to_string(i/3)+p+to_string(j/3);
                if(s.count(row)||s.count(column)||s.count(box)) return false;
                s.insert(row);
                s.insert(column);
                s.insert(box);
            }
        }
        return true;
    }
};