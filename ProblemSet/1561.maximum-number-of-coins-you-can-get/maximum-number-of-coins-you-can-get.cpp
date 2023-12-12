class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n=piles.size();
        int l=0;
        int r=n-1;
        sort(piles.begin(),piles.end());
        int result=0;
        int count=n/3;
        while(l<r&&count!=0)
        {
            if(l<r-1)
            {
                result+=piles[r-1];
                count--;
            }
            l++;
            r-=2;
        }
        return result;
    }
};