class Solution {
public:
    int trap(vector<int>& height) {
        int result;
        int left=0,right=height.size()-1;
        int l_max=0,r_max=0;
        while(left<right)
        {
            l_max=max(l_max,height[left]);
            r_max=max(r_max,height[right]);
            if(l_max<r_max)
            {
                result+=l_max-height[left];
                left++;
            }
            else
            {
                result+=r_max-height[right];
                right--;
            }
        }
        return result;
    }
};