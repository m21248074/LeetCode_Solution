class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,vector<int>> um;
        for(int i=0;i<n;i++)
            um[arr[i]].push_back(i);
        vector<bool> visited(n,false);
        visited[0]=true;
        queue<int> q;
        q.push(0);
        int step=0;
        while(!q.empty())
        {
            for(int i=q.size();i>0;i--)
            {
                int temp=q.front();
                q.pop();
                if(temp==n-1)
                    return step;
                vector<int> &next=um[arr[temp]];
                next.push_back(temp-1);
                next.push_back(temp+1);
                for(int j:next)
                {
                    if(j>=0&&j<n&&!visited[j])
                    {
                        visited[j]=true;
                        q.push(j);
                    }
                }
                next.clear();
            }
            step++;
        }
        return 0;
    }
};