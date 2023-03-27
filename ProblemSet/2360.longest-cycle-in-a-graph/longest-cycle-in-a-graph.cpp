class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        int result=-1;
        vector<int> temp(n);
        for(int edge:edges)
        {
            if(edge!=-1)
                temp[edge]++;
        }
        vector<int> visited(n);
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(!temp[i])
            {
                visited[i]=1;
                q.push(i);
            }
        }
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            int y=edges[x];
            if(y==-1)
                continue;
            temp[y]--;
            if(!temp[y])
            {
                visited[y]=1;
                q.push(y);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(visited[i])
                continue;
            int j=i;
            int count=1;
            visited[j]=1;
            while(edges[j]!=-1&&!visited[edges[j]])
            {
                count++;
                j=edges[j];
                visited[j]=1;
            }
            result=max(result,count);
        }
        return result;
    }
};