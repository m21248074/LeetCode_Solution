class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int left=0;
        int right=0;
        int cnt=0;
        int result=0;
        while(right<n)
        {
            if(nums[right]==0)
            {
                cnt++;
                if(cnt>1)
                {
                    while(nums[left]==1)
                        left++;
                    left++;
                    cnt--;
                }
            }
            right++;
            result=max(result,right-left-1);
        }
        return result;
    }
};