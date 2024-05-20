class Solution {
public:
    int minimumLength(string s) {
        int n=s.length();
        if(n==1) return n;
        int left=0;
        int right=n-1;
        while(left<right&&s[left]==s[right])
        {
            char c=s[left];
            while(left<=right&&s[left]==c)
                left++;
            while(left<=right&&s[right]==c)
                right--;
        }
        return left>right?0:right-left+1;
    }
};