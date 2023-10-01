class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n=nums.size();
        bool a=true;
        bool b=true;
        for(int i=1;i<n;i++)
        {
            a&=nums[i-1]<=nums[i];
            b&=nums[i-1]>=nums[i];
            if(!a&&!b) return false;
        }
        return true;
    }
};