class Solution {
public:
    int A(vector<int>& nums)
    {
        int n=nums.size();
        for(int i=0;i<=n;i++)
        {
            if(find(nums.begin(),nums.end(),i)==nums.end())
                return i;
        }
        return 0;
    }
    int missingNumber(vector<int>& nums) {
        int whichMethod=rand()%1;
        int result=0;
        switch(whichMethod)
        {
            case 0:
                result=A(nums);
                break;
        }
        return result;
    }
};