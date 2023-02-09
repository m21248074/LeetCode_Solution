class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        vector<bool> visited(n,false);
        int count=n;
        stack<int> s;
        s.push(0);
        while(!s.empty())
        {
            int top=s.top();
            s.pop();
            if(visited[top])
                continue;
            visited[top]=true;
            count--;
            for(int key:rooms[top])
                s.push(key);
        }
        return count==0;
    }
};