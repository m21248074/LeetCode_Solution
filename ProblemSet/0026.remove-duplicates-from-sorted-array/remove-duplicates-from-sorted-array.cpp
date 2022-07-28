class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow,fast;
        slow=fast=0;
        while(fast!=nums.size())
        {
            if(nums[slow]!=nums[fast])
            {
                slow++;
                nums[slow]=nums[fast];
            }
            fast++;
        }
        return slow+1;
    }
};