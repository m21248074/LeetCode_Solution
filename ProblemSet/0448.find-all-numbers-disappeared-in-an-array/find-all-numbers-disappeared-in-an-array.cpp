class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n=nums.size();
        vector<int> result;
        set<int> s;
        for(int i=1;i<=n;i++)
            s.insert(i);
        for(int num:nums)
            s.erase(num);
        for(int i:s)
            result.push_back(i);
        return result;
    }
};