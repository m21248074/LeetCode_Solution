class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        vector<int> max_nums(n,0);
        vector<int> min_nums(n,0);
        int result=max_nums[0]=min_nums[0]=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            max_nums[i]=max(max(max_nums[i-1]*nums[i],min_nums[i-1]*nums[i]),nums[i]);
            min_nums[i]=min(min(max_nums[i-1]*nums[i],min_nums[i-1]*nums[i]),nums[i]);
            result=max(result,max_nums[i]);
        }
        return result;
    }
};