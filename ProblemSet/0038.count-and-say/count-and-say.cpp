class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";
        string pre=countAndSay(n-1);
        string result;
        int count=1;
        for(int i=1;i<pre.length();i++)
        {
            if(pre[i-1]==pre[i]) count++;
            else // pre[i-1]!=pre[i]
            {
                result.push_back(count+'0');
                result.push_back(pre[i-1]);
                count=1;
            }
        }
        result.push_back(count+'0');
        result.push_back(pre[pre.length()-1]);
        return result;
    }
};