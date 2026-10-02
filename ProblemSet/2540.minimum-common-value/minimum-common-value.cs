public class Solution {
    public int GetCommon(int[] nums1, int[] nums2) {
        int p1=0;
        int p2=0;
        int n1=nums1.Length;
        int n2=nums2.Length;
        while(p1<n1&&p2<n2)
        {
            if(nums1[p1]==nums2[p2])
                return nums1[p1];
            else if(nums1[p1]<nums2[p2])
                p1++;
            else
                p2++;
        }
        return -1;
    }
}