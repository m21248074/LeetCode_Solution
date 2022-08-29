class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        unordered_map<int,int> um1,um2;
        for(int num:nums1)
            um1[num]++;
        for(int num:nums2)
            um2[num]++;
        for(auto i=um1.begin();i!=um1.end();i++)
        {
            if(um2[i->first]>0)
                result.push_back(i->first);
        }
        return result;
    }
};