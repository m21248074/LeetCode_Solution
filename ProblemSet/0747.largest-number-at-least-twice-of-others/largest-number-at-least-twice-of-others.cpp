class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int n=nums.size();
        int result=-1;
        vector<int> temp(nums);
        sort(temp.begin(),temp.end());
        int max=*temp.rbegin();
        for(int i=0;i<n;i++)
        {
            if(nums[i]==max)
                result=i;
            else if(nums[i]*2>max)
            {
                result=-1;
                break;
            }
        }
        return result;
    }
};