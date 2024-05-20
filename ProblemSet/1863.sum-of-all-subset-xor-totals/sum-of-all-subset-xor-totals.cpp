class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n=nums.size();
        vector<int> s;
        function<int(int,int)> total=[&](int index,int sum)
        {
            int temp=0;
            for(int i:s)
                temp^=i;
            sum+=temp;
            for(int i=index;i<n;i++)
            {
                s.push_back(nums[i]);
                sum=total(i+1,sum);
                s.pop_back();
            }
            return sum;
        };
        return total(0,0);
    }
};