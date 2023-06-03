class Solution {
public:
    bool isVowel(char c)
    {
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
    }
    int maxVowels(string s, int k) {
        int left=0,right=0;
        int n=s.length();
        int result=0;
        int window=0;
        while(right<n)
        {
            if(isVowel(s[right++]))
                window++;
            while(left<right&&right-left>k)
            {
                if(isVowel(s[left++]))
                    window--;
            }
            result=max(result,window);
        }
        return result;
    }
};