class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> result(2,vector<int>());
        set<int> s1,s2;
        for(int num:nums1)
            s1.insert(num);
        for(int num:nums2)
            s2.insert(num);
        for(int num:s1)
            if(!s2.count(num)) result[0].push_back(num);
        for(int num:s2)
            if(!s1.count(num)) result[1].push_back(num);
        return result;
    }
};