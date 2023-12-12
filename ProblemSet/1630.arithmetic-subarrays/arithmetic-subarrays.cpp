class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int diff;
        vector<int> copy;
        vector<bool> result;
        for(int i=0;i!=l.size();i++)
        {
            copy=nums;
            sort(copy.begin()+l[i],copy.begin()+r[i]+1);
            diff=copy[l[i]+1]-copy[l[i]];
            result.push_back(true);
            for(int j=l[i]+2;j<=r[i];j++)
            {
                if(copy[j]-copy[j-1]!=diff)
                {
                    result.back()=false;
                    break;
                }
            }
        }
        return result;
    }
};