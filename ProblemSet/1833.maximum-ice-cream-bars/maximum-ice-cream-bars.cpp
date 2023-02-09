class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int result=0;
        sort(costs.begin(),costs.end());
        for(int cost:costs)
        {
            if(cost>coins)
                return result;
            else
            {
                result++;
                coins-=cost;
            }
        }
        return result;
    }
};