class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n=nums.size();
        int m=queries.size();
        vector<int> result;
        sort(nums.begin(),nums.end());
        vector<int> prefix;
        prefix.push_back(nums[0]);
        for(int i=1;i<n;i++)
            prefix.push_back(prefix[i-1]+nums[i]);
        for(int query:queries)
        {
            int tempResult=0;
            for(int p:prefix)
            {
                if(p<=query)
                    tempResult++;
                else
                    break;
            }
            result.push_back(tempResult);
        }
        return result;
    }
};