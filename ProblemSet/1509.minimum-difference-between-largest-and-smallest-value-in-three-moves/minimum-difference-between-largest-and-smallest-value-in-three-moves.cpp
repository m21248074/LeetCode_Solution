class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if (n <= 4) return 0;
        sort(nums.begin(), nums.end());
        int minDiff = INT_MAX;
        for (int left = 0, right = n - 4; left < 4; left++, right++)
            minDiff = min(minDiff, nums[right] - nums[left]);
        return minDiff;
    }
};