class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        long long result=0;
        unordered_map<int,unordered_set<int>> um;
        for(auto road:roads)
        {
            um[road[0]].insert(road[1]);
            um[road[1]].insert(road[0]);
        }
        function<int(int,int)> helper=[&](int i,int prev)
        {
            int ppl=1;
            for(int j:um[i])
            {
                if(j==prev) continue;
                ppl+=helper(j,i);
            }
            if(i!=0)
                result+=(ppl+seats-1)/seats;
            return ppl;
        };
        helper(0,0);
        return result;
    }
};