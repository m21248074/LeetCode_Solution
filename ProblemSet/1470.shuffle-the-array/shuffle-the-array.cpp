class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int l=0,r=n;
        vector<int> result;
        for(int i=0;i<n;i++)
        {
            result.push_back(nums[l]);
            result.push_back(nums[r]);
            l++,r++;
        }
        return result;
    }
};