class Solution {
public:
    int minElement(vector<int>& nums) {
        int result=INT_MAX;
        for(int& num:nums)
        {
            num=digitSum(num);
            result=min(result,num);
        }
        return result;
    }
    int digitSum(int num)
    {
        int result=0;
        while(num!=0)
        {
            result+=num%10;
            num/=10;
        }
        return result;
    }
};