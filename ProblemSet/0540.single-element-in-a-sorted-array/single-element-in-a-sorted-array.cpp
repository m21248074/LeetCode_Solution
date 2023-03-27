class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int left=0;
        int right=n-1;
        while(left<right)
        {
            int mid=(left+right)/2;
            if(nums[mid]==nums[mid+1])
            {
                if((n-1-mid)%2)
                    right=mid; // to left
                else
                    left=mid+1;// to right
            }
            else
            {
                if(mid==0||nums[mid]!=nums[mid-1])
                    return nums[mid];
                if((n-1-mid)%2)
                    left=mid+1;
                else
                    right=mid;
            }
        }
        return nums[left];
    }
};