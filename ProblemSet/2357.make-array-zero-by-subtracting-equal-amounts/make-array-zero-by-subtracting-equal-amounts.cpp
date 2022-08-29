class Solution {
public:
    void helper(int &cnt,vector<int>& nums)
    {
        int choose=INT_MAX;
        for(int num:nums)
            if(num>0&&num<=choose) choose=num;
        if(choose==INT_MAX) return;
        cnt++;
        for(int &num:nums)
            if(num>0) num-=choose;
        helper(cnt,nums);
    }
    int minimumOperations(vector<int>& nums) {
        int cnt=0;
        helper(cnt,nums);
        return cnt;
    }
};