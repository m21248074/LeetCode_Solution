class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        unordered_set<string> us;
        for(auto num:nums)
            us.insert(num);
        int count=pow(2,n);
        for(int i=0;i<count;i++)
        {
            int t=i;
            string s="";
            for(int j=0;j<n;j++)
            {
                if((t&1)==1)
                    s+="1";
                else
                    s+="0";
                t>>=1;
            }
            if(!us.count(s))
                return s;
        }
        return nullptr;
    }
};