class Solution {
public:
    int A(vector<int>& nums) {
        unordered_map<int,int> um;
        int n=nums.size();
        for(int i=0;i<n;i++)
            um[nums[i]]++;
        for(auto i=um.begin();i!=um.end();i++)
        {
            if(i->second>n/2)
                return i->first;
        }
        return 0;
    }
    int B(vector<int>& nums) {
        int candidate=0;
        int cnt=0;
        for(int num:nums)
        {
            if(cnt==0)
            {
                candidate=num;
                cnt++;
            }
            else
                (candidate==num)?cnt++:cnt--;
        }
        return candidate;
    }
    int majorityElement(vector<int>& nums)
    {
        int whichMethod=rand()%2;
        int result=0;
        switch(whichMethod)
        {
            case 0:
                result=A(nums);
                break;
            case 1:
                result=B(nums);
                break;
        }
        return result;
    }
};