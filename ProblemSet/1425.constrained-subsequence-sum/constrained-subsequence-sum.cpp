class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        deque<int> dq;
        int result=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            nums[i]=max((dq.size()==0?0:dq.front())+nums[i],nums[i]);
            result=max(result,nums[i]);
            while(!dq.empty()&&nums[i]>dq.back())
                dq.pop_back();
            dq.push_back(nums[i]);
            if(i>=k&&nums[i-k]==dq.front())
                dq.pop_front();
        }
        return result;
    }
};