class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> temp;
        int n=s.length();
        function<bool(int,int)> isPalindrome=[&](int start,int end){
            while(start<end)
            {
                if(s[start]!=s[end])
                    return false;
                start++;
                end--;
            }
            return true;
        };
        function<void(int)> helper=[&](int start){
            if(start==n)
            {
                result.push_back(temp);
                return;
            }
            for(int i=start;i<n;i++)
            {
                if(!isPalindrome(start,i))
                    continue;
                temp.push_back(s.substr(start,i-start+1));
                helper(i+1);
                temp.pop_back();
            }
        };
        helper(0);
        return result;
    }
};