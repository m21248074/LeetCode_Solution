class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int x=m-1,y=n-1,p=m+n-1;
        while(x>=0&&y>=0)
        {
            if(nums1[x]>=nums2[y])
            {
                nums1[p]=nums1[x];
                x--;
            }
            else // nums1[x]<nums2[y]
            {
                nums1[p]=nums2[y];
                y--;
            }
            p--;
        }
        if(y>=0)
        {
            for(int i=p;i>=0;i--,y--)
                nums1[i]=nums2[y];
        }
    }
};