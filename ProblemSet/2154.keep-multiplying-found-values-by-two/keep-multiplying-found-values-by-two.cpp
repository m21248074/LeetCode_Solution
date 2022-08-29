class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        if(find(nums.begin(),nums.end(),original)!=nums.end())
            return (findFinalValue(nums,original*2));
        return original;
    }
};