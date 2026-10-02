class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int preIdx=-1;
        for(int i=0;i<nums.size();i++)
        {
            int num=nums[i];
            if(num==1)
            {
                if(preIdx!=-1 && i-preIdx-1<k)
                    return false;
                preIdx=i;
            }
        }
        return true;
    }
};