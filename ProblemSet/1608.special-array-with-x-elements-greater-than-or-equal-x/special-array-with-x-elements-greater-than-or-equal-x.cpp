class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int l=0,r=nums.size()-1;
        while(l<=r)
        {
            int m=(l+r)/2;

            int count=0;
            for(int i:nums)
            {
                if(i>=m+1)
                    count++;
            }
            if(count==m+1)
                return m+1;
            else if(count>m+1)
                l=m+1;
            else // count<m-1
                r=m-1;
        }
        return -1;
    }
};