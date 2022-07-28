class Solution {
public:
    int left_bound(vector<int>& nums, int target)
    {
        if(!nums.size()) return -1;
        int left=0,right=nums.size();
        while(left<right)
        {
            int mid=(left+right)/2;
            if(nums[mid]==target)
                right=mid;
            else if(nums[mid]>target)
                right=mid;
            else // nums[mid]<target
                left=mid+1;
        }
        if(left==nums.size()) return -1;
        return (nums[left]==target)?left:-1;
    }
    int right_bound(vector<int>& nums, int target)
    {
        if(!nums.size()) return -1;
        int left=0,right=nums.size();
        while(left<right)
        {
            int mid=(left+right)/2;
            if(nums[mid]==target)
                left=mid+1;
            else if(nums[mid]>target)
                right=mid;
            else // nums[mid]<target
                left=mid+1;
        }
        if(!left) return -1;
        return (nums[left-1]==target)?left-1:-1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        return vector<int>({left_bound(nums,target),right_bound(nums,target)});
    }
};