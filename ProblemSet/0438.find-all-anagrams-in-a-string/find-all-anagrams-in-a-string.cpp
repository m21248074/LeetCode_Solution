class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        unordered_map<char,int> need,window;
        for(char c:p) need[c]++;
        int left=0,right=0,valid=0;
        while(right<s.size())
        {
            char c=s[right];
            right++;
            if(need.count(c))
            {
                window[c]++;
                if(need[c]==window[c])
                    valid++;
            }
            if(right-left>=p.size())
            {
                if(valid==need.size())
                    result.push_back(left);
                char d=s[left];
                left++;
                if(need.count(d))
                {
                    if(need[d]==window[d])
                        valid--;
                    window[d]--;
                }
            }
        }
        return result;
    }
};