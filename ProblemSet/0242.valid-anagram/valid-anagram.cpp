class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        vector<int> cnt(26,0);
        for(char c:s)
            cnt[c-'a']++;
        for(char c:t)
        {
            cnt[c-'a']--;
            if(cnt[c-'a']<0)
                return false;
        }
        return true;
    }
};