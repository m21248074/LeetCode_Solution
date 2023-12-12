class Solution {
private:
    int rev(int num)
    {
        int result=0;
        while(num!=0)
        {
            result=result*10+num%10;
            num/=10;
        }
        return result;
    }
public:
    int countNicePairs(vector<int>& nums) {
        int n=nums.size();
        int mod=1e9+7;
        int result=0;
        unordered_map<int,int> um;
        for(int num:nums)
        {
            int t=rev(num);
            if(um.count(num-t))
            {
                result+=um[num-t];
                result%=mod;
            }
            um[num-t]++;
        }
        return result;
    }
};