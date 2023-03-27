class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long result=0;
        map<int,int> m;
        int lens=0;
        for(int num:nums)
        {
            if(!num)
                lens++;
            else
            {
                if(lens)
                {
                    m[lens]++;
                    lens=0;
                }
            }
        }
        if(lens)
        {
            m[lens]++;
            lens=0;
        }
        function<long long(long long)> helper=[&](long long n)-> long{
            return n*(n+1)/2;
        };
        for(auto i:m)
        {
            //cout << i.first << ' ' << i.second << endl;
            result+=helper(i.first)*i.second;
        }
        return result;
    }
};