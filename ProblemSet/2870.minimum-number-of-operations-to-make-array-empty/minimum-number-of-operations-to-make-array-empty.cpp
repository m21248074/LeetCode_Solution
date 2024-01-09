class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int result=0;
        int i=0;
        while(i<n)
        {
            int j=i;
            while(j<n&&nums[i]==nums[j])
                j++;
            int cnt=j-i;
            if(cnt==1) return -1;
            result+=cnt/3;
            if(cnt%3!=0)
                result++;
            i=j;
        }
        return result;
    }
};