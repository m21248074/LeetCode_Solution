class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int> um;
        for(int num:nums)
            um[num]++;
        vector<int> result;
        for(auto& [key,value]:um)
        {
            if(value==1)
                result.push_back(key);
        }
        return result;      
    }
};