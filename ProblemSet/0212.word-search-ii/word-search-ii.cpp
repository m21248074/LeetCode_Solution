class Trie
{
    public:
        Trie *child[26];
        string str;
        Trie()
        {
            for(int i=0;i<26;i++)
                child[i]=nullptr;
            str="";
        }
        void insert(string s)
        {
            Trie *p=this;
            for(char c:s)
            {
                int i=c-'a';
                if(!p->child[i]) p->child[i]=new Trie();
                p=p->child[i];
            }
            p->str=s;
        }
};

class Solution {
public:
    void search(vector<vector<char>>& board,Trie *p,int i,int j,vector<vector<bool>>& isVisited,vector<string>& result)
    {
        int m=board.size();
        int n=board[0].size();
        if(!p->str.empty())
        {
            result.push_back(p->str);
            p->str.clear();
        }
        isVisited[i][j]=true;
        int dirs[5]={1,0,-1,0,1};
        for(int k=0;k<4;k++)
        {
            int new_i=i+dirs[k];
            int new_j=j+dirs[k+1];
            if(new_i>=0&&new_i<m&&new_j>=0&&new_j<n&&!isVisited[new_i][new_j]&&p->child[board[new_i][new_j]-'a'])
                search(board,p->child[board[new_i][new_j]-'a'],new_i,new_j,isVisited,result);
        }
        isVisited[i][j]=false;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> result;
        int m=board.size();
        int n=board[0].size();
        vector<vector<bool>> isVisited(m,vector<bool>(n,false));
        Trie t;
        for(string word:words) t.insert(word);
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(t.child[board[i][j]-'a'])
                {
                    search(board,t.child[board[i][j]-'a'],i,j,isVisited,result);
                    if(result.size()>=words.size())
                        return result;
                }
            }
        }
        return result;
    }
};