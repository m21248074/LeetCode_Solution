class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> result;
        map<int,int> m;
        for(int num:nums)
            m[num]++;
        for(int num:nums)
        {
            int sum=0;
            for(auto e:m)
            {
                if(e.first<num)
                    sum+=e.second;
                else
                    break;
            }
            result.push_back(sum);
        }
        return result;
    }
};