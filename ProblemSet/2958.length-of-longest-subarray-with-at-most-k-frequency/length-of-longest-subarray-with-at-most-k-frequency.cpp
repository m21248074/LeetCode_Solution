class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int left=0;
        int right=0;
        int result=0;
        int n=nums.size();
        unordered_map<int,int> um;
        while(right<n)
        {
            int temp=nums[right++];
            um[temp]++;
            while(um[temp]>k)
            {
                um[nums[left]]--;
                left++;
            }
            result=max(result,right-left);
        }
        return result;
    }
};