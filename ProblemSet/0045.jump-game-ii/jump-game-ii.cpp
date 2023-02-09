class Solution {
public:
    int jump(vector<int>& nums) {
        int result=0;
        int n=nums.size();
        int i=0;
        int cur=0;
        while(cur<n-1)
        {
            result++;
            int pre=cur;
            for(;i<=pre;i++)
                cur=max(cur,i+nums[i]);
        }
        return result;
    }
};