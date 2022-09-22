class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> result;
        int sum=0;
        for(int num:nums) if(!(num%2)) sum+=num;
        for(auto query:queries)
        {
            int value=query[0];
            int index=query[1];
            if(nums[index]%2)
            {
                if(!((nums[index]+value)%2))
                    sum+=nums[index]+value;
            }
            else
            {
                if(!((nums[index]+value)%2))
                    sum+=value;
                else
                    sum-=nums[index];
            }
            result.push_back(sum);
            nums[index]+=value;
        }
        return result;
    }
};