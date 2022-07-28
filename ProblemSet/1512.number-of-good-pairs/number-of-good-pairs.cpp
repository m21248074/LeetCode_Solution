class Solution {
public:
    int sigma(int x)
    {
        if(x==1) return 1;
        return x+sigma(x-1);
    }
    int numIdenticalPairs(vector<int>& nums) {
        map<int,int> m;
        int result=0;
        for(int i=0;i<nums.size();i++)
            m[nums[i]]++;
        for(auto i=m.begin();i!=m.end();i++)
        {
            if(i->second>1)
                result+=sigma(i->second-1);
        }
        return result;
    }
};