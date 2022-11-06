class Solution {
public:
    int maxLength(vector<string>& arr) {
        int result=0;
        vector<bitset<26>> dp;
        dp.push_back(bitset<26>());
        for(string s:arr)
        {
            bitset<26> bs;
            for(char c:s)
                bs.set(c-'a');
            int n=bs.count();
            if(n<s.length()) continue;
            for(int i=dp.size()-1;i>=0;i--)
            {
                bitset t=dp[i];
                if((t&bs).any()) continue;
                dp.push_back(t|bs);
                result=max(result,int(t.count())+n);
            }
        }
        return result;
    }
};