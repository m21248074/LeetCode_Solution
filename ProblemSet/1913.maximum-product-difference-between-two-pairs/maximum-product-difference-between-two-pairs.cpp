class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int n=nums.size();
        sort(nums.rbegin(),nums.rend());
        return nums[0]*nums[1]-nums[n-1]*nums[n-2];
    }
};