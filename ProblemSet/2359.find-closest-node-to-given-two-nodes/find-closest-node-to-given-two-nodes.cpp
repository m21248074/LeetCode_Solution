class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<int> v1(n,-1);
        vector<int> v2(n,-1);
        int temp=node1;
        v1[node1]=0;
        v2[node2]=0;
        while(edges[temp]!=-1&&v1[edges[temp]]==-1)
        {
            v1[edges[temp]]=v1[temp]+1;
            temp=edges[temp];
        }
        temp=node2;
        while(edges[temp]!=-1&&v2[edges[temp]]==-1)
        {
            v2[edges[temp]]=v2[temp]+1;
            temp=edges[temp];
        }
        int distance=INT_MAX;
        int result=0;
        for(int i=0;i<n;i++)
        {
            if(v1[i]==-1||v2[i]==-1) continue;
            temp=max(v1[i],v2[i]);
            if(distance>temp)
            {
                distance=temp;
                result=i;
            }
        }
        return distance==INT_MAX?-1:result;
    }
};