class Solution {
public:
    int nSumClosest(vector<int>& nums,int n,int start,int target,int &diff)
    {
        int size=nums.size();
        if(n==2)
        {
            int left=start;
            int right=size-1;
            int result=INT_MAX;
            while(left<right)
            {
                int sum=nums[left]+nums[right];
                if(abs(target-sum)<diff)
                {
                    result=sum;
                    diff=abs(target-sum);
                }
                if(sum<target)
                    left++;
                else if(sum>target)
                    right--;
                else // sum==target
                    return target;
            }
            return result;
        }
        else // n>2
        {
            int temp=diff;
            int result=INT_MAX;
            for(int i=start;i<size;i++)
            {
                int closest=nSumClosest(nums,n-1,i+1,target-nums[i],diff);
                if(diff<temp)
                {
                    result=closest+nums[i];
                    temp=diff;
                }
            }
            return result;
        }
    }
    int threeSumClosest(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==3) return accumulate(nums.begin(),nums.end(),0);
        int diff=INT_MAX;
        sort(nums.begin(),nums.end());
        return nSumClosest(nums,3,0,target,diff);
    }
};