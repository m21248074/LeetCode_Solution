class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int result=0;
        int keyCnt=0;
        queue<pair<int,int>> q;
        unordered_set<string> visited;
        vector<int> dirs({-1,0,1,0,-1});
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='@')
                {
                    q.push({i*n+j,0});
                    visited.insert(to_string(i*n+j)+"_0");
                }
                if(grid[i][j]>='a'&&grid[i][j]<='f') keyCnt++;
            }
        }
        while(!q.empty())
        {
            for(int i=q.size();i>0;i--)
            {
                int t=q.front().first;
                int curKeys=q.front().second;
                q.pop();
                if(curKeys==(1<<keyCnt)-1) return result;
                for(int j=0;j<4;j++)
                {
                    int x=t/n+dirs[j];
                    int y=t%n+dirs[j+1];
                    int keys=curKeys;
                    if(x<0||x>=m||y<0||y>=n) continue;
                    char c=grid[x][y];
                    if(c=='#') continue;
                    if(c>='A'&&c<='F'&&((keys>>(c-'A'))&1)==0) continue;
                    if(c>='a'&&c<='f') keys|=1<<(c-'a');
                    string str=to_string(x*n+y)+"_"+to_string(keys);
                    if(!visited.count(str))
                    {
                        visited.insert(str);
                        q.push({x*n+y,keys});
                    }
                }
            }
            result++;
        }
        return -1;
    }
};