class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int> difference;
        int result=0;
        int n=capacity.size();
        for(int i=0;i<n;i++)
            difference.push_back(capacity[i]-rocks[i]);
        sort(difference.begin(),difference.end());
        for(int d:difference)
        {
            if(d==0)
                result++;
            else if(d>0&&additionalRocks>=d)
            {
                result++;
                additionalRocks-=d;
            }
        }
        return result;
    }
};