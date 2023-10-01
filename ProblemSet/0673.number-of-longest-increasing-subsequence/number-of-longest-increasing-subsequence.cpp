class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int result=0;
        int temp=0;
        int n=nums.size();
        vector<int> len(n,1);
        vector<int> cnt(n,1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]<=nums[j]) continue;
                if(len[i]==len[j]+1) cnt[i]+=cnt[j];
                else if(len[i]<len[j]+1)
                {
                    len[i]=len[j]+1;
                    cnt[i]=cnt[j];
                }
            }
            if(temp==len[i]) result+=cnt[i];
            else if(temp<len[i])
            {
                temp=len[i];
                result=cnt[i];
            }
        }
        return result;
    }
};