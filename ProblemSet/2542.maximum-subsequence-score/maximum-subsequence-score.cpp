class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n=nums1.size();
        vector<pair<int,int>> nums;
        for(int i=0;i<n;i++)
            nums.push_back({nums2[i],nums1[i]});
        sort(nums.rbegin(),nums.rend());
        long long sum=0,result=LONG_LONG_MIN;
        int minValue=INT_MAX;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<n;i++)
        {
            minValue=nums[i].first;
            sum+=nums[i].second;
            pq.push(nums[i].second);
            if(pq.size()>k)
            {
                sum-=pq.top();
                pq.pop();
            }
            if(pq.size()==k)
                result=max(result,sum*minValue);
        }
        return result;
    }
};