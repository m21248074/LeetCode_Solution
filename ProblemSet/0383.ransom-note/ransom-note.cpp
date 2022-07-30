class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> cnt(26,0);
        for(char c:magazine)
            cnt[c-'a']++;
        for(char c:ransomNote)
        {
            cnt[c-'a']--;
            if(cnt[c-'a']<0) return false;
        }
        return true;
    }
};