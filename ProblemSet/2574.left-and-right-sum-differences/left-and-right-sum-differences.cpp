class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        vector<int> result;
        int leftSum=0;
        int rightSum=0;
        for(int num:nums)
            rightSum+=num;
        for(int num:nums)
        {
            rightSum-=num;
            result.push_back(abs(rightSum-leftSum));
            leftSum+=num;
        }
        return result;
    }
};