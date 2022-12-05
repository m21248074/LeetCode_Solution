class Solution {
public:
    int averageValue(vector<int>& nums) {
        int n=nums.size();
        int result=0;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(!(nums[i]%6))
            {
                result+=nums[i];
                cnt++;
            }
        }
        return cnt==0?0:result/cnt;
    }
};