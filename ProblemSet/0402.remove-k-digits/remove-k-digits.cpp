class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.length();
        string result;
        int keep=n-k;
        for(char c:num)
        {
            while(k&&result.length()&&result.back()>c)
            {
                result.pop_back();
                k--;
            }
            result.push_back(c);
        }
        result.resize(keep);
        while(!result.empty()&&result[0]=='0')
            result.erase(result.begin());
        return result.empty()?"0":result;
    }
};