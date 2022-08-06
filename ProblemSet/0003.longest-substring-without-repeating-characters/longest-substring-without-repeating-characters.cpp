class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> m;
        int left=0,right=0,len=0;
        while(right<s.size())
        {
            char c=s[right];
            right++;
            m[c]++;
            while(m[c]>1)
            {
                char d=s[left];
                left++;
                m[d]--;
            }
            len=max(len,right-left);
        }
        return len;
    }
};