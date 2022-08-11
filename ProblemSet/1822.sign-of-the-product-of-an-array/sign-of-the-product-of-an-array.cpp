class Solution {
public:
    int signFunc(double x)
    {
        if(x>0) return 1;
        else if(x<0) return -1;
        return 0;
    }
    int arraySign(vector<int>& nums) {
        double product=1;
        for(int num:nums)
        {
            product*=num;
        }
        return signFunc(product);
    }
};