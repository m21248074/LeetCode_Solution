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
    void moveZeroes(vector<int>& nums) {
        int index=removeElement(nums,0);
        for(int i=index;i<nums.size();i++)
            nums[i]=0;
    }
};