class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        int left=1;
        int right=n;
        while(left<right)
        {
            int mid=(left+right)/2;
            int cnt=0;
            for(int num:nums)
                if(num<=mid) cnt++;
            if(cnt<=mid)
                left=mid+1;
            else
                right=mid;
        }
        return right;
    }
};