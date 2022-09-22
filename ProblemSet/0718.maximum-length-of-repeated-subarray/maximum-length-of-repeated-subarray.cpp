class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size(),n=nums2.size();
        int result=0;
        for(int i=0;i<m;i++)
        {
            for(int j=i,k=0;j<m&&k<n;)
            {
                int cnt=0;
                while(j<m&&k<n&&nums1[j++]==nums2[k++]) cnt++;
                result=max(result,cnt);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i,k=0;j<n&&k<m;)
            {
                int cnt=0;
                while(j<m&&k<n&&nums2[j++]==nums1[k++]) cnt++;
                result=max(result,cnt);
            }
        }
        return result;
    }
};