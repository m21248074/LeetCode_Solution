class UnionFind
{
    private:
        unordered_map<int,int> parent;
        int cnt;
    public:
        UnionFind()
        {
            cnt=0;
        }
        int find(int node)
        {
            if(!parent.count(node))
            {
                parent[node]=node;
                cnt++;
            }
            if(node!=parent[node])
                parent[node]=find(parent[node]);
            return parent[node];
        }
        void union_stones(int a,int b)
        {
            int rootA=find(a);
            int rootB=find(b);
            if(rootA==rootB)
                return;
            parent[rootA]=rootB;
            cnt--;
        }
        int getCount()
        {
            return cnt;
        }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        UnionFind uf;
        for(auto stone:stones)
            uf.union_stones(stone[0]+10001,stone[1]);
        return stones.size()-uf.getCount();
    }
};