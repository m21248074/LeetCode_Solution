class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int result=0;
        for(int num:nums)
        {
            if(num%3!=0)
                result+=min(num%3,3-(num%3));
        }
        return result;
    }
};