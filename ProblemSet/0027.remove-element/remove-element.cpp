class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow,fast;
        slow=fast=0;
        while(fast!=nums.size())
        {
            if(nums[fast]!=val)
            {
                nums[slow]=nums[fast];
                slow++;
            }
            fast++;
        }
        return slow;
    }
};