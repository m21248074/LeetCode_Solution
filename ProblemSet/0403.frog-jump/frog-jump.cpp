class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n=stones.size();
        unordered_map<int,bool> um;
        function<bool(int,int)> helper=[&](int pos,int jump)->bool{
            int key=pos|jump<<11;
            if(pos>=n-1) return true;
            if(um.count(key)) return um[key];
            for(int i=pos+1;i<n;i++)
            {
                int dist=stones[i]-stones[pos];
                if(dist<jump-1) continue;
                if(dist>jump+1) return um[key]=false;
                if(helper(i,dist)) return um[key]=true;
            }
            return um[key]=false;
        };
        return helper(0,0);
    }
};