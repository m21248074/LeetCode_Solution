class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n=nums.size();
        int maxStep=0;
        for(int i=0;i<n;i++)
        {
            if(i>maxStep) return false;
            else if(maxStep>n) return true;
            maxStep=max(maxStep,nums[i]+i);
        }
        return true;
    }
};