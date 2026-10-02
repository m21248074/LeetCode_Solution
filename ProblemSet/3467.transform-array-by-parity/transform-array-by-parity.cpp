class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int x=0;
        int y=0;
        for(int num:nums)
        {
            if(num%2)
                y++;
            else
                x++;
        }
        vector<int> result;
        for(int i=0;i<x;i++)
            result.push_back(0);
        for(int i=0;i<y;i++)
            result.push_back(1);
        return result;
    }
};