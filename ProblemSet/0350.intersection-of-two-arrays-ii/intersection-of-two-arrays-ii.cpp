class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        vector<int> longer=(nums1.size()>nums2.size())?nums1:nums2;
        vector<int> shorter=(nums1.size()>nums2.size())?nums2:nums1;
        for(int i=0;i<shorter.size();i++)
        {
            auto it=find(longer.begin(),longer.end(),shorter[i]);
            if(it!=longer.end()) // find
            {
                longer.erase(it);
                result.push_back(shorter[i]);
            }
        }
        return result;
    }
};