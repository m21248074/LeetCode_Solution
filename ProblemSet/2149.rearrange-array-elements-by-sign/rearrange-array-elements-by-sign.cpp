class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> result(n);
        int a=0;
        int b=0;
        int i=0;
        while(i<n)
        {
            while(nums[a]<0)
                a++;
            result[i]=nums[a];
            i++;
            a++;
            while(nums[b]>0)
                b++;
            result[i]=nums[b];
            i++;
            b++;
        }
        return result;
    }
};