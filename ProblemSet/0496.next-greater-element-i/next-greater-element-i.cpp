class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;
        for(int i=0;i<nums1.size();i++)
        {
            int index;
            for(index=0;index<nums2.size();index++)
                if(nums1[i]==nums2[index]) break;
            int temp=-1;
            for(int j=index+1;j<nums2.size();j++)
            {
                if(nums2[index]<nums2[j])
                {
                    temp=nums2[j];
                    break;
                }
            }
            result.push_back(temp);
        }
        return result;
    }
};