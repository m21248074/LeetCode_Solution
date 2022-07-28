class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int> m;
        for(int i=0;i<nums.size();i++)
        {
            if(m.count(nums[i]))
                return true;
            m[nums[i]]=1;
        }
        return false;
    }
};