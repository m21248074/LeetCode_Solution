class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        for(int num:nums2)
            nums1.push_back(num);
        sort(nums1.begin(),nums1.end());
        int n=nums1.size();
        if(n%2)
            return nums1[n/2];
        else
            return ((double)nums1[n/2-1]+nums1[n/2])/2;
    }
};