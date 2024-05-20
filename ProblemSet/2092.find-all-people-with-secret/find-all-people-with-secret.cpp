class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<int> parents(n);
        for(int i=0;i<n;i++)
            parents[i]=i;
        sort(meetings.begin(),meetings.end(),[](vector<int> a,vector<int> b){
            return a[2]<b[2];
        });
        function<int(int)> find=[&](int x)->int{
            if(x!=parents[x])
                parents[x]=find(parents[x]);
            return parents[x];
        };
        function<void(int,int)> unions=[&](int a,int b){
            parents[find(a)]=find(b);
        };
        parents[firstPerson]=0;
        for(int i=0;i<meetings.size();i++)
        {
            int j=i;
            while(j<meetings.size()&&meetings[i][2]==meetings[j][2])
            {
                int a=meetings[j][0];
                int b=meetings[j][1];
                unions(a,b);
                j++;
            }
            j=i;
            int parent0=find(0);
            while(j<meetings.size()&&meetings[i][2]==meetings[j][2])
            {
                int a=meetings[j][0];
                int b=meetings[j][1];
                if(find(a)!=parent0)
                    parents[a]=a;
                if(find(b)!=parent0)
                    parents[b]=b;
                j++;
            }
            i=j-1;
        }
        vector<int> result;
        int parent0=find(0);
        for(int i=0;i<n;i++)
        {
            if(parent0==find(i))
                result.push_back(i);
        }
        return result;
    }
};