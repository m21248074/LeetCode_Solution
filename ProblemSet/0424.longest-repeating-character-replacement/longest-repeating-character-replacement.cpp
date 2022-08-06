class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();
        if(n<2) return n;
        unordered_map<char,int> m;
        int left=0,right=0,maxCnt=0; //[left,right)
        while(right<n)
        {
            char c=s.at(right);
            m[c]++;
            maxCnt=max(maxCnt,m[c]);
            right++;
            if(right-left>maxCnt+k)
            {
                char d=s.at(left);
                m[d]--;
                left++;
            }
        }
        return right-left;
    }
};