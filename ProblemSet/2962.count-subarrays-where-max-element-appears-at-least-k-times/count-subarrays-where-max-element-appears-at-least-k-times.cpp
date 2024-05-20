class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long result=0;
        int mx=*max_element(nums.begin(),nums.end());
        int n=nums.size();
        int cnt=0;
        int j=0;
        for(int i:nums)
        {
            while(j<n&&cnt<k)
            {
                if(nums[j]==mx)
                    cnt++;
                j++;
            }
            if(cnt<k)
                break;
            result+=n-j+1;
            if(i==mx)
                cnt--;
        }
        return result;
    }
};