class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n=nums.size();
        function<int(int)> helper=[&](int l)->int{
            int result=0;
            int left=0;
            unordered_map<int,int> um;
            for(int i=0;i<n;i++)
            {
                if(um[nums[i]]==0)
                    l--;
                um[nums[i]]++;
                while(l<0)
                {
                    if(--um[nums[left]]==0)
                        l++;
                    left++;
                }
                result+=i-left+1;
            }
            return result;
        };
        return helper(k)-helper(k-1);
    }
};