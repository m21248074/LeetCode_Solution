class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n=nums.size();
        vector<int> result(n);
        for(int i=1,sum=0;i<n;i++)
            result[i]+=(sum+=(nums[i]-nums[i-1])*i);
        for(int i=n-2,sum=0;i>=0;i--)
            result[i]+=(sum+=(nums[i+1]-nums[i])*(n-i-1));
        return result;
    }
};