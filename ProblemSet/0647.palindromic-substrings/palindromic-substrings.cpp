class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length();
        int result=0;
        function<void(int,int)> helper=[&](int i,int j){
            while(i>=0&&j<n&&s[i]==s[j])
            {
                i--;
                j++;
                result++;
            }
        };
        for(int i=0;i<n;i++)
        {
            helper(i,i);
            helper(i,i+1);
        }
        return result;
    }
};