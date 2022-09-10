class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        priority_queue<pair<long,int>,vector<pair<long,int>>,greater<pair<long,int>>> usingRoom; // {end time,room number}
        priority_queue<int,vector<int>,greater<int>> unusedRoom;
        unordered_map<int,int> cnts; // <room number,used times>

        for(int i=0;i<n;i++)
            unusedRoom.push(i);
        for(auto m:meetings)
        {
            int start=m[0],end=m[1];
            while(!usingRoom.empty()&&usingRoom.top().first<=start)
            {
                int room=usingRoom.top().second;
                usingRoom.pop();
                unusedRoom.push(room);
            }
            if(!unusedRoom.empty())
            {
                int room=unusedRoom.top();
                unusedRoom.pop();
                cnts[room]++;
                usingRoom.push({end,room});
            }
            else
            {
                pair<long,int> top=usingRoom.top();
                usingRoom.pop();
                cnts[top.second]++;
                long newEnd=top.first+(end-start);
                usingRoom.push({newEnd,top.second});
            }
        }
        int result=0;
        for(int i=1;i<n;i++)
        {
            if(cnts[i]>cnts[result])
                result=i;
        }
        return result;
    }
};